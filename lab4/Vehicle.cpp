#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle :: Vehicle(int nc, Color color, int mileage):Engine(nc){
	this->color = color;
	this->mileage = mileage;
}

Color Vehicle :: getColor() const{
	return this->color;
}

Vehicle :: ~Vehicle(){
	cout<<endl;
	cout<<"Calling Vehicle's destructor on the following Vehicle:"<<endl;
	this->print();
}

int Vehicle :: getMileage() const{
	return this->mileage;
}

int Vehicle :: getEngine() const{
	return Engine :: getNumCylinder();
}

void Vehicle :: start()const{
	cout<<"Vehicle with "<<this->getEngine()<<"-cylinder engine started."<<endl;
}

void Vehicle :: brake(int distance){
	this->mileage += distance;
	cout<<"Vehicle with "<< this->getEngine() <<"-cylinder engine stopped."<<endl;
	cout<<"Driving distance: "<<distance<<endl;
}

void Vehicle :: print()const{
	cout<<"Engine: "<< this->getEngine()<<"\tColor: "<<this->getColor() << "\tCurrent Mileage: "<< this->getMileage()<<endl;
}
