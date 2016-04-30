
#ifndef SEPARATECHAINING_H_
#define SEPARATECHAINING_H_

#include "Hashing.h"

typedef struct ChainingElem{
	int value;
	struct ChainingElem *next; 					//pointer that points to the next element of the linked list
} ChainingElem;


class SeparateChaining: public Hashing{
public:
	SeparateChaining(int size);
	~SeparateChaining();

	virtual void reset(int newSize);
	virtual void print();
	virtual int getIndexByhashing(int keyValue); //TODO: Implement the hash function
	virtual bool insert(int newValue);			 //TODO: Implement the function that will insert the new value into the hash table

	bool clearData();							 //TODO: Implement the function that clear the hash table

private:
	ChainingElem *data;							 //Hash Table (linked list will be stored here)
};

#endif /* SEPARATECHAINING_H_ */
