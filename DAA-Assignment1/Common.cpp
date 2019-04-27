#include <bits/stdc++.h>
#include "Common.h"
#define E 0.0000001

using namespace std;

bool Common::isequal(double d1, double d2) {
	double epsilon = 0.0000001;
	return abs(d1-d2) < d1*epsilon;
}

int Common::orientation(Point p, Point q, Point r)
{
	double val = (q.GetY() - p.GetY()) * (r.GetX() - q.GetX()) - (q.GetX() - p.GetX()) * (r.GetY() - q.GetY());
	if (abs(val-0) < E  ) return 0;

	return (val > 0) ? 1 : 2;
}

double Common::dist(Point p, Point q)
{
	return sqrt( (p.GetX()-q.GetX()) * (p.GetX()-q.GetX()) + 
				(p.GetY()-q.GetY())*(p.GetY()-q.GetY())  );
}

int Common::findBottomtMostPoint(const vector<Point> & points, int size)
{
	// Pick the bottom-most or the left most in case of ties

	int ymin = points[0].GetY();
	int min = 0;

	for (int i=1; i<size; i++)
	{
		if (points[i].GetY() < ymin) {
			ymin = points[i].GetY();
			min = i;
		} else if (abs(points[i].GetY() - ymin) < E && points[i].GetX() < points[min].GetX()) {
			min = i;
		}
	}

	return min;
}

void Common::setInputData(const vector<Point> *pointsArray)
 {
 	_pointsArray = *pointsArray;
 }		

 void Common::run()
 {
 	
 }

 void Common::printConvexHull()
 {
 	int size = _convexHull.size();

 	cout << "x" << "\t" << "y" << endl;

 	for(int i=0; i<size; i++)
 	{
 		cout << _convexHull[i].GetX() << "\t" << _convexHull[i].GetY() << endl;
 	}
 }