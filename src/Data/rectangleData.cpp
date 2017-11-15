#include "rectangleData.h"
#include <stdexcept>
#include <limits>

RectangleData::RectangleData()
    :  arraySize(0), minX(nullptr), maxX(nullptr), minY(nullptr), maxY(nullptr)
{}

RectangleData::RectangleData(const PointData& data)
    : PointData(data), arraySize(0), minX(nullptr), maxX(nullptr), minY(nullptr), maxY(nullptr)
{
    initializeData();
}

RectangleData::RectangleData(const RectangleData& data)
    : PointData(data), arraySize(0), minX(nullptr), maxX(nullptr), minY(nullptr), maxY(nullptr)
{
    initializeData();
}
RectangleData::RectangleData(RectangleData&& data)
    : PointData(std::move(data)), arraySize(data.arraySize), minX(data.minX), maxX(data.maxX), minY(data.minY), maxY(data.maxY)
{
    data.arraySize = 0;
    data.minX = nullptr;
    data.maxX = nullptr;
    data.minY = nullptr;
    data.maxY = nullptr;
}
RectangleData& RectangleData::operator=(const RectangleData& data)
{
    PointData::operator=(data);
    initializeData();
}
RectangleData& RectangleData::operator=(RectangleData&& data)
{
    PointData::operator=(std::move(data));

    arraySize = data.arraySize;
    minX = data.minX;
    maxX = data.maxX;
    minY = data.minY;
    maxY = data.maxY;

    data.arraySize = 0;
    data.minX = nullptr;
    data.maxX = nullptr;
    data.minY = nullptr;
    data.maxY = nullptr;
}


RectangleData::~RectangleData()
{
    delete [] minX;
    delete [] maxX;
    delete [] minY;
    delete [] maxY;
}

bool RectangleData::operator==(const RectangleData& data) const
{
    auto equalArray = [](const int* a, const int* b, const int& n){
        for(int i=1; i<n; ++i) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    };

    return PointData::operator==(data)
        && arraySize == data.arraySize
        && equalArray(minX, data.minX, arraySize)
        && equalArray(maxX, data.maxX, arraySize)
        && equalArray(minY, data.minY, arraySize)
        && equalArray(maxY, data.maxY, arraySize);
}
bool RectangleData::operator!=(const RectangleData& data) const
{
    return !(*this == data);
}

void RectangleData::changeSymmetrically(int n)
{
    if(n < getSize()) {
        PointData::changeSymmetrically(n);
        updata(n);
    }
}

void RectangleData::initializeData()
{
    if(!getSize())
        return;

    if(minX)    delete [] minX;
    if(maxX)    delete [] maxX;
    if(minY)    delete [] minY;
    if(maxY)    delete [] maxY;

    for(arraySize = 2; arraySize < getSize(); arraySize <<= 1);
    minX = new int[arraySize];
    maxX = new int[arraySize];
    minY = new int[arraySize];
    maxY = new int[arraySize];

    for(int i = 0; i < arraySize; ++i )
        minX[i] = maxX[i] = minY[i] = maxY[i] = std::numeric_limits<int>::max();

    for(int i = 0; i < getSize(); ++i )
        updata(i);
}


int RectangleData::getMinX() const
{
    if(minX)
        return minX[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMaxX() const
{
    if(maxX)
        return maxX[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMinY() const
{
    if(minY)
        return minY[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMaxY() const
{
    if(maxY)
        return maxY[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}

Rectangle RectangleData::getRectangle() const
{
    return Rectangle(getMinX(), getMaxX(), getMinY(), getMaxY(), getOrginalPoints());
}

int RectangleData::min(int a, int b) const
{
    return a < b ? a : b;
}

int RectangleData::max(int a, int b) const
{
    if(a > b) {
        if(a != std::numeric_limits<int>::max())
            return a;
        return b;
    }else if(b > a) {
        if(b != std::numeric_limits<int>::max())
            return b;
        return a;
    }
    return a;
}

void RectangleData::updata(int n)
{
    if(minX && maxX && minY && maxY) {}
    else if( getSize() ) {
        throw std::logic_error( "Must be initialized" );
    } else {
        throw std::logic_error( "Is empty" );
    }

    auto decideF = [](RectangleData *it, int a){
        return a < it->getSize() ? it->getPoint( a ).first : std::numeric_limits<int>::max(); };
    auto decideS = [](RectangleData *it, int a){
        return a < it->getSize() ? it->getPoint( a ).second : std::numeric_limits<int>::max(); };

    int m = (n+arraySize)/2;

    minX[m] = min( decideF(this, 2*m - arraySize), decideF(this, 2*m+1 - arraySize) );
    maxX[m] = max( decideF(this, 2*m - arraySize), decideF(this, 2*m+1 - arraySize) );
    minY[m] = min( decideS(this, 2*m - arraySize), decideS(this, 2*m+1 - arraySize) );
    maxY[m] = max( decideS(this, 2*m - arraySize), decideS(this, 2*m+1 - arraySize) );

    for(int i = m/2; i > 0; --i ) {
        minX[i] = min(minX[2*i],minX[2*i+1]);
        maxX[i] = max(maxX[2*i],maxX[2*i+1]);
        minY[i] = min(minY[2*i],minY[2*i+1]);
        maxY[i] = max(maxY[2*i],maxY[2*i+1]);
    }
}
