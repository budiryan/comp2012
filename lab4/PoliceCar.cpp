/*
 * PoliceCar.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Budi Ryan
 */

#include "PoliceCar.h"
#include <iostream>
using namespace std;

PoliceCar :: PoliceCar(int nc, Color c, int m, bool action): Car(nc ,c ,m){
	this->inAction = action;
}

PoliceCar :: ~PoliceCar(){
	cout<<endl;
	cout<<"Calling PoliceCar's destructor on the following police car: "<<endl;
	this->print();
}

bool PoliceCar :: getInAction() const{
	return this->inAction;
}

void PoliceCar :: setInAction(bool action){
	this->inAction = action;
}

void PoliceCar :: print() const{
	cout<<"Information of the police car: "<<endl;
	Car :: print();
	cout<<"State: ";
	if(this->getInAction()) cout<<"in action"<<endl;
	else cout<<"not in action"<<endl;
}

