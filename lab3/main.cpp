/*
 * main.cpp
 *
 */

#include <iostream>
#include "Point2D.h"
#include "Triangle.h"
#include <math.h>
using namespace std;

int main() {
	cout << "Triangle1:" << endl;
	Point2D points1[3] = { Point2D(0, 0), Point2D(1, 0), Point2D(1, 1) };
	Triangle *triangle1 = new Triangle(points1, 3); // Initialized by the constructor
	triangle1->print();
	cout << endl;
	delete triangle1;
	cout << endl;

	cout << "Triangle2:" << endl;
	Point2D points2[3] = { Point2D(0, 0), Point2D(1, 1), Point2D(2, 2) };
	Triangle *triangle2 = new Triangle(points2, 3); // Initialized by the constructor
	triangle2->print();
	cout << endl;
	delete triangle2;
	cout << endl;

	cout << "Triangle3:" << endl;
	Point2D points3[2] = { Point2D(0, 0), Point2D(1, 1) };
	Triangle *triangle3 = new Triangle(points3, 2); // Initialized by the constructor

	return 0;
}
