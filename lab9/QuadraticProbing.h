/*
 * QuadraticProbing.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */

#ifndef QUADRATICPROBING_H_
#define QUADRATICPROBING_H_
#include "OpenAddressing.h"

class QuadraticProbing: public OpenAddressing {
public:
	QuadraticProbing(int);
	virtual int getIndexByhashing(int keyValue); // To be implemented in sub-classes: if there is no empty entries
												 // or any other errors exist, please return -1
};

#endif /* QUADRATICPROBING_H_ */
