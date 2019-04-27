#include "Point.h"
#include<bits/stdc++.h>
#define E 0.0000001
using namespace std;

Point::Point()
{ m_x = 0; 
  m_y = 0;
}

Point::Point(double x,double y):
		m_x(x),
		m_y(y)
{}

Point::Point(Point p1, Point p2):
		m_x(p2.GetX() - p1.GetX()),
		m_y(p2.GetY() - p1.GetY())
{}		

double Point::GetX() const
{
	return m_x;
}

double Point::GetY() const
{
	return m_y;
}

bool Point::isSame(Point p)
{
	return (abs(m_x-p.GetX()) < E && abs(m_y-p.GetY()) <E);
}

bool Point::operator == (Point p)
{
	//No need for fancy float comparator as value is never manipulated
	if(p.GetX() == m_x && p.GetY() == m_y)
		return true;
	else
		return false;
}