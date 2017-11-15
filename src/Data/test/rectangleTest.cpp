#include "3rd-party/catch.hpp"
#include "../rectangle.h"

SCENARIO("Rectangle test")
{
	GIVEN("A object")
	{
        Rectangle rec(1,2,3,4,5);

		THEN("Elements in object are correct") {
            REQUIRE(rec.getMinX() == 1);
            REQUIRE(rec.getMaxX() == 2);
            REQUIRE(rec.getMinY() == 3);
            REQUIRE(rec.getMaxY() == 4);

            REQUIRE(rec.getPerimeter() == 4);

            REQUIRE(rec.getOrginalPoints() == 5);
		}
    }
    GIVEN("Two objects")
	{
        THEN("1 object is the same that 2") {
            REQUIRE( Rectangle(1,1,1,1,1) == Rectangle(1,1,1,1,1) );
            REQUIRE( Rectangle(1,2,3,4,5) == Rectangle(1,2,3,4,5) );

            REQUIRE_FALSE( Rectangle(1,2,3,4,5) == Rectangle(0,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(0,2,3,4,5) == Rectangle(1,2,3,4,5) );
		}
        THEN("1 object is different that 2") {
            REQUIRE( Rectangle(1,2,3,4,5) != Rectangle(0,2,3,4,5) );
            REQUIRE( Rectangle(0,2,3,4,5) != Rectangle(1,2,3,4,5) );

            REQUIRE_FALSE( Rectangle(1,1,1,1,1) != Rectangle(1,1,1,1,1) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) != Rectangle(1,2,3,4,5) );
		}
		THEN("1 object is smaller that 2") {
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(0,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(1,3,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(1,2,2,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(1,2,3,5,5) );
            REQUIRE( Rectangle(1,2,3,4,5) < Rectangle(1,2,3,4,4) );

            REQUIRE_FALSE( Rectangle(1,2,3,4,5) < Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(0,2,3,4,5) < Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,3,3,4,5) < Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,2,4,5) < Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,5,5) < Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,4) < Rectangle(1,2,3,4,5) );
		}
		THEN("1 object is greater that 2") {
            REQUIRE( Rectangle(0,2,3,4,5) > Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,3,3,4,5) > Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,2,4,5) > Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,5,5) > Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,4) > Rectangle(1,2,3,4,5) );

            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(0,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(1,3,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(1,2,2,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(1,2,3,5,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) > Rectangle(1,2,3,4,4) );
		}
		THEN("1 object is smaller or equal that 2") {
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(0,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(1,3,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(1,2,2,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(1,2,3,5,5) );
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(1,2,3,4,4) );
            REQUIRE( Rectangle(1,2,3,4,5) <= Rectangle(1,2,3,4,5) );

            REQUIRE_FALSE( Rectangle(0,2,3,4,5) <= Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,3,3,4,5) <= Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,2,4,5) <= Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,5,5) <= Rectangle(1,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,4) <= Rectangle(1,2,3,4,5) );
		}
		THEN("1 object is greater or equal  that 2") {
            REQUIRE( Rectangle(0,2,3,4,5) >= Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,3,3,4,5) >= Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,2,4,5) >= Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,5,5) >= Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,4) >= Rectangle(1,2,3,4,5) );
            REQUIRE( Rectangle(1,2,3,4,5) >= Rectangle(1,2,3,4,5) );

            REQUIRE_FALSE( Rectangle(1,2,3,4,5) >= Rectangle(0,2,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) >= Rectangle(1,3,3,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) >= Rectangle(1,2,2,4,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) >= Rectangle(1,2,3,5,5) );
            REQUIRE_FALSE( Rectangle(1,2,3,4,5) >= Rectangle(1,2,3,4,4) );
		}

		THEN("1 object is equal with 2") {
            Rectangle rec(1,2,3,4,5);
            REQUIRE( rec.isEqual( Rectangle(2,3,4,5,5) ));
		}
    }
    GIVEN("A object")
	{
        Rectangle rect(1,2,3,4,5);

        THEN("Copy the object by constructor") {
            Rectangle copyRect(rect);
            REQUIRE( rect == copyRect );
        }
        THEN("Copy the object by operator =") {
            Rectangle copyRect = rect;
            REQUIRE( rect == copyRect );
        }
    }
}


























