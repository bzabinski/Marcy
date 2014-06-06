/*
 * Neighborhoods.h
 *
 *  Created on: Jun 6, 2014
 *      Author: beth
 */

#ifndef NEIGHBORHOODS_H_
#define NEIGHBORHOODS_H_

struct Neighborhoods
{
	struct Cells *topForwardCenter;
	struct Cells *topBackLeft;
	struct Cells *topBackRight;

	struct Cells *midForwardCenter;
	struct Cells *midForwardLeft;
	struct Cells *midForwardRight;
	struct Cells *midBackCenter;
	struct Cells *midBackLeft;
	struct Cells *midBackRight;

	struct Cells *botForwardCenter;
	struct Cells *botBackLeft;
	struct Cells *botBackRight;
};

#endif /* NEIGHBORHOODS_H_ */
