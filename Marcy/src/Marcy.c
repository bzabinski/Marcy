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

#include "include/Config.h"
#include "include/Torus.h"
#include "include/Interface.h"

int main(void)
{
	//createTorus(size);
	if(initialize(size) == 0)
		puts("Pass"); 
	else
		puts("Fail");
	return 0;
}
