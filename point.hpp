#pragma once

class Point{
    public:
        Point(double xCord, double yCord);
        double getX();
        double getY();
        std::string printPoint();
        bool nearEqual(double num1, double num2, double acceptableDelta);
    private:
        double X;
        double Y;
};