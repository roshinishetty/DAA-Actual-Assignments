#include <bits/stdc++.h>
#include "Point.h"
#include "Common.h"
#include "Jarvis.h"
#include "GrahamStack.h"
#include "Graham.h"
#include "Kirkpatrick.h"

using namespace std;

int main() {
	int n;

	cout << "enter number of points" << endl;
	cin >> n;

	double x, y;
	vector<Point> points;

	for (int i=0; i<n; i++)
	{
		cin >> x >> y;
		points.push_back( Point(x, y) );
	}
	
	Jarvis obj1;
	obj1.setInputData(&points);
	obj1.run();
	cout << "Using Jarvis March algorithm" << endl;
	obj1.printConvexHull();

	Graham obj2;
	obj2.setInputData(&points);
	obj2.run();
	cout << "Using Graham scan algorithm" << endl;
	obj2.printConvexHull();

	Kirkpatrick obj3;
	obj3.setInputData(&points);
	cout << "Input data set using Kirkpatrick" << endl;
	obj3.run();
	
	obj3.printConvexHull();

	return 0;
}
