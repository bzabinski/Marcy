/*
 * Cells.h
 *
 *  Created on: Jun 6, 2014
 *      Author: beth
 */

#ifndef CELL_H_
#define CELL_H_

#include "Neighborhoods.h"

struct Cells
{
	struct Neighborhoods neighborhood;
	unsigned long name;
	float velocity;
	float pressure;
};

#endif /* CELL_H_ */
