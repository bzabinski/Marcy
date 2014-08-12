/*
 * Interface.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <stdio.h>

#include "Interface.h"
#include "REST.h"

int initialize()
{
	if(testServer() != 0)
	{
		return 1;
	}
	puts("Server tested");
	return 0;
}

int makeNodes(int nodes)
{
	for(int i = 0; i < nodes; i++)
	{
		if(createNode(i) != 0)
		{
			return 1;
		}
	}

	return 0;
}

int makeRel(int nodeFrom, int nodeTo, char* name)
{
	if(createRelationship(nodeFrom, nodeTo, name) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
