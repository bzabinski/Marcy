/*
 * REST.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <stdlib.h>
#include <string.h>

#include <jansson.h>
#include <curl/curl.h>

#include "REST.h"

#define BUFFER_SIZE (256 * 1024)

#define CYPHER_URL	"http://localhost:7474/db/data/cypher"
#define URL_SIZE	256

int testServer()
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
	size_t i;
	char *text;
	char url[URL_SIZE];

	snprintf(url, URL_SIZE, CYPHER_URL);

	puts(url);

	text = request(url);
	
	puts(text);
	free(text);

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

static char *request(const char *url)
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

	curl_easy_setopt(curl, CURLOPT_URL, url);

	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

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

	puts("All done?");
	return data;
}
