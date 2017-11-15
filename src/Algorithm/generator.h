#ifndef GENERATOR_H
#define GENERATOR_H

#include "src/Data/pointData.h"

class Generator
{
public:
    Generator(int numberOfPoints = 0, int rangeOfNumbers = 1);

    Generator(const Generator&) = default;
	Generator(Generator&&) = default;
	Generator& operator=(const Generator&) = default;
	Generator& operator=(Generator&&) = default;

    bool operator==(const Generator&) const;
    bool operator!=(const Generator&) const;

    void setNumberOfPoints(int n);
    int getNumberOfPoints() const;
    void setRangeOfNumbers(int n);
    int getRangeOfNumbers() const;
    void setSeed(unsigned int = 0);
    PointData generateTest();
private:
    int numberOfPoints;
    int rangeOfNumbers;
};

#endif
