/*
 * Interface.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <jansson.h>

#include "JSON.h"

int parse(char *text)
{
	size_t i;

	json_t *root;
	json_error_t error;
	
	puts(text);

	root = json_loads(text, JSON_DECODE_ANY, &error);
	free(text);

	if(!root)
	{
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
		return 1;
	}

	if(!json_is_array(root))
	{
		fprintf(stderr, "error: root is not an array\n");
		json_decref(root);
		return 1;
	}
	puts("it is good");
	json_decref(root);
	return 0;
}

char* sample(void)
{
	const struct json_t *temp = json_pack("{s:s, s:{s:s}}", "query", "CREATE (n:Person { name : {name} }) RETURN n", "params", "name", "Andres");
	return json_dumps(temp, JSON_ENCODE_ANY);
}
