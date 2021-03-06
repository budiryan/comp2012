#include "Polygon.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Polygon :: Polygon(): n_points(0),points(NULL){
	cout<<"Initialized by Polygon's default constructor"<<endl;
}

Polygon :: Polygon(const Polygon& s){
	this->n_points = s.n_points;
	this->points = new Point2D [this->n_points];
	for(int i = 0 ; i < this->n_points ; i++) this->points[i] = s.points[i];
	cout<< "Initialized by Polygon's copy constructor"<<endl;
}

Polygon :: Polygon(const Point2D points[], int numPoints){
	cout<<"Initialized by Polygon's other constructor"<<endl;
	this->n_points = numPoints;
	this->points = new Point2D[this->n_points];
	for(int i = 0 ; i < this->n_points; i++) this->points[i] = points[i];
}

Polygon :: ~Polygon(){
	cout<<"Polygon's destructor"<<endl;
	delete [] this->points;
	this->points = NULL;
}

void Polygon :: print()const{
	cout<<"Number of points: "<<this->n_points<<endl;
	cout<<"Points: "<<endl;
	for(int i = 0 ; i < this->n_points; i++){
		this->points[i].print();
		cout<<endl;
	}
}



