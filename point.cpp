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

Point::Point(){

}

void Point::setCords(double x, double y){
    X = x;
    Y = y;
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