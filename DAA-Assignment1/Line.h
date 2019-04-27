#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line {

    public:
        //! A public variable.
        /*!
            p1 is the starting point of the line segment.
        */
        Point p1;

        //! A public variable.
        /*!
            p2 is the ending point of the line segment.
        */
        Point p2;
        //! A public variable.
        /*!
            M is the slope of the line segment.
        */
        double M;
        //! A public variable.
        /*!
            C is the intercept of the line segment on y-axis.
        */
        double C;

        /** 
        * A constructor.
        * It creates a default Line with 0 slope and intercept.
        */	
        Line() {
            M=0;
            C=0;
        }
        /** 
        * A constructor.
        * It creates a Line from p1 to p2 and calculate it's parameters, M and C.
        */	

        Line(Point p1, Point p2) {
            this->p1 = p1;
            this->p2 = p2;
            calculateParams();
        }

        //! A public function.
        /*!
            It calculates the parameters, slope and intercept for the given line.
        */
        void calculateParams() {
            M = (p1.GetY() - p2.GetY()) / (p1.GetX() - p2.GetX());
            C = p1.GetY() - M * p1.GetX();
        }

	    //! A public member taking no arguments and returning a double constant value.
        /*!
        This function is to retrieve slope.
        */    
        double getSlope() {
            return M;
        }
   	    //! A public member taking no arguments and returning a double constant value.
        /*!
            This function is to retrieve intercept.
        */     
        double getIntercept() {
            return C;
        }
};

#endif 