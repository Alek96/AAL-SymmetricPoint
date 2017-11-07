#include "3rd-party/catch.hpp"
#include "../rectangleData.h"

#include <iostream>

SCENARIO("Test for rectangleData", "[Data]")
{
	GIVEN("A rectangleData object")
	{
		RectangleData data;

		THEN("Cannot take min/max information without elements")
        {
            REQUIRE_THROWS( data.getMinX() );
            REQUIRE_THROWS( data.getMaxX() );
            REQUIRE_THROWS( data.getMinY() );
            REQUIRE_THROWS( data.getMaxY() );
        }

		WHEN("Elements are given")
		{
            for(int i=0; i<4; ++i) {
                data.pushPoint(-i,i);
            }

            THEN("Cannot take min/max information without initializing")
            {
                REQUIRE_THROWS( data.getMinX() );
                REQUIRE_THROWS( data.getMaxX() );
                REQUIRE_THROWS( data.getMinY() );
                REQUIRE_THROWS( data.getMaxY() );
            }

            THEN("Can initialize and take min/max information")
            {
                data.initializeData();

                REQUIRE_NOTHROW( data.getMinX() );
                REQUIRE_NOTHROW( data.getMaxX() );
                REQUIRE_NOTHROW( data.getMinY() );
                REQUIRE_NOTHROW( data.getMaxY() );

                REQUIRE( data.getMinX() == -3 );
                REQUIRE( data.getMaxX() == 0 );
                REQUIRE( data.getMinY() == 0 );
                REQUIRE( data.getMaxY() == 3 );
            }
		}
    }
    GIVEN("A rectangleData object with some elements")
	{
        RectangleData data;
		for(int i=0; i<4; ++i) {
            data.pushPoint(-i,i); }
        data.initializeData();

        WHEN("Change symmetrically piont")
		{
            data.changeSymmetrically(3);
			THEN("min/max is changed")
			{
				REQUIRE( data.getMinX() == -2 );
                REQUIRE( data.getMaxX() == 3 );
                REQUIRE( data.getMinY() == -3 );
                REQUIRE( data.getMaxY() == 2 );
			}

            data.changeSymmetrically(3);
            data.changeSymmetrically(2);
			THEN("min/max is changed")
			{
				REQUIRE( data.getMinX() == -3 );
                REQUIRE( data.getMaxX() == 2 );
                REQUIRE( data.getMinY() == -2 );
                REQUIRE( data.getMaxY() == 3 );
			}
        }
	}
}
