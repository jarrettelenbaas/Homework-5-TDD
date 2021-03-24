#include "point.hpp"


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