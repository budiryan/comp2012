/*
 * Carrot.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef CARROT_H_
#define CARROT_H_

#include "Plant.h"

class Carrot : public Plant{
public:
	Carrot(float ppw, float w);
	void calculatePrice();

private:
	float pricePerWeight;
	float weight;
};



#endif /* CARROT_H_ */
