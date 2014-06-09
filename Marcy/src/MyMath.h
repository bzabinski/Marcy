/*
 * myMath.h
 *
 *  Created on: Jun 8, 2014
 *      Author: beth
 */

#ifndef MYMATH_H_
#define MYMATH_H_

int trueMod(unsigned long long a, unsigned long long b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

#endif /* MYMATH_H_ */
