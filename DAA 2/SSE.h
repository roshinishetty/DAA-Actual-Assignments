#include"geometry.h"
#include<algorithm>
#define endl "\n"
/*!
	Stores points from index 1 to n
*/	
std::vector<Point> points; 
std::vector<Line> lines1, lines2, lines3;

void input(std::vector<Point> &, int);
int inputFromFile(std::vector<Point> &);
double inputWeightFromFile(double);
bool compareX(Point, Point) ;
void outputToConsole(std::vector<Point>&);
void outputToConsole(std::vector<Line>&);
void outputToFile(std::vector<Line>&,std::string&);
/*!
	Stores x_sum for all points from 1 to n
*/	
std::vector<double> xSum; 
//Stores y_sum for all points from 1 to n
std::vector<double> ySum; 
//Stores x_square_sum for all points from 1 to n
std::vector<double> xSquareSum;
/*!
Stores xy_sum for all points from 1 to n 
*/
std::vector<double> xySum; 
void precalculate(std::vector<double> &, std::vector<double> &y, std::vector<double> &, std::vector<double> &);

double diff(int , int ,std::vector<double> & );

/*!
	Stores slope[i][j] of line for points[i-1] to points[j-1]
*/
double Slope2[100][100]; 
/*!
	Stores intercept[i][j] of line for points[i-1] to points[j-1]
*/
double Intercept2[100][100]; 
/*!
	Stores error[i][j] of line for points[i-1] to points[j-1]
*/
double Error2[101][101]; 
/*!
	Calculates Error2 for all i-j pairs
*/
void squareErrorIJ2(std::vector<Point> &); 
/*!
Stores the lowest error for points 1...j
*/
double Optimum2[101]; 
std::vector<int> pointIndex;

double SSE(std::vector<Point> &, std::vector<Line> &, double );





