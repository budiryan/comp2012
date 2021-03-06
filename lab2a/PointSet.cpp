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
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's other constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
  this->numPoints = num_in;
  for(int i = 0; i < num_in ;i++)this->points[i] = points_in[i];
   
}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   this->numPoints = s.numPoints;
   for(int i = 0; i < s.numPoints ; i++)this->points[i] = s.points[i];

}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here
   if(this->numPoints < 5){
		this->points[this->numPoints] = p;
		this->numPoints++;
   }
   else cout<<"Insufficient array space"<<endl;

}

bool PointSet::contains(const Point3D& p) const
{
   // TODO: add your code here
   for(int i = 0;i < this->numPoints;i++){
	   if(p.equal(this->points[i])){
		   return true;
		   break;
	   }
   }
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

