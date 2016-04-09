/*
 * Vehicle.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Budi Ryan
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "engine.h"

class Vehicle: private Engine{
	public:
	Vehicle(int nc, Color color, int mileage); // Constructor
	Color getColor() const;
	int getMileage() const;
	int getEngine() const;
	~Vehicle();

	// Start the engine and print the information.
	// Please refer to the sample I/O.
	void start()const;

	// Stop the engine and update the data member "mileage" by adding the traveled distance to it.
	// Print the information.
	// Please refer to the sample I/O.
	void brake(int distance);

	// Print the information of the car. (Please refer to the I/O sample)
	void print() const;

private:
	Color color;	// Color of the car
	int mileage;	// Total mileage

};




#endif /* VEHICLE_H_ */
