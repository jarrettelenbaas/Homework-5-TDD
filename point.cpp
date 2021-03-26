#include <cmath>
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "point.hpp"

using namespace std;

Point::Point(double xCord, double yCord){
    X = xCord;
    Y = yCord;
}

double Point::getX(){
    return X;
}

double Point::getY(){
    return Y;
}

string Point::printPoint(){
    stringstream xstream;
    stringstream ystream;
    xstream << fixed << setprecision(1) << X;
    ystream << fixed << setprecision(1) << Y;
    return "X: " + xstream.str() + ", Y: " + ystream.str();
}

bool nearEqual(double num1, double num2, double acceptableDelta)
{
    bool retVal = false;
    //find the difference between the two numbers
    double diff = num1 - num2;
    //if the absolute value between the difference is smaller than the acceptable allowed difference then it is close enough
    if(fabs(diff) <= acceptableDelta)
    {
        retVal = true;
    }
    return retVal;
}