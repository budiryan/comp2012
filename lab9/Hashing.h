/*
Assumptions:

    * Values are non-negative integers
	* -1 is reserved as EMPTY
	* No need to implement search and deletion
 */

#ifndef HASHING_H_
#define HASHING_H_

//base class of all the hashing method
class Hashing{
public:
	static const int EMPTY = -1;  						//-1 is reserved as EMPTY

	Hashing(int size):bucketSize(size){ }   			//constructor
	virtual ~Hashing(){ }								//destructor

	//Pure virtual functions that will be implemented in the sub-classes
	virtual void reset(int newSize) = 0;	   			//reset the hash table and initialize every element
	virtual void print() = 0; 				   			//print all the key values of the hash table
	virtual bool insert(int newValue) = 0;	   			//insert a given value to the hash table

	virtual int getIndexByhashing(int keyValue) = 0;	//get the location by using a hashing method

protected:
	int bucketSize;										//size of the hash table
};

#endif /* HASHING_H_ */
