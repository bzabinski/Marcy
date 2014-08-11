/*
 * Interface.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include <stdio.h>

#include "Interface.h"
#include "REST.h"

int initialize(int nodes)
{
	if(testServer() != 0)
	{
		return 1;
	}
	puts("Server tested");
	createNodes(nodes);
	puts("Nodes created?");
	return 0;
}
