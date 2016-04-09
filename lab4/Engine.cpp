/*
* Engine.cpp
*/

#include <iostream>
#include "Engine.h"
using namespace std;

//Conversion constructor
Engine::Engine(int nc) : numCylinder(nc) {}

int Engine::getNumCylinder() const {
	return numCylinder;
}

//Start the engine
void Engine::Start(){
	cout << getNumCylinder() << "-cylinder engine started." << endl;
}

//Stop the engine
void Engine::Stop(){
	cout << getNumCylinder() << "-cylinder engine stopped." << endl;
}

