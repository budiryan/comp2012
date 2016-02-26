/*
 * Point3D.h
 * The header file for the class Point3D
 */
 
class Point3D
{
	public:
		Point3D();	//Default constructor. It creates a point (0,0,0)
		Point3D(const Point3D& p);	//Copy constructor
		Point3D(double x);	//Conversion constructor that can convert a double to a Point3D object
		Point3D(double x, double y, double z);	//Construct a point with given coordinates
		bool equal(const Point3D& p) const;	//Check whether two 3D points are the same
		void print() const;	//Print the 3D point

	private:
		double x,y,z;	//Coordinates
};
