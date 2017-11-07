#ifndef BRUT_H
#define BRUT_H

#include "../Data/rectangleData.h"
#include "../Data/rectangle.h"
#include <memory>

class Brut
{
public:
    Brut(RectangleData &data);
    Rectangle solve();
private:
    RectangleData &data;
    Rectangle rec;
    void rek(int x);
    int numberOfSymmetricePoint;
};

#endif
