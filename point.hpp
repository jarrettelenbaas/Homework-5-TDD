#pragma once

class Point{
    public:
        Point(double xCord, double yCord);
        Point();
        void setCords(double x, double y);
        double getX();
        double getY();
        std::string printPoint();
    private:
        double X;
        double Y;
};