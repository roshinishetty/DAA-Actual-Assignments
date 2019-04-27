#ifndef COMMON_H
#define COMMON_H

#include "Point.h"

class Common {

protected:
	//! A protected variable.
    /*!
        _convexHull is a vector of Point.
    */	
	std::vector<Point> _convexHull;
	//! A protected member taking 2 arguments and returning a bool.
    /*!
      	This function checks if both the doubles are equal.
    */
	bool isequal(double d1, double d2);
	//! A protected member taking 3 arguments and returning a static integer.
    /*!
      	This function finds the orientation of the points, that is, clockwise, anticlockwise or collinear.
    */	
	static int orientation(Point p, Point q, Point r);
	//! A protected member taking 2 arguments and returning a double.
    /*!
    	This function gives distance of the points.
    */	
	static double dist(Point p, Point q);
	//! A protected member taking 2 arguments and returning an integer.
    /*!
	 \param points a pointer to vector of Point
	 \param size an integer
      	This function fins the bottomost point, in case of ties, gives leftmost of those points.
    */	
	int findBottomtMostPoint(const std::vector<Point> & points, int size);


public:
	//! A public variable.
    /*!
        _pointsArray is a vector of Point.
    */	
	std::vector<Point> _pointsArray;
	//! A public member taking 2 arguments.
    /*!
    	This function sets input data with the given input.
    */	
	void setInputData(const std::vector<Point> *pointsArray);
	//! A public member taking no arguments and returning void.
    /*!
    	This function is overridden in the inherited classes.
    */	
	void run();
	//! A public member taking no arguments and returning void.
    /*!
    	This function gives all the points on the convex hull.
    */	
	void printConvexHull();

};

#endif //COMMON_H
