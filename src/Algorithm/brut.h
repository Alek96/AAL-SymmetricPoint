#ifndef BRUT_H
#define BRUT_H

#include "basicAlgorithm.h"
#include "src/Data/pointData.h"
#include "src/Data/rectangleData.h"
#include "src/Data/rectangle.h"
#include <memory>

class Brut
    : public BasicAlgorithm
{
public:
    Brut(const PointData data = PointData());
    //Brut(RectangleData &data);

    Brut(const Brut&) = default;
	Brut(Brut&&) = default;
	Brut& operator=(const Brut&) = default;
	Brut& operator=(Brut&&) = default;

	void setData(PointData&);
	RectangleData getData() const;
    Rectangle solve();
private:
    RectangleData data;
    Rectangle rec;
    void rek(int x);
};

#endif
