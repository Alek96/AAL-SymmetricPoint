#include "3rd-party/cxxopts.hpp"
#include "Data/rectangle.h"
#include "Algorithm/heurystyka.h"
#include "Algorithm/brut.h"
#include "Algorithm/generator.h"
#include "Test/test.h"

#include <iostream>
#include <string>

#define NOCOUNT_C

int main(int argc, char* argv[])
{
    int points=0,range=0,tests=0,increment=0,step=0;
    bool verify=false, output=false, time=false;
    double c=0.0018;
    #ifdef COUNT_C
        double cc=0;
    #endif // COUNT_C

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
        if(time)
            std::cout << "  Agorithm with asymptote O(T(n))" << std::endl
                      << "n\t\tt(n)[ms]\tc" << std::endl;

        for(int i=0; i<step; ++i) {
            test.setGenerator(Generator(points,range));
            for(int j=0; j<tests; ++j) {
                test.readFromGenerator();
                test.run();
            }
            if(time) {
                #ifdef COUNT_C
                    cc+= test.getOutput().getArithmeticAverageTime() / points;
                #endif // COUNT_C

                std::cout << points << "\t\t"
                          << test.getOutput().getArithmeticAverageTime() << "\t\t"
                          << test.getOutput().getArithmeticAverageTime() / (c * points)
                          #ifdef COUNT_C
                            << "   \t" << cc / (i+1)
                          #endif // COUNT_C
                          << std::endl;
            }
            points+= increment;
            test.reset();
        }
    }

	return 0;
}
