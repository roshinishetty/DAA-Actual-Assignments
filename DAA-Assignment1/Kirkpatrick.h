#ifndef KIRKPATRICK_H
#define KIRKPATRICK_H

#include "Point.h"
#include "Common.h"
#include "Line.h"
#include "median.h"

class Kirkpatrick : public Common {

private:
        //! A public variable.
        /*!
           _UL is upper left Point.
        */
    Point _UL;
        //! A public variable.
        /*!
           _UR is upper right Point.
        */    
    Point _UR;
        //! A public variable.
        /*!
           _LL is lower left Point.
        */
    Point _LL;
        //! A public variable.
        /*!
           _LR is lower right Point.
        */
    Point _LR;
    static bool comparePoints(const Point &p1, const Point &p2) ;
    //! A function crossProduct.
    /*!
     \param l a Point object
     \param r a Point object
     \return double
      It finds the cross product of 2 vectors.
    */    
    double crossProduct( Point l, Point r);
    //! A function getExtremePoints.
    /*!
     \param pointsArray an adress of vector of Point objects
     \return void
      It finds extreme points, upper left, upper right, lower left, lower right.
    */     
    void getExtremePoints(const std::vector<Point> & pointsArray);
    //! A function findUpperSupportingLine.
    /*!
     \param pk a pointer of Point
     \param pm a pointer of Point 
     \param S a vector of Point
     \param alpha double
     \return void
      It finds a supporting line in the upper hull, that is the line with the median slope with greatest intercept. 
      The line segments extreme points are stored in pk and pm.
    */ 
    void findUpperSupportingLine( Point &pk, Point &pm, vector<Point> S, double alpha);
    //! A function upperBridge.
    /*!
     \param pl a pointer of Point
     \param pr a pointer of Point 
     \param S a vector of Point
     \param med double
     \return void
      It finds the upper bridge by pairing the points and finding the median of their slopes. 
      Then, median of slopes is used to classify the lines into 3 classes. 
      A supporting line is found. 
      Depending on the median of x coordinates and extremes of supporting line, candidate vector of Point is formed.
      This is used to call the upperBridge function recursively.
    */     
    void upperBridge(Point &pl, Point &pr, vector<Point> S, double med);
    //! A function upperHull.
    /*!
     \param pmin a Point
     \param pmax a Point 
     \param P a vector of Point
     \return vector of Point
      It finds the upper hull by finding median of x coordinates, which is used to find upperBridge. 
      All the points on the left side of upper bridge are found and used for recursively 
      calling upperHull function. Similarly, all points on right side are found and used to call 
      upperHull function. These 2 functions find the upper hull points and are merged.   
    */    
    vector<Point> upperHull(Point pmin, Point pmax, vector<Point> P);
    //! A function findLowerSupportingLine.
    /*!
     \param pk a pointer of Point
     \param pm a pointer of Point 
     \param S a vector of Point
     \param alpha double
     \return void
      It finds a supporting line in the lower hull, that is the line with the median slope with least intercept. 
      The line segments extreme points are stored in pk and pm.
    */    
    void findLowerSupportingLine( Point &pk, Point &pm, vector<Point> S, double alpha);
    //! A function lowerBridge.
    /*!
     \param pl a pointer of Point
     \param pr a pointer of Point 
     \param S a vector of Point
     \param med double
     \return void
      It finds the lower bridge by pairing the points and finding the median of their slopes. 
      Then, median of slopes is used to classify the lines into 3 classes. 
      A supporting line is found. 
      Depending on the median of x coordinates and extremes of supporting line, candidate vector of Point is formed.
      This is used to call the lowerBridge function recursively.
    */     
    void lowerBridge(Point &pl, Point &pr, vector<Point> S, double med);
    //! A function lowerHull.
    /*!
     \param pmin a Point
     \param pmax a Point 
     \param P a vector of Point
     \return vector of Point
      It finds the lower hull by finding median of x coordinates, which is used to find lowerBridge. 
      All the points on the left side of lower bridge are found and used for recursively 
      calling lowerHull function. Similarly, all points on right side are found and used to call 
      lowerHull function. These 2 functions find the lower hull points and are merged.   
    */    
    vector<Point> lowerHull(Point pmin, Point pmax, vector<Point> P);    
    //! A function getConvexHull.
    /*!
     \param pointsArray a pointer to vector of Point
     \param convexHull a pointer to vector of Point 
     \return void
      It finds all the convex hull points by first finding the extreme points, then calling upper and lower hull functions. 
    */
    void getConvexHull(const std::vector<Point> & pointsArray, std::vector<Point> & ConvexHull);

public:
	void run();		

};

#endif //KIRKPATRICK_H