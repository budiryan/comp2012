/*
 * Organism.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Budi Ryan
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism{
public:
	Organism(void);
	Organism(float price);
	void setPrice(const float p);
	float getPrice(void)const;
	virtual void calculatePrice() = 0;
	virtual ~Organism(void);
private:
	float price;
};


#endif /* ORGANISM_H_ */
