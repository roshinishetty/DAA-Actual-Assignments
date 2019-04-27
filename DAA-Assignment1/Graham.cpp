#include <bits/stdc++.h>
#include "Graham.h"

using namespace std;

bool Graham::compare(const Point &p1, const Point &p2) {
	return ((p1.GetX()*p2.GetY() - p2.GetX()*p1.GetY() ) > 0) ;
} 


void Graham::getConvexHull(std::vector<Point> & pointsArray, GrahamStack stack, std::vector<Point> & ConvexHull)
{

	int n = pointsArray.size();
	int first = findBottomtMostPoint(pointsArray, n);

	std::swap(pointsArray[0], pointsArray[first]);
    
	Point p0 = pointsArray[0];
	
	std::sort(pointsArray.begin()+1, pointsArray.end(), compare);

	int newSize = 1;
	for (int i =1; i<n; i++)
	{
		while (i < n-1 && orientation(p0, pointsArray[i], pointsArray[i+1]) < 0)
		{
			i++;
		}
		 
		pointsArray[newSize] = pointsArray[i];
		newSize++;
	}

	if(newSize < 3) return;

	stack.pushElement(pointsArray[0]);
	stack.pushElement(pointsArray[1]);
	stack.pushElement(pointsArray[2]);

	for(int i=3; i<newSize; i++) {
		while (orientation( stack.getNextToTop(), stack.getTOS(), pointsArray[i]) != 2)
			stack.popElement();	
		stack.pushElement(pointsArray[i]);		
	}

	ConvexHull = stack.getStack();
}

void Graham:: run() {
	getConvexHull(_pointsArray, stack, _convexHull);
}