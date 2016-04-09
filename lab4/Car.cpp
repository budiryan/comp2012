/*
 * Car.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Budi Ryan
 */

#include "car.h"
#include <iostream>
using namespace std;

Car :: Car(int nc, Color color, int mileage) : engine(nc){
	this->color = color;
	this->mileage = mileage;
}

Color Car :: getColor() const{
	return this->color;
}

Car :: ~Car(){
	cout<<endl;
	cout<<"Calling Car's destructor on the following car:"<<endl;
	this->print();
}

int Car :: getMileage() const{
	return this->mileage;
}

int Car :: getEngine() const{
	return this->engine.getNumCylinder();
}

void Car :: start(){
	cout<<"Car with "<<this->getEngine()<<"-cylinder engine started."<<endl;
}

void Car :: brake(int distance){
	this->mileage += distance;
	cout<<"Car with "<< this->getEngine() <<"-cylinder engine stopped."<<endl;
	cout<<"Driving distance: "<<distance<<endl;
}

void Car :: print()const{
	cout<<"Engine: "<< this->getEngine()<<"\tColor: "<<this->getColor() << "\tCurrent Mileage: "<< this->getMileage()<<endl;
}




