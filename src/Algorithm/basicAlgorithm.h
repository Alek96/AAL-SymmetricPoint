#ifndef BASICALGORITHM_H
#define BASICALGORITHM_H

#include "src/Data/pointData.h"
#include "src/Data/rectangle.h"

class BasicAlgorithm
{
public:
    virtual ~BasicAlgorithm() {};
    virtual void setData(PointData&) = 0;
    virtual Rectangle solve() = 0;
};

#endif
