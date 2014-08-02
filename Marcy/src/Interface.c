/*
 * Interface.c
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#include "Interface.h"
#include "REST.h"

int initialize(int nodes)
{
	if(testServer() != 0)
	{
		return 1;
	}
	createNodes(nodes);
	return 0;
}
