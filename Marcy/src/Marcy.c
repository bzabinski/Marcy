/*
 ============================================================================
 Name        : Marcy.c
 Author      : Beth Zabinski
 Version     :
 Copyright   : Mine!
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Config.h"
#include "Torus.h"
#include "Neo4jDriver/Interface.h"

int main(void)
{
	createTorus(size);
	test();
	puts("Test"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
