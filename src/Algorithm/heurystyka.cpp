#include "heurystyka.h"

#include <algorithm>
#include <iostream>

Heurystyka::Heurystyka(PointData data)
    : data(data)
{}

void Heurystyka::setData(PointData& newData)
{
    data = newData;
}

PointData Heurystyka::getData() const
{
    return data;
}

Rectangle Heurystyka::solve()
{
    Rectangle rec;

    moveElementsToOneSide(true);
    moveMeaninglessElements(data.getRectangle());
    rec = data.getRectangle();

    moveElementsToOneSide(false);
    moveMeaninglessElements(data.getRectangle());
    rec = std::min(rec, data.getRectangle());

    return rec;
}

void Heurystyka::moveElementsToOneSide(bool XLessThatY)
{
    if(XLessThatY) {
        for(int i=0; i<data.getSize(); ++i) {
            if(data.getPoint(i).first > data.getPoint(i).second)
                data.changeSymmetrically(i);
        }
    } else {
        for(int i=0; i<data.getSize(); ++i) {
            if(data.getPoint(i).first < data.getPoint(i).second)
                data.changeSymmetrically(i);
        }
    }
}

void Heurystyka::moveMeaninglessElements(Rectangle rec)
{
    for(int i=0; i<data.getSize(); ++i) {
        if(!data.isOrginal(i))
            if( data.getPoint(i).first <= rec.getMaxY()
             && data.getPoint(i).first >= rec.getMinY()
             && data.getPoint(i).second <= rec.getMaxX()
             && data.getPoint(i).second >= rec.getMinX()) {
                data.changeSymmetrically(i);
            }
    }
}
