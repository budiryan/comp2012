
#ifndef CAR_H_
#define CAR_H_

#include "Engine.h"

class Car
{
public:
	Car(int nc, Color color, int mileage); // Constructor
	Color getColor() const;
	int getMileage() const;
	int getEngine() const;
	~Car();

	// Start the engine and print the information.
	// Please refer to the sample I/O.
	void start();

	// Stop the engine and update the data member "mileage" by adding the traveled distance to it.
	// Print the information.
	// Please refer to the sample I/O.
	void brake(int distance);

	// Print the information of the car. (Please refer to the I/O sample)
	void print() const;

private:
	Engine engine;		// Car has-a engine
	Color color;	// Color of the car
	int mileage;	// Total mileage

};




#endif /* CAR_H_ */
