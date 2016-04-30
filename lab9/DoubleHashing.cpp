/*
 * DoubleHashing.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */

#include "DoubleHashing.h"

DoubleHashing::DoubleHashing(int a) :
		OpenAddressing(a) {
}

int DoubleHashing::getIndexByhashing(int keyValue) {
	int initValue = keyValue % bucketSize;
	int secondHash = 7 - (keyValue % 7);
	int resultValue = initValue;
	int i = 1;
	while (data[resultValue] != EMPTY) {
		resultValue = (initValue + (i * secondHash)) % bucketSize;
		i++;
	}
	return resultValue;

}
