/*
 * Carrot.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#include "Carrot.h"
#include <iostream>
using namespace std;

Carrot :: Carrot(float ppw, float w){
	this->pricePerWeight = ppw;
	this->weight = w;
}

void Carrot :: calculatePrice(){
	cout<<"Carrot::calculatePrice() is called!"<<endl;
	this->setPrice(this->pricePerWeight * this->weight);
}


