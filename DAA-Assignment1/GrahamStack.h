#ifndef GRAHAMSTACK_H
#define GRAHAMSTACK_H

#include <bits/stdc++.h>
#include "Point.h"

class GrahamStack {
	
	private:
	    //! A private variable.
        /*!
            stack is a vector of Point that is used such that it's next to top and top element can be retrieved at any point of time.
        */
		std::vector<Point> stack;
		//! A private variable.
        /*!
            tos is the Point at the top of stack.
        */
		Point tos;
		//! A private variable.
        /*!
            nextToTop is the Point that is next to the topmost element of stack.
        */
		Point nextToTop;

	public:
		//! A public member taking 0 arguments and returning a Point.
    	/*!
      		This function gives topmost element of the stack.
    	*/
		Point getTOS();
		//! A public member taking 0 arguments and returning a Point.
    	/*!
      		This function gives next one to the topmost element of the stack.
    	*/		
		Point getNextToTop();
		//! A public member taking 1 argument and returning void.
    	/*!
      		This function pushes an element to the stack, that is, adds the element at the back of stack.
    	*/		
		void pushElement(Point p);
		//! A public member taking 0 arguments and returning null.
    	/*!
      		This function removes the last element from stack.
    	*/		
		void popElement();
		//! A public member taking 0 arguments and returning a vector of Point.
    	/*!
      		This function gives stack vector.
    	*/
		std::vector<Point> getStack();	
		/** 
     	* A constructor.
     	* It creates a GrahamStack that uses a vector to implement stack with top element and next to top element.
     	*/		
		GrahamStack();
};

#endif //GRAHAMSTACK_H