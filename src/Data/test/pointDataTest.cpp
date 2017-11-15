#include "3rd-party/catch.hpp"
#include "../pointData.h"

SCENARIO("PointData test")
{
	GIVEN("A object with some items")
	{
		PointData data;
		for(int i=0; i<4; ++i)
            data.pushPoint(-i,i);

        THEN("Object has the some number of items") {
            REQUIRE( data.getSize() == 4 );
        }
        THEN("Object has the some items") {
			for(int i=0; i<4; ++i) {
                REQUIRE( data.getPoint(i) == std::make_pair(-i,i) );
            }
            data.pushPoint(10,20);
            REQUIRE( data.getPoint(4) == std::make_pair(10,20) );
        }
        THEN("Object return corrrect rectangle") {
            REQUIRE( data.getRectangle() == Rectangle(-3, 0, 0, 3, 4) );
        }
        THEN("Change symmetrically pionts") {
            REQUIRE( data.getOrginalPoints() == 4 );

            data.changeSymmetrically(1);
            REQUIRE_FALSE( data.isOrginal(1) );
            REQUIRE( data.getOrginalPoints() == 3 );
            INFO( "(" << data.getPoint(1).first << "," << data.getPoint(1).second << ") != (1,-1)" );
            REQUIRE( data.getPoint(1) == std::make_pair(1,-1) );

            data.changeSymmetrically(2);
            REQUIRE_FALSE( data.isOrginal(2) );
            REQUIRE( data.getOrginalPoints() == 2 );
            INFO( "(" << data.getPoint(2).first << "," << data.getPoint(2).second << ") != (2,-2)" );
            REQUIRE( data.getPoint(2) == std::make_pair(2,-2) );

            data.changeSymmetrically(3);
            REQUIRE_FALSE( data.isOrginal(3) );
            REQUIRE( data.getOrginalPoints() == 1 );
            INFO( "(" << data.getPoint(3).first << "," << data.getPoint(3).second << ") != (3,-3)" );
            REQUIRE( data.getPoint(3) == std::make_pair(3,-3) );

            data.changeSymmetrically(0);
            REQUIRE( data.isOrginal(0) );
            REQUIRE( data.getOrginalPoints() == 1 );
            INFO( "(" << data.getPoint(0).first << "," << data.getPoint(0).second << ") != (0,0)" );
            REQUIRE( data.getPoint(0) == std::make_pair(0,0) );


            data.changeSymmetrically(1);
            REQUIRE( data.isOrginal(1) );
            REQUIRE( data.getOrginalPoints() == 2 );
            REQUIRE( data.getPoint(1) == std::make_pair(-1,1) );

            data.changeSymmetrically(2);
            REQUIRE( data.isOrginal(2) );
            REQUIRE( data.getOrginalPoints() == 3 );
            REQUIRE( data.getPoint(2) == std::make_pair(-2,2) );
		}
    }
    GIVEN("Two object with some items")
	{
        PointData data1;
        PointData data2;
        for(int i=0; i<4; ++i) {
            data1.pushPoint(-i,i);
            data2.pushPoint(-i,i);
        }
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

        data1.changeSymmetrically(2);
        THEN("First obj != second obj") {
            REQUIRE_FALSE( data1 == data2 );
            REQUIRE( data1 != data2 );
        }

        data1.changeSymmetrically(2);
        data1.pushPoint(-4,4);
        THEN("First obj != second obj") {
            REQUIRE_FALSE( data1 == data2 );
            REQUIRE( data1 != data2 );
        }
	}
    GIVEN("A object with some items")
	{
        PointData data;
		for(int i=0; i<4; ++i)
            data.pushPoint(-i,i);
        data.changeSymmetrically(1);

		THEN("Copy the object by constructor") {
            PointData copyData(data);
            REQUIRE( data == copyData );
        }
		THEN("Move the object by constructor") {
            PointData copyData(data);
            PointData moveData(std::move(data));
            REQUIRE( moveData == copyData );
            REQUIRE( data == PointData() );

            PointData moveData2(std::move(data));
            REQUIRE( moveData2 == PointData() );
        }
        THEN("Copy the object by operator =") {
            PointData copyData = data;
            REQUIRE( data == copyData );
        }
        THEN("Move the object by operator =") {
            PointData copyData = data;
            PointData moveData = std::move(data);
            REQUIRE( moveData == copyData );
            REQUIRE( data == PointData() );

            moveData = std::move(data);
            REQUIRE( moveData == PointData() );
        }
	}
}
