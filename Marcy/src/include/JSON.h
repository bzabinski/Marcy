/*
 * JSON.h
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#ifndef JSON_H_
#define JSON_H_

int parse(char *text);

char *dropall(void);

char *formNode(int nodeNum);

char *formRelationship(int startNode, int endNode, char* name);

#endif /* JSON_H_ */
