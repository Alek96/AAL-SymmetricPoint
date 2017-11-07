#include "brut.h"

#include <iostream>

Brut::Brut(RectangleData &data)
    : data(data)
{
    (this->data).initializeData();
    rec = (this->data).getRectangle();
    //std::cout << "newTest:\n";
    //std::cout << "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")\n";
}

Rectangle Brut::solve()
{
    rek(0);
    return rec;
}

void Brut::rek(int x)
{
	if( x >= data.getSize() )
        return;

	rek(x+1);

    Rectangle newRec = data.getRectangle();

	if(newRec < rec) {
		rec = newRec;
        //std::cout << "(" << rec.getLeftX() << "," << rec.getLeftY() << "),(" << rec.getRightX() << "," << rec.getRightY() << ")\n";
	}

	data.changeSymmetrically(x);
	rek(x+1);
}

