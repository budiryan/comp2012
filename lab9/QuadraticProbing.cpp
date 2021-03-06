/*
 * QuadraticProbing.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */
#include "QuadraticProbing.h"

QuadraticProbing::QuadraticProbing(int a) :
		OpenAddressing(a) {
}

int QuadraticProbing::getIndexByhashing(int keyValue) {
	int initValue = keyValue % bucketSize;
	int resultValue = initValue;
	int i = 1;
	while (data[resultValue] != EMPTY) {
		resultValue = (initValue + (i * i)) % bucketSize;
		i++;
	}
	return resultValue;
}

