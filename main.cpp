#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "point.hpp"
#include "line.hpp"

using namespace std;

int main()
{

    return 0;
}

TEST_CASE("Point")
{
    SECTION("Constructors")
    {
        Point p1(1.2, 3.4);
        REQUIRE(p1.getX() == 1.2);
        REQUIRE(p1.getY() == 3.4);

        Point p2(3.4, 1.2);
        REQUIRE(p2.getX() == 3.4);
        REQUIRE(p2.getY() == 1.2);

        Point p3(0, 0);
        REQUIRE(p3.getX() == 0);
        REQUIRE(p3.getY() == 0);

        Point p4(0, 6);
        REQUIRE(p4.getX() == 0);
        REQUIRE(p4.getY() == 6);

        Point p5(6, 0);
        REQUIRE(p5.getX() == 6);
        REQUIRE(p5.getY() == 0);
    }
}