#include <iostream>
#include "Vehicle.h"
#include "Engine.h"
#include "DeliveryCar.h"

using namespace std;

int main(){
		Vehicle *c2 = new Vehicle(6,Red,1500);
		c2->print();
		cout << endl;

		c2->start();
		c2->brake(20);
		cout << endl;

		c2->print();
		cout << endl;

		//DeliveryCar
		DeliveryCar *dc = new DeliveryCar(10,White,7500,20);
		dc->print();
		cout << endl;

		dc->start();
		dc->brake(120);
		cout << endl;

		dc->setCharge(15);
		dc->print();
		cout << endl;

		delete c2;
		delete dc;

		return 0;
}



