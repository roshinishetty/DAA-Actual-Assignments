#ifndef JARVIS_H
#define JARVIS_H

#include "Common.h"
#include "Point.h"

class Jarvis : public Common {

private:
	//! A private member taking 3 arguments and returning a boolean value.
    /*!
      This function checks if Point q is in between Point p and Point r.
    */	
	bool isInside(Point p, Point q, Point r);
	//! A function getConvexHull.
    /*!
     \param pointsArray a pointer to vector of Point
     \param convexHull a pointer to vector of Point 
     \return void
      It finds all the convex hull points by Jarvis Algorithm.
	  In this algorithm, next point of convex hull is found such that all other points are in the anticlockwise sense.   
    */
	void getConvexHull(const std::vector<Point> & pointsArray, std::vector<Point> & ConvexHull);

public:
	//! A public member taking no arguments and returning void.
    /*!
      This function calls getConvexHull to find convex hull using Jarvis algorithm.
    */	
	void run();	

};

#endif //JARVIS_H