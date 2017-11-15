#include "3rd-party/catch.hpp"
#include "../rectangleData.h"

SCENARIO("RectangleData test")
{
	GIVEN("A object") {
		RectangleData data;

		THEN("Cannot take min/max information without elements") {
            REQUIRE_THROWS( data.getMinX() );
            REQUIRE_THROWS( data.getMaxX() );
            REQUIRE_THROWS( data.getMinY() );
            REQUIRE_THROWS( data.getMaxY() );
        }

		WHEN("Elements are given") {
            for(int i=0; i<4; ++i) {
                data.pushPoint(-i,i);
            }

            THEN("Cannot take min/max information without initializing") {
                REQUIRE_THROWS( data.getMinX() );
                REQUIRE_THROWS( data.getMaxX() );
                REQUIRE_THROWS( data.getMinY() );
                REQUIRE_THROWS( data.getMaxY() );
            }

            THEN("Can initialize and take min/max information") {
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
    GIVEN("A object with some elements") {
        RectangleData data;
		for(int i=0; i<4; ++i) {
            data.pushPoint(-i,i);
        }
        data.initializeData();

        WHEN("Change symmetrically piont") {
            data.changeSymmetrically(3);
			THEN("min/max is changed") {
				REQUIRE( data.getMinX() == -2 );
                REQUIRE( data.getMaxX() == 3 );
                REQUIRE( data.getMinY() == -3 );
                REQUIRE( data.getMaxY() == 2 );
			}

            data.changeSymmetrically(3);
            data.changeSymmetrically(2);
			THEN("min/max is changed") {
				REQUIRE( data.getMinX() == -3 );
                REQUIRE( data.getMaxX() == 2 );
                REQUIRE( data.getMinY() == -2 );
                REQUIRE( data.getMaxY() == 3 );
			}
        }
	}
    GIVEN("Two object with some elements") {
        RectangleData data1;
        RectangleData data2;
		for(int i=0; i<4; ++i) {
            data1.pushPoint(-i,i);
            data2.pushPoint(-i,i);
        }
        data1.initializeData();
        data2.initializeData();

        THEN("First obj == second obj") {
            REQUIRE( data1 == data2 );
            REQUIRE_FALSE( data1 != data2 );
        }

        data1.changeSymmetrically(1);
        data2.changeSymmetrically(1);
        THEN("First obj == second obj") {
            REQUIRE( data1 == data2 );
            REQUIRE_FALSE( data1 != data2 );
        }

        data1.changeSymmetrically(1);
        THEN("First obj != second obj") {
            REQUIRE_FALSE( data1 == data2 );
            REQUIRE( data1 != data2 );
        }
    }
    GIVEN("A object with some elements") {
        RectangleData data;
		for(int i=0; i<4; ++i) {
            data.pushPoint(-i,i);
        }
        data.initializeData();

        THEN("Copy the object by constructor") {
            RectangleData copyData(data);
            REQUIRE( data == copyData );
        }
		THEN("Move the object by constructor") {
            RectangleData copyData(data);
            RectangleData moveData(std::move(data));
            REQUIRE( moveData == copyData );
            REQUIRE( data == RectangleData() );

            RectangleData moveData2(std::move(data));
            REQUIRE( moveData2 == RectangleData() );
        }
        THEN("Copy the object by operator =") {
            RectangleData copyData = data;
            REQUIRE( data == copyData );
        }
        THEN("Move the object by operator =") {
            RectangleData copyData = data;
            RectangleData moveData = std::move(data);
            REQUIRE( moveData == copyData );
            REQUIRE( data == RectangleData() );

            moveData = std::move(data);
            REQUIRE( moveData == RectangleData() );
        }
    }
}
