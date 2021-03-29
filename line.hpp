#pragma once
#include "point.hpp"

class Line{
    public:
        Line(Point point1, Point point2);
        std::string printLine();
        double getLength();
        bool isParallel(Line l2);
        bool isOnLine(Point point);
        bool isCrossing(Line l2);
    private:
        Point p1;
        Point p2;
};