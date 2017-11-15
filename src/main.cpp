#include <iostream>
#include <string>

#include "Data/rectangle.h"
#include "Data/pointData.h"
#include "Data/rectangleData.h"
#include "Algorithm/heurystyka.h"
#include "Algorithm/brut.h"
#include "Algorithm/generator.h"
#include "Test/test.h"
#include "3rd-party/cxxopts.hpp"

int main(int argc, char* argv[])
{
    int points=0,range=0,tests=0,increment=0,step=0;
    bool verify=false, output=false, time=false;

    try
    {
    cxxopts::Options options(argv[0], "Test for algorithm");
    options.add_options()
        ("h,help", "Print help")
        ("p,points", "Number of generated points per test.", cxxopts::value<int>(points))
        ("r,range", "Range of generated points.", cxxopts::value<int>(range))
        ("t,tests", "Number of tests. If the number of steps (-s,--step) is given, this is the number of tests per step.", cxxopts::value<int>(tests)
            ->default_value("1"))
        ("i,increment", "Number of incremented generated points for tests per step. After finising euch step will be printed arithmetic average of tests execution time if 'time' is enable.", cxxopts::value<int>(increment)
            ->implicit_value("1000"))
        ("s,step", "Number of steps.", cxxopts::value<int>(step)
            ->implicit_value("1"))
        ("v,verify", "Verifying the correctness of the test result. 'points' cannot increase 20. (default: false)", cxxopts::value<bool>(verify))
        ("o,output", "Show result on terminal during tests. (default: false)", cxxopts::value<bool>(output))
        ("c,time", "Test with execution time. (default: false)", cxxopts::value<bool>(time))
    ;
    options.parse(argc, argv);

    if (options.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if( increment && !step || !increment && step ) {
        std::cout << "You need to specified 'increment' and 'step'" << std::endl;
        return 0;
    } else if( points && !range || !points && range ) {
        std::cout << "You need to specified 'points' and 'range'" << std::endl;
        return 0;
    }

    } catch (const cxxopts::OptionException& e) {
        std::cout << "error parsing options: " << e.what() << std::endl;
        return 1;
    }
    //std::cout << points << " " << range << " " << tests << " " << increment << " " << step << "\n";
    //std::cout << verify << " " << output << " " << time << "\n";

    Test test;
    test.setAlgorithm(std::make_shared<Heurystyka>());
    if(verify) {
        test.setValidationAlgorithm(std::make_shared<Brut>());
        test.setValidationEnable(true);
    }
    if(output)
        test.setTerminalOutputEnable(true);
    if(time)
        test.setTimeTestEnable(true);
    if(!step)
        ++step;

    if(!points) {
        test.readFromInput();
        test.run();
        std::cout << test.getLastResult() << "\n";
    } else {
        for(int i=0; i<step; ++i) {
            test.setGenerator(Generator(points,range));
            for(int j=0; j<tests; ++j) {
                test.readFromGenerator();
                test.run();
            }
            if(time)
                std::cout << "Arithmetic average of times for " << points
                          << " is " << test.getOutput().getArithmeticAverageTime() << "s" << std::endl;
            points+= increment;
            test.reset();
        }
    }

	return 0;
}
