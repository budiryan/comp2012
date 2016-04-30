/*
 * OpenAddressing.h
 *
 *  Created on: 27 Apr, 2016
 *      Author: wangyong
 */

#ifndef OPENADDRESSING_H_
#define OPENADDRESSING_H_
#include "Hashing.h"

class OpenAddressing: public Hashing{
public:
	OpenAddressing(int newSize);
	virtual ~OpenAddressing();

	virtual void reset(int newSize);
	virtual void print();
	virtual bool insert(int newValue);

	virtual int getIndexByhashing(int keyValue) = 0;// To be implemented in sub-classes: if there is no empty entries
													// or any other errors exist, please return -1

protected:
	int *data;										// hash table (the data will be stored here)
	int occupiedSize;  								// The of hash table entries currently occupied
};

#endif /* OPENADDRESSING_H_ */
