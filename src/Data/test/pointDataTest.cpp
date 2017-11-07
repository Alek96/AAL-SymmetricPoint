#include "3rd-party/catch.hpp"
#include "../pointData.h"

#include <iostream>

SCENARIO("Test for pointData", "[Data]")
{
	GIVEN("A pointData object with some items")
	{
		PointData data;

		for(int i=0; i<4; ++i) {
            data.pushPoint(-i,i);
        }

        THEN("pointData object has the some number of items")
		{
            REQUIRE( data.getSize() == 4 );
        }

        THEN("pointData object has the some items")
		{
            for(int i=0; i<4; ++i) {
                REQUIRE( data.getPoint(i) == std::make_pair(-i,i) );
            }
        }

		WHEN("Change symmetrically piont")
		{
            REQUIRE( data.getNumberOfSymmetricePoint() == 0 );
            data.changeSymmetrically(1);
            REQUIRE( data.getNumberOfSymmetricePoint() == 1 );

			THEN("point is changed symmetrically")
			{
				INFO( "(" << data.getPoint(1).first << "," << data.getPoint(1).second << ") != (1,-1)" );
				REQUIRE( data.getPoint(1) == std::make_pair(1,-1) );
			}
			THEN("Change symmetrically piont again")
			{
				data.changeSymmetrically(1);
                REQUIRE( data.getNumberOfSymmetricePoint() == 0 );
			}
        }
	}
}
