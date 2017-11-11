#include "test.h"

#include "src/Data/rectangle.h"
#include <iostream>

Test::Test()
{}

void Test::reset()
{
    data = PointData();
}

void Test::readFromInput()
{
    int n, x, y;
    reset();

    std::cin >> n;
    for(int i=0; i<n; ++i) {
        std::cin >> x >> y;
        data.pushPoint(x,y);
    }

    if(algo)
        algo->setData(data);
    if(validAlgo)
        validAlgo->setData(data);
    //std::cout << data << "\n";
}

void Test::readFromGenerator()
{
    reset();
    data = gen.generateTest();

    if(algo)
        algo->setData(data);
    if(validAlgo)
        validAlgo->setData(data);
    //std::cout << data << "\n";
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
    if(algo) {
        Rectangle rec = algo->solve();
        std::cout << rec << "\n";
    }
}

void Test::runWithValidation()
{
    if(algo && validAlgo) {
        Rectangle rec = algo->solve();
        Rectangle validRec = validAlgo->solve();
        if( validRec.isEqual(rec) ) {
            //std::cout << "OK\n";
        }
        else {
            std::cout << "Error\n";
            std::cout << "\t" << validRec << " " << validRec.getPerimeter() << "\n";
            std::cout << "\t" << rec << " " << rec.getPerimeter() << "\n";
            std::cout << data << "\n";
        }
    }
}
