#include "Organism.h"

Organism :: Organism(){
	this->price = 0.0;
}

void Organism :: setPrice(const float p){
	this->price = p;
}

float Organism :: getPrice(void)const{
	return this->price;
}

Organism :: ~Organism(){

}

