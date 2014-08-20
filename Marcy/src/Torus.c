/*
 * Torus.c
 *
 *  Created on: Jun 6, 2014
 *      Author: beth
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Torus.h"
#include "Interface.h"
#include "Cells.h"
#include "MyMath.h"

int createTorus(int size)
{
	unsigned long length = (1 << size);
	unsigned long uniqueCells = length * length;

	unsigned long i = 0;
	
    makeNodes(uniqueCells);

	//Now set the pointers to the correct cell
	for(i = 0; i < uniqueCells; i++)
	{
		/*			Size: 1, Length: 2, Unique: 4
		 *
		 * 			0
		 * 				2
		 * 			1		0
		 * 				3		2
		 * 			0		1		0
		 * 				2		3		2
		 * 			1		0		1		0
		 * 				3		2		3		2
		 * 			0		1		0		1
		 *
		 * 			Size: 2, Length: 4, Unique: 16
		 *
		 * 			0
		 * 				4
		 * 			1		8
		 * 				5		C
		 *			2		9		0
		 * 				6		D		4
		 *			3		A		1		8
		 *				7		E		5		C
		 *			0		B		2		9		0
		 *				4		F		6		D		4
		 *			1		8		3		A		1		8
		 *				5		C		7		E		5		C
		 *			2		9		0		B		2		9		0
		 *				6		D		4		F		6		D		4
		 *			3		A		1		8		3		A		1		8
		 *
		 *
		 */
		unsigned long adjustVal = floor((double)i / (double)length) * length;
		makeRel(i, trueMod((i - 1), length) + adjustVal, "midForwardCenter"); //= allTheCells[trueMod((i - 1), length) + adjustVal];
		makeRel(i, trueMod(trueMod((i - 1), length) + adjustVal + length, uniqueCells), "midForwardRight"); //= allTheCells[trueMod(trueMod((i - 1), length) + adjustVal + length, uniqueCells)];	//Goes forward-center then back-right
		makeRel(i, trueMod(i + length, uniqueCells), "midBackRight"); //= allTheCells[trueMod(i + length, uniqueCells)];
		makeRel(i, trueMod(i + 1, length) + adjustVal, "midBackCenter"); //= allTheCells[trueMod((i + 1),length) + adjustVal];
		makeRel(i, trueMod(trueMod(i + 1, length) + adjustVal - length, uniqueCells), "midBackLeft"); //= allTheCells[trueMod(trueMod((i + 1),length) + adjustVal - length, uniqueCells)];			//Goes back-center then forward-left
		makeRel(i, trueMod(i - length, uniqueCells), "midForwardLeft"); //= allTheCells[trueMod(i - length, uniqueCells)];
	}
	//int a = 0;
	//printf("%d\n",allTheCells[a]->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midForwardCenter->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midForwardRight->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midBackRight->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midBackCenter->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midBackLeft->name);
	//printf("%d\n",allTheCells[a]->neighborhood.midForwardLeft->name);

	return 0;
}
