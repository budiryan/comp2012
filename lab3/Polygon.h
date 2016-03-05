/*
 * Polygon.h
 * The header file for the class Polygon
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Point2D.h"

class Polygon
{
	public:
		/*
		 *  Default constructor
		 *  Output "Initialized by Polygon's default constructor"
		 *  Set n_points to 0 and points to NULL
		 */
		Polygon();

		/*
		 *  Copy constructor
		 *  Output "Initialized by Polygon's copy constructor", and
		 *  perform deep copying
		 */
		Polygon(const Polygon& s);

		/*
		 *  Other constructor
		 *  Output "Initialized by Polygon's other constructor", and
		 *  perform deep copying
		 */
		Polygon(const Point2D points[], int numPoints);

		/*
		 *  Destructor
		 *  Output "Polygon's destructor!" and destruct all the points
		 */
		~Polygon();

		/*
		 *  Print the list of 2D points in the set and the number of the points
		 *  Check if the number of points is 0. If so, output "The Polygon is empty!".
		 *  Otherwise, output the number of points of polygon and all the points.
		 */
		void print() const;

	protected:
		int n_points;
		Point2D *points;
};

#endif
