#include <bits/stdc++.h>
#include "Jarvis.h"

using namespace std;

void Jarvis::run()
 {
 	getConvexHull(_pointsArray, _convexHull);
 }

bool Jarvis::isInside(Point p, Point q, Point r)
{
	return ( p.GetX()<=q.GetX() || isequal(p.GetX(), q.GetX())) && 
			( q.GetX()<=r.GetX() || isequal(q.GetX(), r.GetX())) &&
			( p.GetY()<=q.GetY() || isequal(p.GetY(), q.GetY())) &&
			( q.GetY()<=r.GetY() || isequal(q.GetY(), r.GetY())) ; 
}

void Jarvis::getConvexHull(const vector<Point> & pointsArray, vector<Point> & ConvexHull)
{
	
	int size = pointsArray.size();

	if(size < 3) return;

	int first = findBottomtMostPoint(pointsArray, size);

	int curr = first, next;

	do{
		ConvexHull.push_back(pointsArray[curr]);

		next = (curr + 1)%size;
        int orient;

		for(int i=0; i<size; i++) {

			orient = orientation(pointsArray[curr], pointsArray[i], pointsArray[next] );
			if (orient == 2){
				next = i;	
			}
		}

		curr = next;

		// if(curr != first) {
		// 	ConvexHull.push_back( pointsArray[curr] );
		// }

 	} while(curr!=first);

}