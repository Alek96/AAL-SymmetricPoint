#ifndef RECTANGLEDATA_H
#define RECTANGLEDATA_H

#include "pointData.h"
#include "rectangle.h"
#include <memory>

/*
Mysl techniczna:

inteligentne wskazniki - nie potrzebne "delete []"
std::shared_ptr<int> minX;
zakaz dodania wiecej elementow niz n (stala?)
tablice beda stalymi - raczek nie
rzucac wyjatkami, na prawo i lewo
*/

class RectangleData
    : public PointData
{
public:
    RectangleData();
    virtual ~RectangleData();
    void changeSymmetrically(int n);
    void initializeData();
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
    Rectangle getRectangle();

private:
    int arraySize;
    int *minX;
    int *maxX;
    int *minY;
    int *maxY;

    int min(int a, int b);
    int max(int a, int b);
};

#endif //RECTANGLEDATA_H
