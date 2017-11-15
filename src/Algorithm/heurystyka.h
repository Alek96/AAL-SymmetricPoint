#ifndef HEURYSTYKA_H
#define HEURYSTYKA_H

#include "basicAlgorithm.h"
#include "src/Data/pointData.h"
#include "src/Data/rectangle.h"

class Heurystyka
    : public BasicAlgorithm
{
public:
    Heurystyka(PointData data = PointData());

    Heurystyka(const Heurystyka&) = default;
	Heurystyka(Heurystyka&&) = default;
	Heurystyka& operator=(const Heurystyka&) = default;
	Heurystyka& operator=(Heurystyka&&) = default;

	void setData(PointData&);
	PointData getData() const;
    Rectangle solve();
private:
    PointData data;
    Rectangle resultRec;
    void moveElementsToOneSide(bool XLessThatY);
    void moveMeaninglessElements(Rectangle rec);
    void moveEdge(Rectangle rec, bool XLessThatY);
};

#endif
