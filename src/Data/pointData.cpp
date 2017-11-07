#include "pointData.h"


PointData::PointData()
    : _size(0), numberOfSymmetricePoint(0)
{}

PointData::~PointData() {}

void PointData::pushPoint(int x, int y)
{
    xAxis.push_back(x);
    yAxis.push_back(y);
    symmetric.push_back(false);
    ++_size;
}

std::pair<int,int> PointData::getPoint(int n)
{
    if( n < _size )
        return symmetric[n] ? std::make_pair(yAxis[n], xAxis[n]) : std::make_pair(xAxis[n], yAxis[n]);
    return std::make_pair(0, 0);
}

int PointData::getSize()
{
    return _size;
}

void PointData::changeSymmetrically(int n)
{
    if( n < _size ) {
        if(symmetric[n]) {
            symmetric[n] = false;
            --numberOfSymmetricePoint;
        }
        else {
            symmetric[n] = true;
            ++numberOfSymmetricePoint;
        }
    }
}

int PointData::getNumberOfSymmetricePoint()
{
    return numberOfSymmetricePoint;
}
