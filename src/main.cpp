#include <iostream>
#include <string>

#include "Data/rectangle.h"
#include "Data/pointData.h"
#include "Data/rectangleData.h"
#include "Algorithm/heurystyka.h"
#include "Algorithm/brut.h"
#include "Algorithm/generator.h"
#include "Test/test.h"

int main(int argc, char** argv)
{
    Test test;
    if(argc == 2 && std::string(argv[1]) == "-h" ) {
        std::cout << "Options: \n"
                << "\t-m1\t\t- get data from standart input\n"
                << "\t-m2 -n10 -m20\t- generate data and run test \n\t\t\t(n - how many points, m - there range)\n"
                << "\t-m3 -n10 -m20 -k30 -step5 -r10\t- ...\n";
	} else if(argc == 2 && std::string(argv[1]) == "-m1" ) {
        test.readFromInput();
        test.setAlgorithm(std::make_shared<Heurystyka>());
        test.run();
	} else if(argc == 2 && std::string(argv[1]) == "-m3") {
        test.setGenerator(Generator(5,5));
        test.setAlgorithm(std::make_shared<Heurystyka>());
        test.setValidationAlgorithm(std::make_shared<Brut>());

        for(int i=0; i<100; ++i) {
            //std::cout << i << ":\n";
            test.readFromGenerator();
            test.runWithValidation();
        }
	} else {
        std::cout << "Bad argument/s. Check -h for more informations\n";
        std::cout << "arg: ";
        for(int i=0; i<argc; ++i)
            std::cout << argv[i] << " ";
        std::cout << "\n";
	}
	return 0;
}
