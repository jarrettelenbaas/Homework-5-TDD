#pragma once

class Point
{
    public:
        Point(double xCord, double yCord);
        double getX();
        double getY();

    private:
        double x;
        double y;
}