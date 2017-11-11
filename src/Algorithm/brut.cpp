#include "brut.h"

#include <iostream>

Brut::Brut(const PointData data)
    : data(data)
{
    (this->data).initializeData();
}

/*Brut::Brut(RectangleData &data)
    : data(data)
{
    (this->data).initializeData();
    rec = (this->data).getRectangle();
}*/

void Brut::setData(PointData& newData)
{
    data = RectangleData(newData);
    data.initializeData();
}

RectangleData Brut::getData() const
{
    return data;
}

Rectangle Brut::solve()
{
    rec = data.getRectangle();
    rek(0);
    return rec;
}

void Brut::rek(int x)
{
    Rectangle newRec;
	if( x >= data.getSize() )
        return;
	rek(x+1);

	newRec = data.getRectangle();
	if(newRec < rec)
		rec = newRec;

	data.changeSymmetrically(x);

    newRec = data.getRectangle();
	if(newRec < rec)
		rec = newRec;

	rek(x+1);
}

