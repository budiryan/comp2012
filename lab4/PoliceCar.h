
#ifndef POLICECAR_H_
#define POLICECAR_H_

#include "Car.h"

class PoliceCar : public Car
{
public:
	PoliceCar(int nc, Color c, int m, bool action);	//Constructor
	~PoliceCar(); //Destructor

	bool getInAction() const;
	void setInAction(bool action);

	////Print the information of the PoliceCar. Please refer to the sample I/O.
	void print() const;

private:
	bool inAction;	//Data member indicating whether the police car is in action.
};



#endif /* POLICECAR_H_ */
