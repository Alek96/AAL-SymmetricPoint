#include "3rd-party/catch.hpp"
#include "../brut.h"

#include "src/Data/pointData.h"

#include <iostream>

SCENARIO("Brut algorithm test")
{
	GIVEN("A RectangleData object")
	{
        RectangleData data;

        WHEN("Given some point") {
            data.pushPoint(0,0);
            data.pushPoint(1,0);
            data.pushPoint(0,2);

            THEN("Make brut object and add data by constructor") {
                Brut brut(data);
                data.initializeData();
                RectangleData newData = brut.getData();
                REQUIRE( data == newData );
            }
            THEN("Make brut object and add data by method") {
                Brut brut;
                brut.setData(data);
                data.initializeData();
                RectangleData newData = brut.getData();
                REQUIRE( data == newData );
            }
        }

        WHEN("Given some point - test 1") {
            data.pushPoint(0,0);
            THEN("Find smallest rectangle 1") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(0,0),1" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,0,1) ));
            }

            data.pushPoint(1,0);
            THEN("Find smallest rectangle 2") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(1,0),2" );
                REQUIRE(rec.isEqual( Rectangle(0,1,0,0,2) ));
            }

            data.pushPoint(0,2);
            THEN("Find smallest rectangle 3") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(2,0),2 v (0,0),(0,2),2" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,2,2) ));
            }

            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 4") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (-1,0),(0,2),3" );
                REQUIRE(rec.isEqual( Rectangle(-1,0,0,2,3) ));
            }
        }

        WHEN("Given some point - test 2")  {
            Brut brut;
            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 1") {
                brut.setData(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (-1,1),(-1,1),1" );
                REQUIRE(rec.isEqual( Rectangle(-1,-1,1,1,1) ));
            }

            data.pushPoint(0,-2);
            THEN("Find smallest rectangle 2") {
                brut.setData(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (-2,0),(-1,1),1 v (0,-2),(1,-1),1" );
                REQUIRE(rec.isEqual( Rectangle(-2,-1,0,1,1) ));
            }

            data.pushPoint(1,1);
            THEN("Find smallest rectangle 3") {
                brut.setData(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (-2,0),(1,1),2 v (0,-2),(1,1),2" );
                REQUIRE(rec.isEqual( Rectangle(-2,1,0,1,2) ));
            }
        }
    }
    GIVEN("A PointData object")
	{
        PointData data;

        WHEN("Given some point - test 1") {
            data.pushPoint(0,0);
            THEN("Find smallest rectangle 1") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(0,0),1" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,0,1) ));
            }

            data.pushPoint(1,0);
            THEN("Find smallest rectangle 2") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(1,0),2" );
                REQUIRE(rec.isEqual( Rectangle(0,1,0,0,2) ));
            }

            data.pushPoint(0,2);
            THEN("Find smallest rectangle 3") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (0,0),(2,0),2 v (0,0),(0,2),2" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,2,2) ));
            }

            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 4") {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( rec << " != (-1,0),(0,2),3" );
                REQUIRE(rec.isEqual( Rectangle(-1,0,0,2,3) ));
            }
        }
    }
}
