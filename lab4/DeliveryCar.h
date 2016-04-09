/*
 * DeliveryCar.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Budi Ryan
 */

#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_
#include "Vehicle.h"

class DeliveryCar: protected Vehicle{
	public:
		DeliveryCar(int nc, Color color, int mileage, int cpm);
		~DeliveryCar();
		void setCharge(int charge);
		int getCharge(void) const;

		void print(void)const;
		void start(void)const;
		void brake(int v);

	private:
		int chargePerMile;
};




#endif /* DELIVERYCAR_H_ */
