/*
 * Rose.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef ROSE_H_
#define ROSE_H_

#include "Plant.h"

class Rose : public Plant{
public:
	Rose(int roseColor);
	void calculatePrice();

private:
	int color;
};



#endif /* ROSE_H_ */
