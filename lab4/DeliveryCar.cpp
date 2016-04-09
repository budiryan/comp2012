/*
 * DeliveryCar.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Budi Ryan
 */

#include "DeliveryCar.h"
#include <iostream>
using namespace std;

DeliveryCar :: DeliveryCar(int nc, Color color, int mileage, int cpm):Vehicle(nc , color , mileage){
	setCharge(cpm);
}

void DeliveryCar :: setCharge(int c){
	this->chargePerMile = c;
}

DeliveryCar :: ~DeliveryCar(){
	cout<<endl;
	cout<<"Calling Vehicle's destructor on the following delivery car: "<<endl;
	this->print();
}

int DeliveryCar :: getCharge(void)const{
	return this->chargePerMile;
}

void DeliveryCar :: print(void)const{
	cout<<"Information of the delivery car: "<<endl;
	Vehicle :: print();
	cout<<"Charges per mile: "<<getCharge()<<endl;
}

void DeliveryCar :: start(void)const{
	Vehicle :: start();
}

void DeliveryCar :: brake(int v){
	Vehicle :: brake(v);
}



