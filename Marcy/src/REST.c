/*
 * REST.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <curl/curl.h>

#include "JSON.h"
#include "REST.h"

#define CYPHER_URL	"http://localhost:7474/db/data/cypher"

int something()
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
