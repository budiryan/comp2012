/*
 * Cat.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */
#include "Cat.h"
#include <iostream>
using namespace std;

Cat :: Cat(int type):Animal(){
	this->type = type;
}

void Cat :: calculatePrice(){
	cout<<"Cat::calculatePrice() is called!"<<endl;
	switch(this->type){
	case 0:
		this->setPrice(50.0);
		break;
	case 1:
		this->setPrice(100.0);
		break;
	case 2:
		this->setPrice(150.0);
		break;
	default:
		cout<<"Species is not found!"<<endl;
	}
}


