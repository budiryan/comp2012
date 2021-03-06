/*
 * DoubleHashing.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */

#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_

#include "OpenAddressing.h"

class DoubleHashing: public OpenAddressing {
public:
	DoubleHashing(int);

	virtual int getIndexByhashing(int keyValue);

};

#endif /* DOUBLEHASHING_H_ */
