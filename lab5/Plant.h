/*
 * Plant.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef PLANT_H_
#define PLANT_H_
#include "Organism.h"

class Plant : public Organism{
public:
	virtual void calculatePrice() = 0;
	virtual ~Plant();
};


#endif /* PLANT_H_ */
