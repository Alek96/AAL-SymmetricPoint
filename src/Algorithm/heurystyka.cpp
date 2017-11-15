#include "heurystyka.h"

#include <algorithm>
#include <vector>

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
    resultRec = rec;
    moveEdge(rec, true);

    moveElementsToOneSide(false);
    moveMeaninglessElements(data.getRectangle());
    rec = data.getRectangle();
    resultRec = std::min(resultRec, rec);
    moveEdge(rec, false);

    return resultRec;
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

void Heurystyka::moveEdge(Rectangle rec, bool XLessThatY)
{
    std::vector<int> vertical;
    std::vector<int> horizontal;
    std::vector<int> vertex;

    if(XLessThatY) {
        for(int i=0; i<data.getSize(); ++i) {
            if(data.getPoint(i).first < rec.getMinY() && data.getPoint(i).second > rec.getMaxX()) {
                vertex.push_back(i);
            } else if( data.getPoint(i).first < rec.getMinY() ) {
                vertical.push_back(i);
            } else if( data.getPoint(i).second > rec.getMaxX() ) {
                horizontal.push_back(i);
            }
        }
    } else {
        for(int i=0; i<data.getSize(); ++i) {
            if(data.getPoint(i).first > rec.getMaxY() && data.getPoint(i).second < rec.getMinX()) {
                vertex.push_back(i);
            } else if( data.getPoint(i).first > rec.getMaxY() ) {
                vertical.push_back(i);
            } else if( data.getPoint(i).second < rec.getMinX() ) {
                horizontal.push_back(i);
            }
        }
    }

    auto checkAndMove = [&](std::vector<int> &vec) {
        int orginalPoints=0;
        std::for_each(vec.begin(), vec.end(), [&](int &x){ if(data.isOrginal(x)) ++orginalPoints; } );
        if( vec.size() > 2*orginalPoints ) {
            std::for_each(vec.begin(), vec.end(), [&](int &x){ data.changeSymmetrically(x); } );
            resultRec = std::min(resultRec, data.getRectangle());
            std::for_each(vec.begin(), vec.end(), [&](int &x){ data.changeSymmetrically(x); } );
        }
    };

    if(vertex.empty()) {
        checkAndMove(vertical);
        checkAndMove(horizontal);
    } else {
        vertex.insert(vertex.end(), vertical.begin(), vertical.end());
        vertex.insert(vertex.end(), horizontal.begin(), horizontal.end());
        checkAndMove(vertex);
    }
}
