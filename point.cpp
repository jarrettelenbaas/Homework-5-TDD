#include "point.hpp"

Point::Point(double xCord, double yCord)
{
    x = xCord;
    y = yCord;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}