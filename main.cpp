// Homework 5 TDD & PP
// Jarrett E., Sam G., Nick W.

#include <iostream>
#include <cmath>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "point.hpp"
#include "line.hpp"

using namespace std;

int main(){

    Catch::Session().run();
    return 0;
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

TEST_CASE("Point"){
    SECTION("Constructors"){
        Point p1(1.2, 3.4);
        REQUIRE(p1.getX() == 1.2);
        REQUIRE(p1.getY() == 3.4);

        Point p2(3.4, 1.2);
        REQUIRE(p2.getX() == 3.4);
        REQUIRE(p2.getY() == 1.2);

        Point p3(0,0);
        REQUIRE(p3.getX() == 0);
        REQUIRE(p3.getY() == 0);

        Point p4(0,6);
        REQUIRE(p4.getX() == 0);
        REQUIRE(p4.getY() == 6);

        Point p5(6,0);
        REQUIRE(p5.getX() == 6);
        REQUIRE(p5.getY() == 0);

        Line l1(p1, p2);
        REQUIRE(l1.printLine() == "Point 1: [X: 1.2, Y: 3.4], Point 2: [X: 3.4, Y: 1.2]");

        Line l2(p2, p3);
        REQUIRE(l2.printLine() == "Point 1: [X: 3.4, Y: 1.2], Point 2: [X: 0.0, Y: 0.0]");

        Line l3(p3, p4);
        REQUIRE(l3.printLine() == "Point 1: [X: 0.0, Y: 0.0], Point 2: [X: 0.0, Y: 6.0]");

        Line l4(p4, p5);
        REQUIRE(l4.printLine() == "Point 1: [X: 0.0, Y: 6.0], Point 2: [X: 6.0, Y: 0.0]");
    }

    SECTION("Printing"){
        Point p1(1.2, 3.4);
        REQUIRE(p1.printPoint() == "X: 1.2, Y: 3.4");

        Point p2(3.4, 1.2);
        REQUIRE(p2.printPoint() == "X: 3.4, Y: 1.2");

        Point p3(0, 0);
        REQUIRE(p3.printPoint() == "X: 0.0, Y: 0.0");

        Point p4(0, 6);
        REQUIRE(p4.printPoint() == "X: 0.0, Y: 6.0");

        Point p5(6, 0);
        REQUIRE(p5.printPoint() == "X: 6.0, Y: 0.0");
    }

    SECTION("Length of Line"){
        Point p1(1.2, 3.4);
        Point p2(3.4, 1.2);
        Line l1(p1, p2);
        REQUIRE(nearEqual(l1.getLength(), 3.1, 0.1) == true);

        Point p3(0.5, 0.2);
        Point p4(0.8, 0.7);
        Line l2(p3, p4);
        REQUIRE(nearEqual(l2.getLength(), 0.6, 0.1) == true);
    }

    SECTION("Is it Parallel"){
        Point p1(1.2, 3.4);
        Point p2(3.4, 1.2);
        Line l1(p1, p2);
        Point p3(0.5, 0.2);
        Point p4(0.8, 0.7);
        Line l2(p3, p4);

        REQUIRE(l1.isParallel(l2) == false);

        Point p5(1, 2);
        Point p6(2, 4);
        Line l3(p5, p6);
        Point p7(3, 5);
        Point p8(5, 9);
        Line l4(p7, p8);

        REQUIRE(l3.isParallel(l4) == true);

        Point p9(0, 0);
        Point p10(0, 6);
        Line l5(p9, p10);
        Point p11(3, 0);
        Point p12(3, 6);
        Line l6(p11, p12);

        REQUIRE(l5.isParallel(l6) == true);
    }

    SECTION("Is on Line"){
        Point p1(1.2, 3.4);
        Point p2(3.4, 1.2);
        Line l1(p1, p2);
        Point p3(5.6, 5.6);

        REQUIRE(l1.isOnLine(p3) == false);

        Point p4(0.0, 0.0);
        Point p5(6.0, 0.0);
        Line l2(p4, p5);
        Point p6(3.0, 0.0);
        Point p7(5.0, 0.0);

        REQUIRE(l2.isOnLine(p6) == true);
        REQUIRE(l2.isOnLine(p7) == true);
    }

    SECTION("Do Lines cross"){
        Point p1(1.2, 3.4);
        Point p2(3.4, 1.2);
        Line l1(p1, p2);
        Point p3(0.5, 0.2);
        Point p4(0.8, 0.7);
        Line l2(p3, p4);

        REQUIRE(l1.isCrossing(l2) == false);

        Point p5(4.0, 0.0);
        Point p6(4.0, 8.0);
        Line l3(p5, p6);
        Point p7(0.0, 4.0);
        Point p8(8.0, 4.0);
        Line l4(p7, p8);

        REQUIRE(l3.isCrossing(l4) == true);
    }
}