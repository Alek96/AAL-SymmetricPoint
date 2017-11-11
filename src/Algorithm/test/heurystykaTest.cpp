#include "3rd-party/catch.hpp"
#include "../heurystyka.h"

#include <iostream>

SCENARIO("Test for Heurystyka algorithm", "[Algorithm]")
{
	GIVEN("A Heurystyka object")
	{
        PointData data;

        WHEN("Given some point") {
            data.pushPoint(0,0);
            data.pushPoint(1,0);
            data.pushPoint(0,2);

            THEN("Make brut object and add data by constructor") {
                Heurystyka heurystyka(data);
                PointData newData = heurystyka.getData();
                REQUIRE( data == newData );
            }
            THEN("Make brut object and add data by method") {
                Heurystyka heurystyka;
                heurystyka.setData(data);
                PointData newData = heurystyka.getData();
                REQUIRE( data == newData );
            }
        }

        WHEN("Given some point 1")
        {
            data.pushPoint(0,0);
            THEN("Find smallest rectangle 1") {
                Heurystyka heurystyka(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (0,0),(0,0),1" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,0,1) ));
            }

            data.pushPoint(1,0);
            THEN("Find smallest rectangle 2") {
                Heurystyka heurystyka(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (0,0),(1,0),2" );
                REQUIRE(rec.isEqual( Rectangle(0,1,0,0,2) ));
            }

            data.pushPoint(0,2);
            THEN("Find smallest rectangle 3") {
                Heurystyka heurystyka(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (0,0),(2,0),2 v (0,0),(0,2),2" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,2,2) ));
            }

            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 4")
            {
                Heurystyka heurystyka(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (-1,0),(0,2),3" );
                REQUIRE(rec.isEqual( Rectangle(-1,0,0,2,3) ));
            }
        }

        WHEN("Given some point 2")
        {
            Heurystyka heurystyka;
            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 1") {
                heurystyka.setData(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (-1,1),(-1,1),1" );
                REQUIRE(rec.isEqual( Rectangle(-1,-1,1,1,1) ));
            }

            data.pushPoint(0,-2);
            THEN("Find smallest rectangle 2") {
                heurystyka.setData(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (-2,0),(-1,1),1 v (0,-2),(1,-1),1" );
                REQUIRE(rec.isEqual( Rectangle(-2,-1,0,1,1) ));
            }

            data.pushPoint(1,1);
            THEN("Find smallest rectangle 3") {
                heurystyka.setData(data);
                Rectangle rec = heurystyka.solve();

                INFO( rec << " != (-2,0),(1,1),2 v (0,-2),(1,1),2" );
                REQUIRE(rec.isEqual( Rectangle(-2,1,0,1,2) ));
            }
        }
    }
}
