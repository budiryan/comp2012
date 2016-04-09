/*
 * Cat.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

class Cat: public Animal{
public:
	Cat(int type);
	void calculatePrice();
private:
	int type;
};



#endif /* CAT_H_ */
