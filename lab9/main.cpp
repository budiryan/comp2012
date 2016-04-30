
#include "Hashing.h"
#include "SeparateChaining.h" 	//TODO: Implement three functions of function OpenAddressing:getIndexByhashing, insert, clearData
#include "LinearProbing.h"		//TODO: Implement the class LinearProbing
#include "QuadraticProbing.h"   // TODO: Implement the class QuadraticProbing
#include "DoubleHashing.h"		// TODO: Implement the class DoubleHashing

#include <string>
#include <iostream>
using namespace std;

int main(){
	const int inputSize = 6;
	const int bucketSize = 13; //the size of the hash table

	// Generate some input values
	int input[inputSize];
	for (int i=0; i<inputSize; i++) {
		input[i] = 1 + bucketSize*i;
	}

	Hashing *hashMethod[4];
	hashMethod[0] = new SeparateChaining(bucketSize);
	hashMethod[1] = new LinearProbing(bucketSize);
	hashMethod[2] = new QuadraticProbing(bucketSize);
	hashMethod[3] = new DoubleHashing(bucketSize);
	string hashNames[4] = {"SeparateChaining", "LinearProbing", "QuadraticProbing", "DoubleHashing"};

	for(int i = 0; i < 4; i++){
		cout<<"Hash Method " << (i+1) << " : "<< hashNames[i]<<endl;
		for (int j=0; j<inputSize; j++) {
			hashMethod[i]->insert( input[j] );
			cout << "Step " << j+1 << " : " ;
			hashMethod[i]->print();
		}
		cout<<endl;
		delete hashMethod[i];
	}
}




