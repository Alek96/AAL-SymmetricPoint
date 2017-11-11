#ifndef TEST_H
#define TEST_H

#include "src/Algorithm/basicAlgorithm.h"
#include "src/Data/pointData.h"
#include "src/Algorithm/generator.h"

#include <functional>
#include <memory>

class Test
{
public:
    Test();
    void reset();
    void readFromInput();
    void readFromGenerator();
    void setAlgorithm(std::shared_ptr<BasicAlgorithm>);
    void setValidationAlgorithm(std::shared_ptr<BasicAlgorithm>);
    void setGenerator(Generator);
    void run();
    void runWithValidation();

private:
    PointData data;
    std::shared_ptr<BasicAlgorithm> algo;
    std::shared_ptr<BasicAlgorithm> validAlgo;
    Generator gen;
};

#endif
