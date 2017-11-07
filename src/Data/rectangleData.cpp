#include "rectangleData.h"
#include <stdexcept>
#include <limits>

RectangleData::RectangleData()
    : PointData(), arraySize(0), minX(nullptr), maxX(nullptr), minY(nullptr), maxY(nullptr)
{}

RectangleData::~RectangleData()
{
    delete [] minX;
    delete [] maxX;
    delete [] minY;
    delete [] maxY;
}

void RectangleData::changeSymmetrically(int n)
{
    PointData::changeSymmetrically(n);

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

void RectangleData::initializeData()
{
    if(minX)    delete [] minX;
    if(maxX)    delete [] maxX;
    if(minY)    delete [] minY;
    if(maxY)    delete [] maxY;

    for(arraySize = 2; arraySize < getSize(); arraySize <<= 1);
    minX = new int[arraySize];
    maxX = new int[arraySize];
    minY = new int[arraySize];
    maxY = new int[arraySize];

    auto decideF = [](RectangleData *it, int a){
        return a < it->getSize() ? it->getPoint( a ).first : std::numeric_limits<int>::max(); };
    auto decideS = [](RectangleData *it, int a){
        return a < it->getSize() ? it->getPoint( a ).second : std::numeric_limits<int>::max(); };

    for(int i = arraySize-1; i > 0; --i ) {
        if( i >= arraySize/2 ) {
            minX[i] = min( decideF(this, 2*i - arraySize), decideF(this, 2*i+1 - arraySize) );
                //2*i - arraySize < getSize() ? getPoint( 2*i - arraySize ).first : std::numeric_limits<int>::max(),
                //2*i+1 - arraySize < getSize() ? getPoint( 2*i+1 - arraySize ).first : std::numeric_limits<int>::max()}
            maxX[i] = max( decideF(this, 2*i - arraySize), decideF(this, 2*i+1 - arraySize) );
            minY[i] = min( decideS(this, 2*i - arraySize), decideS(this, 2*i+1 - arraySize) );
            maxY[i] = max( decideS(this, 2*i - arraySize), decideS(this, 2*i+1 - arraySize) );
        }else {
            minX[i] = min(minX[2*i],minX[2*i+1]);
            maxX[i] = max(maxX[2*i],maxX[2*i+1]);
            minY[i] = min(minY[2*i],minY[2*i+1]);
            maxY[i] = max(maxY[2*i],maxY[2*i+1]);
        }
    }
}


int RectangleData::getMinX()
{
    if(minX)
        return minX[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMaxX()
{
    if(maxX)
        return maxX[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMinY()
{
    if(minY)
        return minY[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}
int RectangleData::getMaxY()
{
    if(maxY)
        return maxY[1];
    else if( getSize() )
        throw std::logic_error( "Must be initialized" );
    else
        throw std::logic_error( "Is empty" );
}

Rectangle RectangleData::getRectangle()
{
    return Rectangle(getMinX(), getMaxX(), getMinY(), getMaxY(), getNumberOfSymmetricePoint());
}

int RectangleData::min(int a, int b)
{
    return a < b ? a : b;
}

int RectangleData::max(int a, int b)
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
