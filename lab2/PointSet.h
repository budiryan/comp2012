/*
 * PointSet.h
 * The header file for the class PointSet
 */

const int DEFNUM = 5;
#include "Point3D.h"
class PointSet
{
	public:
		PointSet();	//Default constructor
		PointSet(const PointSet& s);	//Copy constructor
		PointSet(const Point3D points[], int numPoints);	// Other constructor

		void addPoint(const Point3D& p);	//add a 3D point p(x,y,z) to the set
		bool contains(const Point3D& p) const;	//return true if the given 3D point p(x,y,z) is in the set; return false otherwise
		void print() const;	// print the list of 3D points in the set

	private:
		int numPoints;
		Point3D points[DEFNUM];

};
