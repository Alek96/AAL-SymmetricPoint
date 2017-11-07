#include "3rd-party/catch.hpp"
#include "../brut.h"

#include <iostream>

SCENARIO("Test for brut algorithm", "[Data]")
{
	GIVEN("A rectangleData object")
	{
        RectangleData data;

        WHEN("Given some point 1")
        {
            data.pushPoint(0,0);
            THEN("Find smallest rectangle 1")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (0,0),(0,0),0" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,0,0) ));
            }

            data.pushPoint(1,0);
            THEN("Find smallest rectangle 2")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (0,0),(1,0),0" );
                REQUIRE(rec.isEqual( Rectangle(0,1,0,0,0) ));
            }

            data.pushPoint(0,2);
            THEN("Find smallest rectangle 3")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (0,0),(2,0),1 v (0,0),(0,2),1" );
                REQUIRE(rec.isEqual( Rectangle(0,0,0,2,1) ));
            }

            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 4")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (-1,0),(0,2),1" );
                REQUIRE(rec.isEqual( Rectangle(-1,0,0,2,1) ));
            }
        }

        WHEN("Given some point 2")
        {
            data.pushPoint(-1,1);
            THEN("Find smallest rectangle 1")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (-1,1),(-1,1),0" );
                REQUIRE(rec.isEqual( Rectangle(-1,-1,1,1,0) ));
            }

            data.pushPoint(0,-2);
            THEN("Find smallest rectangle 2")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (-2,0),(-1,1),1 v (0,-2),(1,-1),1" );
                REQUIRE(rec.isEqual( Rectangle(-2,-1,0,1,1) ));
            }

            data.pushPoint(1,1);
            THEN("Find smallest rectangle 3")
            {
                Brut brut(data);
                Rectangle rec = brut.solve();

                INFO( "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")," << rec.getNumberOfSymmetricePoint() << " != (-2,0),(1,1),1 v (0,-2),(1,1),1" );
                REQUIRE(rec.isEqual( Rectangle(-2,1,0,1,1) ));
            }
        }
    }
}


























