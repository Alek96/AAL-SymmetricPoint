#ifndef RECTANGLEDATA_H
#define RECTANGLEDATA_H

#include "pointData.h"
#include "rectangle.h"

#include <memory>

class RectangleData
    : public PointData
{
public:
    RectangleData();
    RectangleData(const PointData&);

    RectangleData(const RectangleData&);
	RectangleData(RectangleData&&);
	RectangleData& operator=(const RectangleData&);
	RectangleData& operator=(RectangleData&&);
    virtual ~RectangleData();

    bool operator==(const RectangleData&) const;
    bool operator!=(const RectangleData&) const;

    void changeSymmetrically(int n); //move
    void initializeData();
    int getMinX() const;
    int getMaxX() const;
    int getMinY() const;
    int getMaxY() const;
    Rectangle getRectangle() const;

private:
    int arraySize;
    int *minX;
    int *maxX;
    int *minY;
    int *maxY;

    int min(int a, int b) const;
    int max(int a, int b) const;
    void updata(int n);
};

#endif //RECTANGLEDATA_H
