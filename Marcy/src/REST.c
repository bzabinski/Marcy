/*
 * REST.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

#include "REST.h"
#include "JSON.h"

#define BUFFER_SIZE (1024 * 1024)

#define CYPHER_URL	"http://localhost:7474/db/data/cypher"
#define URL_SIZE	256

#define NO_RETURN 0
#define RETURN 1

int testServer(void)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, CYPHER_URL);

		res = curl_easy_perform(curl);

		if(res != CURLE_OK)
		{
			puts("CURL not ok");
			fprintf(stderr, "curl_easy_perform() failed %s\n", curl_easy_strerror(res));
			return 1;
		}
		curl_easy_cleanup(curl);
		puts("Good job");
	}
	else
	{
		puts("CURL init failed");
		printf("init failed\n");
		return 2;
	}
	return 0;
}

int createNodes(int nodes)
{
	char *text;
	char url[URL_SIZE];

	snprintf(url, URL_SIZE, CYPHER_URL);

	puts(url);

	//Truncates the current DB
	puts(dropall());
	request(url, dropall(), NO_RETURN);

	//Loops and adds each node to the DB
	for(int i = 0; i < nodes; i++)
	{
		puts("About to create node");
		request(url, formNode(i), NO_RETURN);
		puts("About to free text");
	}
	puts("Out of loop");
	//Create the relationships between the nodes

	//if(!text)
	//	puts("Text didn't return anything");

	//parse(text);

	return 0;
}

//Internal stuff


static int newline_offset(const char *text)
{
	const char *newline = strchr(text, '\n');
	if(!newline)
		return strlen(text);
	else
		return (int)(newline - text);
}

struct write_result
{
	char *data;
	int pos;
};

static size_t write_response(void *ptr, size_t size, size_t nmemb, void *stream)
{
	struct write_result *result = (struct write_result *)stream;

	if(result->pos + size * nmemb >= BUFFER_SIZE - 1)
	{
		fprintf(stderr, "error: too small buffer\n");
		return 0;
	}

	memcpy(result->data + result->pos, ptr, size * nmemb);
	result->pos += size * nmemb;

	return size * nmemb;
}

static char *request(const char *url, char *postdata, int datareturn)
{
	CURL *curl = NULL;
	CURLcode status;
	struct curl_slist *headers = NULL;
	char *data = NULL;
	long code;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	
	//skip error checking
	
	data = malloc(BUFFER_SIZE);

	struct write_result write_result = {
		.data = data,
		.pos = 0
	};

	puts("About to set stuff");

	//char *postdata = sample();
	//char *postdata = dropall();
	//char *postdata = '{"query" : "MATCH (x {name: {startName}})-[r]-(friend) WHERE friend.name = {name} RETURN TYPE(r)", "params" : {"startName" : "I", "name" : "you"}}';
	//puts(*postdata);
	headers = curl_slist_append(headers, "Accept: application/json; charset=UTF-8");
	headers = curl_slist_append(headers, "Content-Type: application/json");

	curl_easy_setopt(curl, CURLOPT_URL, url);

	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &write_result);

	puts("About to perform");

	status = curl_easy_perform(curl);

	puts("I performed it");

	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
	
	curl_easy_cleanup(curl);
	curl_slist_free_all(headers);
	curl_global_cleanup();
	
	data[write_result.pos] = '\0';
	return data;
}
