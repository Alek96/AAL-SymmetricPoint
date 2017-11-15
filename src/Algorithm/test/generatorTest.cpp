#include "3rd-party/catch.hpp"
#include "../generator.h"

#include <iostream>

SCENARIO("Generator algorithm Test")
{
	GIVEN("A object")
	{
        Generator gen;
        THEN("Set number of points") {
            gen.setNumberOfPoints(10);
            REQUIRE( gen.getNumberOfPoints() == 10 );
		}
		THEN("Set range of generate numbers") {
            gen.setRangeOfNumbers(20);
            REQUIRE( gen.getRangeOfNumbers() == 20 );
		}
		WHEN("Generating test") {
            gen.setNumberOfPoints(20);
            gen.setRangeOfNumbers(10);
            PointData data(gen.generateTest());
            THEN("Test is correct") {
                REQUIRE( data.getSize() == 20 );
                for(int i=0; i<data.getSize(); ++i) {
                    REQUIRE( -10 < data.getPoint(i).first );
                    REQUIRE( -10 < data.getPoint(i).second );
                    REQUIRE( data.getPoint(i).first < 10 );
                    REQUIRE( data.getPoint(i).second < 10 );
                }
            }
		}
		WHEN("Set identical seed") {
            gen.setSeed(10); auto data1 = gen.generateTest();
            gen.setSeed(10); auto data2 = gen.generateTest();
            THEN("Generate the same obj") {
                REQUIRE( data1 == data1 );
            }
        }
        WHEN("Set different seed") {
            gen.setSeed(10); auto data1 = gen.generateTest();
            gen.setSeed(11); auto data2 = gen.generateTest();
            THEN("Generate the same obj") {
                REQUIRE( data1 == data1 );
            }
        }
    }
    GIVEN("Two object with some parametrs")
	{
        Generator gen1(10, 20);
        Generator gen2(10, 20);

        THEN("First obj == second obj") {
            REQUIRE( gen1 == gen2 );
            REQUIRE_FALSE( gen1 != gen2 );
        }
        THEN("First obj != second obj") {
            gen1.setNumberOfPoints(5);
            REQUIRE_FALSE( gen1 == gen2 );
            REQUIRE( gen1 != gen2 );
        }
        THEN("First obj != second obj") {
            gen1.setRangeOfNumbers(5);
            REQUIRE_FALSE( gen1 == gen2 );
            REQUIRE( gen1 != gen2 );
        }
	}
    GIVEN("A object with some parametrs")
	{
        Generator gen(10, 20);
        THEN("Number of points and range of generate number are correct") {
            REQUIRE( gen.getNumberOfPoints() == 10 );
            REQUIRE( gen.getRangeOfNumbers() == 20 );
		}

		THEN("Copy the object by constructor") {
            Generator copyGen(gen);
            REQUIRE( gen == copyGen );
        }
        THEN("Copy the object by operator =") {
            Generator copyGen = gen;
            REQUIRE( gen == copyGen );
        }
	}
}


























