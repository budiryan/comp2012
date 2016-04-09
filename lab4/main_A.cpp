/*
* main() for Part A
*/

#include <iostream>
#include "Engine.h"
#include "Car.h"
#include "PoliceCar.h"
using namespace std;

int main(){

	//Car
	Car *c = new Car(12,Sliver,12000);
	c->print();
	cout << endl;

	c->start();
	c->brake(1200);
	cout << endl;

	c->print();
	cout << endl;

	//PoliceCar
	PoliceCar *pc = new PoliceCar(8, Black, 100000, false);
	pc->print();
	cout << endl;

	pc->setInAction(true);
	pc->start();
	cout << endl;
	cout << "Current state of the police car: ";
	if(pc->getInAction())
		cout << "in action" << endl;
	else
		cout << "not in action" << endl;
	cout << endl;

	pc->brake(500);
	cout << endl;

	pc->setInAction(false);
	pc->print();

	delete c;
	c = pc;
	cout << endl;
	c->print();

	delete pc;

	return 0;
}



