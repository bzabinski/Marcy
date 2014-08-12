/*
 * Interface.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <jansson.h>
#include <strings.h>

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

char* dropall(void)
{
	const struct json_t *temp = json_pack("{s:s}", "query", "MATCH (n) OPTIONAL MATCH (n)-[r]-() DELETE n,r");
	return json_dumps(temp, JSON_COMPACT);
}

char* formNode(int nodeNum)
{
	puts("Forming Node");
	const struct json_t *temp = json_pack("{s:s, s:{s:i}}", "query", "CREATE (a { name : {name} })", "params", "name", nodeNum);
	return json_dumps(temp, JSON_COMPACT);
}

char* formRelationship(int startNode, int endNode, char* name)
{
	puts("Forming relationship");
	//char* matchMerge = malloc(1024 * 256);
	//sprintf(matchMerge, "MATCH (start: {start},(end: {end}) MERGE (start)-[:%s]->(end)", name);
	//puts(matchMerge);
	const struct json_t *temp = json_pack("{s:s, s:{s:i,s:i}}", "query", "MATCH (start { name: {start} }),(end { name: {end} }) MERGE (start)-[:Forward]->(end)", "params", "start", startNode, "end", endNode);
	//free(matchMerge);
	return json_dumps(temp, JSON_COMPACT);
}
