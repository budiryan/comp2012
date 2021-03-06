#include "Triangle.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits>
using namespace std;

Triangle :: Triangle(const Point2D points[],int numPoints) : Polygon(points, numPoints){
	if(this->n_points < 3){
		cout<<"Illegal! Number of points should be 3"<<endl;
		exit(0);
	}
	cout<<"Initialized by Triangle's other constructor"<<endl;
}



Triangle :: ~Triangle(){
	cout<<"Triangle's destructor"<<endl;
}

void Triangle :: print()const{
	Polygon::print();
	cout<<"Triangle's perimeter: "<<this->perimeter()<<endl;
	cout<<"Triangle's area: "<<this->area()<<endl;
}

double Triangle :: perimeter() const{
	double left = (points[0].getY() - points[1].getY()) * (points[2].getX() - points[1].getX());
	double right = (points[2].getY() - points[1].getY()) * (points[0].getX() - points[1].getX());
	bool collinear = fabs(left - right) < numeric_limits<double>::epsilon() ? true : false;
	if(collinear){
		return 0.0;
	}
	else{
		//Compute the length of each vertice
		double a,b,c;
		a = sqrt(pow((points[0].getX() - points[1].getX()), 2) + pow((points[0].getY() - points[1].getY()), 2));
		b = sqrt(pow((points[0].getX() - points[2].getX()), 2) + pow((points[0].getY() - points[2].getY()), 2));
		c = sqrt(pow((points[1].getX() - points[2].getX()), 2) + pow((points[1].getY() - points[2].getY()), 2));
		return a+b+c;
	}
}

double Triangle :: area() const{
	double left = (points[0].getY() - points[1].getY()) * (points[2].getX() - points[1].getX());
	double right = (points[2].getY() - points[1].getY()) * (points[0].getX() - points[1].getX());
	bool collinear = fabs(left - right) < numeric_limits<double>::epsilon() ? true : false;
	if(collinear){
		return 0.0;
	}
	else{
		double a,b,c;
		a = sqrt(pow((points[0].getX() - points[1].getX()), 2.0) + pow((points[0].getY() - points[1].getY()), 2.0));
		b = sqrt(pow((points[0].getX() - points[2].getX()), 2.0) + pow((points[0].getY() - points[2].getY()), 2.0));
		c = sqrt(pow((points[1].getX() - points[2].getX()), 2.0) + pow((points[1].getY() - points[2].getY()), 2.0));
		double p;
		p = (a+b+c)/2.0;
		double area;
		area = sqrt(p*(p - a)*(p - b)*(p - c));
		return area;
	}

}
