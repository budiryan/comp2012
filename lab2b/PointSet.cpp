/*
 * PointSet.cpp
 * 
 */

#include "PointSet.h"
#include <iostream>
using namespace std;


PointSet::PointSet()
{
   cout << "Initialized by PointSet's default constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked
   numPoints = 0;
   points = NULL;
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's other constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked
   // TODO: add your code here
   this->numPoints = num_in;
   this->points = new Point3D[num_in];
   for(int i  = 0; i < num_in; i++) this->points[i] = points_in[i];
}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   this->numPoints = s.numPoints;
   this->points = new Point3D[s.numPoints];
   for(int i = 0; i < s.numPoints;i++)this->points[i] = s.points[i];

}

PointSet::~PointSet()
{
    cout<<"PointSet's destructor!" <<endl;
    // This cout statement is for learning purpose only, which shows when the desstructor will be invoked
     // TODO: add your code here
    //Free the allocated memory
    delete [] this->points;
    this->points = NULL;
}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here
	this->numPoints++;
	Point3D * temp= new Point3D[this->numPoints];
	for(int i = 0; i < this->numPoints - 1; i++)temp[i] = this->points[i];
	temp[this->numPoints - 1] = p;

	delete [] this->points;
	this->points = NULL;
	this->points = new Point3D[this->numPoints];

	this->points = temp;
	//for(int i = 0; i < this->numPoints; i++)this->points[i] = temp[i];
	//delete [] temp;
	//temp = NULL;
}

bool PointSet::contains(const Point3D& p) const
{
   // TODO: add your code here
   for(int i = 0;i < this->numPoints ; i++)if(this->points[i].equal(p))return true;
   return false;
}

void PointSet::print() const
{
   if (numPoints == 0) {
      cout << "The PointSet is empty!" << endl;
      return;
   }
   cout << "Number of points: " << numPoints << endl;;
   cout << "points: " << endl;
   for (int i = 0; i < numPoints; i++)
   {
      points[i].print();
      cout << endl;
   }
}

