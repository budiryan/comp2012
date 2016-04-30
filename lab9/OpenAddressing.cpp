
#include "OpenAddressing.h"
#include <iostream>
using namespace std;

OpenAddressing::OpenAddressing(int newSize):Hashing(newSize), data(NULL), occupiedSize(0){
	reset(newSize);
}


OpenAddressing::~OpenAddressing(){
	if(data != NULL){
		delete []data;
		data = NULL;
	}
}

void OpenAddressing::reset(int newSize){
	if ( data != NULL ) {
		delete [] data ;
		data = NULL;
	}
	occupiedSize = 0;
	bucketSize = newSize;
	data = new int[bucketSize];
	for (int i=0; i<bucketSize; i++)
		data[i] = EMPTY;
}

void OpenAddressing::print()  {
	cout << "[" ;
	for (int i=0; i<bucketSize; i++) {
		if ( data[i] == EMPTY ) {
			cout << "_" ;
		}
		else {
			cout << data[i] ;
		}
		if ( i<bucketSize-1)
			cout << ", " ;
	}
	cout << "]" << endl ;
}

bool OpenAddressing::insert(int value) {
	if ( occupiedSize < bucketSize ) {
		int itemIndex = getIndexByhashing(value);
		if(itemIndex != -1){ //NOTE: -1 means that there are no empty entries in hash table or some other errors exist
			data[itemIndex] = value;
			occupiedSize++;
			return true;
		}
	}

	cout<<"the hash table is full!!!"<<endl;
	return false;
}


