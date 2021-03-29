#include <cmath>
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "line.hpp"

using namespace std;

Line::Line(Point point1, Point point2){
    p1 = point1;
    p2 = point2;
}

string Line::printLine(){
    return "Point 1: [" + p1.printPoint() + "], Point 2: [" + p2.printPoint() + "]";
}

double Line::getLength(){
    double b = p2.getY() - p1.getY();
    double a = p2.getX() - p1.getX();

    double c = sqrt((pow(a, 2)) + (pow(b, 2)));
    return c;
}

bool Line::isParallel(Line l2){

    double slope1 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    double slope2 = (l2.p2.getY() - l2.p1.getY()) / (l2.p2.getX() - l2.p1.getX());

    return slope1 == slope2;
}

bool Line::isOnLine(Point point){
    Line l1(p1, point);
    Line l2(p2, point);

    double totalLength = l1.getLength() + l2.getLength();

    return getLength() == totalLength;
}

bool Line::isCrossing(Line l2){
    
}


