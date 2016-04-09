#include "Organism.h"
#include "Cat.h"
#include "Pig.h"
#include "Rose.h"
#include "Carrot.h"
#include <iostream>
using namespace std;

int main(){
	const int numOfOrganism = 4;

	// Dynamically allocate an array of Organism*
	Organism **orgVec = new Organism*[numOfOrganism];

	//An cat object: species id = 1.
	//Note: 0---the first species, 1---the second species, 2---the third species
	Cat *catObj = new Cat(1);

	//An pig object: weight = 100.0, the Price per weight unit = 4.25
	Pig *pigObj = new Pig(100.0, 4.25);

	//An rose object: color_id = 2
	//Note: 0---red color, 1---pink, 2---white, 3--blue
	Rose *roseObj = new Rose(2);

	//An carrot object: weight = 10.0, the price per weight-unit = 8.5
	Carrot *carrotObj = new Carrot(10.0, 8.5);

	orgVec[0] = catObj;    //cat is an organism
	orgVec[1] = pigObj;    //pig is an organism
	orgVec[2] = roseObj;   //rose is an organism
	orgVec[3] = carrotObj; //carrot is an organism

	//calculate the prices of all the organism objects
	double totalPrice = 0.0;
	for(int i = 0; i < numOfOrganism ; ++i){
		cout<<"The initial price of this object is "<<orgVec[i]->getPrice()<<endl;
		orgVec[i]->calculatePrice();
		totalPrice += orgVec[i]->getPrice();
		cout<<"Now the price of this object is "<<orgVec[i]->getPrice()<<endl;
		cout<<endl;
	}
	cout<<"The total price of all the organism objects is " <<totalPrice<<endl;

	// Clean up
	for(int i = 0; i < numOfOrganism; ++i)
		delete orgVec[i];
	delete [] orgVec;

	return 0;
}


