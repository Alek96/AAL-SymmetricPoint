#include "3rd-party/catch.hpp"
#include "../rectangle.h"

#include <iostream>

SCENARIO("Test for rectangle", "[Data]")
{
	GIVEN("A rectangleData object")
	{
        Rectangle rect(1,2,3,4,5);

		THEN("Elements are equal")
		{
            REQUIRE(rect.getLeftX() == 1);
            REQUIRE(rect.getRightX() == 2);
            REQUIRE(rect.getLeftY() == 3);
            REQUIRE(rect.getRightY() == 4);

            REQUIRE(rect.getPerimeter() == 4);

            REQUIRE(rect.getNumberOfSymmetricePoint() == 5);
		}
    }
    GIVEN("Two rectangleData objects")
	{
		THEN("1 object is smaller that 2")
		{
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(0,2,3,4,5) );
		}
		THEN("2 object is smaller that 1")
		{
            REQUIRE( Rectangle(0,2,3,4,5) > Rectangle(1,2,3,4,5) );
		}
		THEN("1 object is smaller that 2")
		{
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(1,2,3,4,6) );
		}
		THEN("1 object is the same that 2")
		{
            REQUIRE( Rectangle(1,2,3,4,5) == Rectangle(1,2,3,4,5) );
		}
		THEN("1 object is equal with 2")
		{
            Rectangle rec = Rectangle(1,2,3,4,5);
            REQUIRE( rec.isEqual( Rectangle(2,3,4,5,5) ));
		}
    }
}


























