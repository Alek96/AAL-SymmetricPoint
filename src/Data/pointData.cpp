#include "pointData.h"

#include <algorithm>
#include <memory>
#include <iostream>

PointData::PointData()
    : _size(0), orginalPoints(0)
{}
PointData::PointData(const PointData& PD)
    : _size(PD._size), xAxis(PD.xAxis), yAxis(PD.yAxis), orginal(PD.orginal), orginalPoints(PD.orginalPoints)
{}
PointData::PointData(PointData&& PD)
    : _size(PD._size), xAxis(std::move(PD.xAxis)), yAxis(std::move(PD.yAxis)), orginal(std::move(PD.orginal)), orginalPoints(PD.orginalPoints)
{
    PD._size = 0;
    PD.orginalPoints = 0;
}

PointData& PointData::operator=(const PointData& data)
{
    _size = data._size;
    xAxis = data.xAxis;
    yAxis = data.yAxis;
    orginal = data.orginal;
    orginalPoints = data.orginalPoints;
}
PointData& PointData::operator=(PointData&& data)
{
    _size = data._size;
    data._size = 0;

    xAxis = std::move(data.xAxis);
    yAxis = std::move(data.yAxis);
    orginal = std::move(data.orginal);

    orginalPoints = data.orginalPoints;
    data.orginalPoints = 0;
}

PointData::~PointData() {}

bool PointData::operator==(const PointData& data) const
{
    return _size == data._size
        && xAxis == data.xAxis
        && yAxis == data.yAxis
        && orginal == data.orginal
        && orginalPoints == data.orginalPoints;
}
bool PointData::operator!=(const PointData& data) const
{
    return !(*this == data);
}

std::ostream& operator<<(std::ostream& os, const PointData& data)
{
    os << data.getSize() << "\n";
    for(int i=0; i<data.getSize(); ++i) {
        os << data.getPoint(i).first << " " << data.getPoint(i).second << "\n";
    }
    return os;
}

void PointData::pushPoint(int x, int y)
{
    xAxis.push_back(x);
    yAxis.push_back(y);
    orginal.push_back(true);
    ++_size;
    ++orginalPoints;
}

std::pair<int,int> PointData::getPoint(int n) const
{
    if( n < _size )
        return orginal[n] ? std::make_pair(xAxis[n], yAxis[n]) : std::make_pair(yAxis[n], xAxis[n]);
    return std::make_pair(0, 0);
}

int PointData::getSize() const
{
    return _size;
}

void PointData::changeSymmetrically(int n)
{
    if( n < _size && getPoint(n).first != getPoint(n).second ) {
        if(orginal[n]) {
            orginal[n] = false;
            --orginalPoints;
        }
        else {
            orginal[n] = true;
            ++orginalPoints;
        }
    }
}

bool PointData::isOrginal(int n) const
{
    return orginal[n];
}

int PointData::getOrginalPoints() const
{
    return orginalPoints;
}

Rectangle PointData::getRectangle() const
{
    if( !_size )
        throw std::logic_error( "Is empty" );

    int l,r,u,d;
    l = r = getPoint(0).first;
    u = d = getPoint(0).second;

    for(int i=1; i<_size; ++i) {
        l = std::min(l, getPoint(i).first);
        r = std::max(r, getPoint(i).first);
        d = std::min(d, getPoint(i).second);
        u = std::max(u, getPoint(i).second);
    }

    return Rectangle(l, r, d, u, getOrginalPoints());
}
