/*
 * Pig.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */
#include "Pig.h"
#include <iostream>
using namespace std;

Pig :: Pig(float w, float ppw):Animal(){
	this->pricePerWeight = ppw;
	this->weight = w;
}

void Pig :: calculatePrice(){
	cout<<"Pig::calculatePrice() is called!"<<endl;
	this->setPrice(this->pricePerWeight * this->weight);
}


