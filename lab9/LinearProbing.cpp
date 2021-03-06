/*
 * LinearProbing.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Budi Ryan
 */

#include "LinearProbing.h"

LinearProbing :: LinearProbing(int a):OpenAddressing(a){}


int LinearProbing :: getIndexByhashing(int keyValue){
	int initValue = keyValue % bucketSize;
	int count = 0;
	while(data[initValue] != EMPTY){
		initValue = (initValue + 1) % bucketSize;
		count++;
		if(count == bucketSize){
			return -1;
		}
	}
	return initValue;
}


