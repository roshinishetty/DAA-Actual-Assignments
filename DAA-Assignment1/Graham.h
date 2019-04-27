#ifndef GRAHAM_H
#define GRAHAM_H

#include "Point.h"
#include "Common.h"
#include "GrahamStack.h"

class Graham : public Common {

private:
	//! A private variable.
    /*!
        p0 is the starting point of the convex hull, which is at the bottom left.
    */
	Point p0;
	//! A private variable.
    /*!
        stack is a GrahamStack object that uses vector to store elements, tos to store top element.
    */	
	GrahamStack stack;
	//! A private  static bool variable.
    /*!
        compare compares checks if the orientation of p0,p1,p2 is anticlockwise or not. 
    */
	static bool compare(const Point &p1, const Point &p2);
	//! A private variable.
    /*!
    	getConvexHull finds the convex hull by graham scan algorithm using graham stack
	*/
	void getConvexHull( std::vector<Point> & pointsArray, GrahamStack stack, std::vector<Point> & ConvexHull);

public:
	//! A private variable.
    /*!
        It runs getConvexHull, which uses Graham algorithm.
    */
	void run();		

};

#endif //GRAHAM_H