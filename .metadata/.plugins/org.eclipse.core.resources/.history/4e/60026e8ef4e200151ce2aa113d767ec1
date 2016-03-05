/* COMP2012 2016S Lab03 */

// Triangle.h is the header file for the class Triangle

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point2D.h"
#include "Polygon.h"

class Triangle: public Polygon
{
	public:
		/*
		 *  Constructor
		 *  Check if the number of points is 3 or not.
		 *  If not, output "Illegal! Number of points should be 3" and exit the program.
		 *  Otherwise, output "Initialized by Triangle's other constructor"
		 */
		Triangle(const Point2D points[], int numPoints);

		/*
		 *  Destructor
		 *  Output "Triangle's destructor!"
		 */
		~Triangle();

		/*
		 *  Print list of points, the perimeter and the area of the triangle object
		 */
		void print() const;

		/*
		 *  Compute the perimeter of the triangle
		 *
		 *  Note:
		 *  You are required to check if the three points are collinear.
		 *  If so, return 0.0, otherwise return the perimeter
		 *
		 *  Condition for collinear points
		 *  ==============================
		 *	Let (x1,y1), (x2,y2), (x3,y3) be the coordinates of three vertices
		 *	Three points are collinear if (y1 - y2)(x3 - x2) = (y3 - y2)(x1 - x2)
		 */
		double perimeter() const;

		/*
		 *  Compute the area of the triangle
		 *
		 *  Formula of area of a triangle
		 *  =============================
		 *	Let a, b, c be the lengths of the sides of a triangle,
		 *	the area of triangle is given by
		 *	sqrt( p(p - a)(p - b)(p - c) ), where p = (a + b + c)/2
		 *
		 *  Note:
		 *  You are required to check if the three points are collinear.
		 *  If so, return 0.0, otherwise return the computed area
		 *
		 *  Condition for collinear points
		 *  ==============================
		 *	Let (x1,y1), (x2,y2), (x3,y3) be the coordinates of three vertices
		 *	Three points are collinear if (y1 - y2)(x3 - x2) = (y3 - y2)(x1 - x2)
		 */
		double area() const;
};

#endif
