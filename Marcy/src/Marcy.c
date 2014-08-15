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
	if(initialize() == 0)
    {
		puts("Pass");
    }
	else
    {
		puts("Fail");
        return 1;
    }

   if(createTorus(size) == 0)
   {
       puts("Torus created successfully");
   }
   else
   {
       puts("Torus creation failed");
       return 1;
   }

	return 0;
}
