/*
 * Animal.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include "Organism.h"

class Animal : public Organism{
public:
	virtual void calculatePrice() = 0;
	virtual ~Animal();
};


#endif /* ANIMAL_H_ */
