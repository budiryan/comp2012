/*
 * LinearProbing.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_
#include "OpenAddressing.h"

class LinearProbing: public OpenAddressing {

public:
	LinearProbing(int a);

	virtual int getIndexByhashing(int keyValue); // To be implemented in sub-classes: if there is no empty entries
												 // or any other errors exist, please return -1

};

#endif /* LINEARPROBING_H_ */
