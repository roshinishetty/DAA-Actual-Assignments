#include"SSE.h"
#define INFINITY 10000
#define MIN 0.000001
double ans1,ans2,ans3;
#include<fstream>

//Calculates the sum of values of an attribute from indices i..j, whose cumulative sum values are stored in the sumVector
double diff(int i, int j,std::vector<double> & sumVector)
{
    return sumVector[j]-sumVector[i-1];
}


//Precalculates all sums that are used for slope and intercept calculation
void precalculate(std::vector<double> &xSum,std::vector<double> &ySum,std::vector<double> &xSquareSum,std::vector<double> &xySum)
{

    //Stores the sum of X-coordinates
    xSum.push_back(0);
    for(int i=1;i<=points.size()-1;++i)
        xSum.push_back(xSum[i-1]+points[i].get_x());

    //Stores the sum of Y-coordinates
    ySum.push_back(0);
    for(int i=1;i<=points.size()-1;++i) 
        ySum.push_back(ySum[i-1]+points[i].get_y());

    //Stores the sum of squares of the X-coordinates
    xSquareSum.push_back(0);
    for(int i=1;i<=points.size()-1;++i) 
        xSquareSum.push_back(xSquareSum[i-1]+(points[i].get_x()*points[i].get_x()));

    //Stores the sum of x*y
    xySum.push_back(0);
    for(int i=1;i<=points.size()-1;++i)
        xySum.push_back(xySum[i-1]+(points[i].get_x()*points[i].get_y()));

    //Calculates the slope of the optimal line through points i..j 
    for(int j=1;j<=points.size()-1;++j)
    {
        for(int i=1;i<j;++i){
            Slope2[i][j]=((j-i+1)*diff(i,j,xySum)-diff(i,j,xSum)*diff(i,j,ySum))/((j-i+1)*diff(i,j,xSquareSum)-diff(i,j,xSum)*diff(i,j,xSum));
        }
    }

    //Calculates the intercept of the optimal line through points i..j 
    for(int j=1;j<=points.size()-1;++j)
    {
        for(int i=1;i<j;++i) 
        {
            Intercept2[i][j]=(diff(i,j,ySum)-Slope2[i][j]*diff(i,j,xSum))/(j-i+1);
        }
    }
}

//Calculates the error value of optimal lines for the point indices i..j
 void squareErrorIJ2(std::vector<Point> &points)
{
    for(int j=0;j<101;++j) for(int i=0;i<=j;++i) Error2[i][j]=0;
    std::cout<<"Attributes "<<endl;
    for(int j=1;j<=points.size()-1;++j)
        for(int i=1;i<j;++i)
        {
            for(int k=i;k<=j;k++) 
            {    
                double sqErr=(points[k].get_y()-Slope2[i][j]*points[k].get_x()-Intercept2[i][j])*(points[k].get_y()-Slope2[i][j]*points[k].get_x()-Intercept2[i][j]);
                Error2[i][j]+=sqErr;
            }
            if(Error2[i][j]<MIN) Error2[i][j]=0;
            std::cout<<"Point_tuple(i,j) is ("<<i<<","<<j<<").  Slope is "<<Slope2[i][j]<<" Error is "<<Error2[i][j]<<"   "<<endl;
        }
}

//Runs the SSE algorithm for thr set of points, and stores the resulting lines in a vector of lines, with the error weight c
double SSE(std::vector<Point> &points, std::vector<Line> &lines, double c)
{
  
    std::sort(points.begin(),points.end(),compareX);
  
    precalculate(xSum,ySum,xSquareSum,xySum);

    squareErrorIJ2(points);
 
    //Constructs a 2-D matrix of point-indices for every j value in 1..j 
    std::vector<std::vector<int>> pointIndex;
    pointIndex.push_back({1});

    //Base case
    Optimum2[0]=0;
    
    //The value of i that gives the minimum error for a given j
    int i_min;

    //The 
    for(int j=1;j<=points.size()-1;++j)
    {    
        double min=INFINITY;
        if(j==1) i_min=0;
        else for(int i=1;i<j;++i)
        {
            // if(i==j) c=0;
            // else c=ctemp;
            if(Error2[i][j]+c+Optimum2[i-1]<min) 
            {
                min=Error2[i][j]+c+Optimum2[i-1];
                i_min=i;
            }
        }
        
        //temp stores the elements of the optimal previous index into a new vector and appends j to it
        std::vector<int> temp;
        temp.push_back(1);
		
        if(pointIndex.size()==1) ; //j==1
        else for(int i=1;i<pointIndex[i_min].size();++i )
            temp.push_back(pointIndex[i_min][i]);
        
        temp.push_back(j);
        Optimum2[j]=min; 
        pointIndex.push_back(temp);
        std::cout<<endl<<"Optimum "<<j<< "is "<<Optimum2[j];
    } 

    //Prints the point indices that shall have lines between them
	for(int i=1;i<pointIndex[points.size()-1].size();++i) 
        std::cout << pointIndex[points.size()-1][i]<<"    ";
	
    //Calculates the line equations and stores it in an array of lines
    for(int i=1;i<pointIndex[points.size()-1].size()-1;++i) 
    {
        double slope=Slope2[pointIndex[points.size()-1][i]][pointIndex[points.size()-1][i+1]];
        double intercept= Intercept2[pointIndex[points.size()-1][i]][pointIndex[points.size()-1][i+1]];
        double xs=points[pointIndex[points.size()-1][i]].get_x();
        double ys=slope*xs +intercept;
        double xe=points[pointIndex[points.size()-1][i+1]].get_x();
        double ye=slope*xe +intercept;
        Point start = Point(xs,ys);
        Point end=Point(xe,ye);
        lines.push_back(Line(slope,intercept,start,end));
    }
    std::cout<<endl<<"Optimal for weight "<<c<<"is "<< Optimum2[points.size()-1];
    return Optimum2[points.size()-1];
}
