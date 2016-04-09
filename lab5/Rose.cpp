/*
 * Rose.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */
#include "Rose.h"
#include <iostream>
using namespace std;


Rose :: Rose(int roseColor){
	this->color = roseColor;
}

void Rose :: calculatePrice(){
	cout<<"Rose::calculatePrice() is called!"<<endl;
	switch(this->color){
	case 0:
		this->setPrice(100.0);
		break;
	case 1:
		this->setPrice(200.0);
		break;
	case 2:
		this->setPrice(300.0);
		break;
	case 3:
		this->setPrice(400.0);
		break;
	default:
		cout<<"Color of the Rose is invalid!"<<endl;
	}
}



