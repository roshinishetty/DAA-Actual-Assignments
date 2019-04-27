#ifndef POINT_H
#define POINT_H

/**
 *  Point class, that stores point's spatial coordintes and performs actions on the point
 */

class Point
{
	public:
	
	/** 
     * A constructor.
     * It creates a default Point with (0,0) as it's spatial coordinates.
     */
		Point();
	/** 
     * A constructor.
     * It creates a Point with the given spatial coordinates.
     */
		Point(double x, double y);
	/** 
     * A constructor.
     * It creates a Point with the vector coordinates from p1 to p2.
     */		
		Point(Point p1, Point p2);
	
	//! A public member taking no arguments and returning a double constant value.
    /*! 
	  This function is to retrieve x coordinate.
    */
		double GetX() const;

	//! A public member taking no arguments and returning a double constant value.
    /*!
      This function is to retrieve y coordinate.
    */	
		double GetY() const;
	//! A public member taking 1 argument and returning a boolean value.
   /*!
      \param p a Point object.
      \return if point is same as this Point.   
    */
		bool isSame(Point p);

    bool operator == (Point p);
	private:
		/** 
       * a private variable.
       * It stores the x coordinate and is of type double.
       */
		double m_x;
		/** 
       * a private variable.
       * It stores the y coordinate and is of type double.
       */
		double m_y;	
};

#endif //POINT_H