#include "generator.h"

#include <cstdlib>

Generator::Generator(int numberOfPoints, int rangeOfNumbers)
    : numberOfPoints(numberOfPoints), rangeOfNumbers(rangeOfNumbers)
{}

bool Generator::operator==(const Generator& gen) const
{
    return numberOfPoints == gen.numberOfPoints
        && rangeOfNumbers == gen.rangeOfNumbers;
}
bool Generator::operator!=(const Generator& gen) const
{
    return !(*this == gen);
}

void Generator::setNumberOfPoints(int n)
{
    numberOfPoints = n;
}

int Generator::getNumberOfPoints() const
{
    return numberOfPoints;
}

void Generator::setRangeOfNumbers(int n)
{
    rangeOfNumbers = n;
}

int Generator::getRangeOfNumbers() const
{
    return rangeOfNumbers;
}

PointData Generator::generateTest()
{
    PointData data;
    for(int i = 0; i< getNumberOfPoints(); ++i) {
        data.pushPoint(
            std::rand()%(2*getRangeOfNumbers() - 1) - getRangeOfNumbers() + 1,
            std::rand()%(2*getRangeOfNumbers() - 1) - getRangeOfNumbers() + 1);
    }
    return data;
}
