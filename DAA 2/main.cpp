//#include "stdafx.h"
#include<iostream>
#include"preprocess.h" 




int main()
{

    //Total number of points in file excluding the dummy (0,0)
    int n_pts=inputFromFile(points); 
    std::cout<<"Enter three parsimonial weights"<<endl; 
    
    //The constant weight p in the Error function E+pL
    double p1, p2, p3; 

    std::cin>>p1>>p2>>p3;

    //Stores the optimal lines in vector<Line> lines
    ans1=SSE(points,lines1,p1); 
    
    ans2=SSE(points,lines2,p2); 
    
    ans3=SSE(points,lines3,p3); 
    
    outputToConsole(lines1); 
    std::cout<<ans1<<endl;

    outputToConsole(lines2);
    std::cout<<ans2<<endl;

    outputToConsole(lines3);
    std::cout<<ans3<<endl;
    
    std::string o1="output1.csv";
    std::string o2="output2.csv";
    std::string o3="output3.csv";

	outputToFile(lines1,o1);
    outputToFile(lines2,o2);
    outputToFile(lines3,o3);
    
    return 0;
}
