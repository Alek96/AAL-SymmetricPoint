#include "test.h"

#include "src/Data/rectangle.h"
#include <iostream>
#include <ctime>
#include <chrono>

Test::Test()
    : _terminalOutput(false), _validation(false), _timeTest(false)
{}

void Test::reset()
{
    data = PointData();
    gen.setSeed();
    output = OutputTest();
}

void Test::readFromInput()
{
    int n, x, y;
    data = PointData();

    std::cin >> n;
    for(int i=0; i<n; ++i) {
        std::cin >> x >> y;
        data.pushPoint(x,y);
    }

    if(algo)
        algo->setData(data);
    if(validAlgo)
        validAlgo->setData(data);
}

void Test::readFromGenerator()
{
    data = gen.generateTest();

    if(algo)
        algo->setData(data);
    if(validAlgo)
        validAlgo->setData(data);
}

void Test::setAlgorithm(std::shared_ptr<BasicAlgorithm> newAlgo)
{
    algo = newAlgo;
    algo->setData(data);
}

void Test::setValidationAlgorithm(std::shared_ptr<BasicAlgorithm> newAlgo)
{
    validAlgo = newAlgo;
    validAlgo->setData(data);
}

void Test::setGenerator(Generator newGen)
{
    gen = newGen;
}

void Test::run()
{
    if(!algo)
        return;

    double time=0;

    if(_timeTest) {
        auto start = std::chrono::system_clock::now();
        lastRec = algo->solve();
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
        time = milliseconds.count();
        time/=1000;
    } else
        lastRec = algo->solve();


    if(_validation && validAlgo) {
        Rectangle validRec = validAlgo->solve();
        if(_timeTest) {
            output.addResult(validRec.isEqual(lastRec), time);
        } else {
            output.addResult(validRec.isEqual(lastRec));
        }
        if(_terminalOutput) {
            std::cout << output.getSize() << ":\t";
            if( validRec.isEqual(lastRec) ) {
                std::cout << "OK   \t";
                if(_timeTest)
                    std::cout << "time: " << time;
                std::cout << "\n";
            }
            else {
                std::cout << "WRONG\t";
                if(_timeTest)
                    std::cout << "time: " << time;
                std::cout << "\n";
                std::cout << "\t" << validRec << " " << validRec.getPerimeter() << "\n";
                std::cout << "\t" << lastRec << " " << lastRec.getPerimeter() << "\n";
                std::cout << data << "\n";
            }
        }
    } else if(_timeTest){
        output.addResult(time);
        if(_terminalOutput) {
            std::cout << output.getSize() << ":\t";
            std::cout << "time: " << time << "\n";
        }
    } else if(_terminalOutput) {
        std::cout << lastRec << "\n";
    }
}

void Test::setTerminalOutputEnable(bool terminalOutput)
{
    _terminalOutput = terminalOutput;
}
void Test::setValidationEnable(bool validation)
{
    _validation = validation;
}
void Test::setTimeTestEnable(bool timeTest)
{
    _timeTest = timeTest;
}
OutputTest Test::getOutput()
{
    output.setTimeEnable(_timeTest);
    output.setCorrectionEnable(_validation);
    return output;
}
Rectangle Test::getLastResult() const
{
    return lastRec;
}
