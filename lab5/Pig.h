/*
 * Pig.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef PIG_H_
#define PIG_H_

#include "Animal.h"

class Pig : public Animal{
public:
	Pig(float w, float ppw);
	void calculatePrice();

private:
	float pricePerWeight;
	float weight;
};


#endif /* PIG_H_ */
