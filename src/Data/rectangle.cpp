#include "rectangle.h"

Rectangle::Rectangle(int xl, int xr, int yl, int yr, int numberOfSymmetricePoint)
	: xl(xl <= xr ? xl : xr),
	  xr(xl <= xr ? xr : xl),
	  yl(yl <= yr ? yl : yr),
	  yr(yl <= yr ? yr : yl),
	  numberOfSymmetricePoint(numberOfSymmetricePoint < 0 ? 0 : numberOfSymmetricePoint)
{}

bool Rectangle::operator==(const Rectangle& rec) const
{
    return  getLeftX() == rec.getLeftX() &&
            getRightX() == rec.getRightX() &&
            getLeftY() == rec.getLeftY() &&
            getRightY() == rec.getRightY() &&
            getNumberOfSymmetricePoint() == rec.getNumberOfSymmetricePoint();
}
bool Rectangle::operator<(const Rectangle& rec) const
{
    if(getPerimeter() < rec.getPerimeter() ||
	   getPerimeter() == rec.getPerimeter() && getNumberOfSymmetricePoint() < rec.getNumberOfSymmetricePoint()) {
        return true;
    }else {
        return false;
    }
}
bool Rectangle::operator>(const Rectangle& rec) const
{
    return !(*this < rec);
}


int Rectangle::getLeftX() const
{
	return xl;
}
int Rectangle::getRightX() const
{
	return xr;
}
int Rectangle::getLeftY() const
{
	return yl;
}
int Rectangle::getRightY() const
{
	return yr;
}

int Rectangle::getPerimeter() const
{
	return (xr-xl + yr-yl)*2;
}

int Rectangle::getNumberOfSymmetricePoint() const
{
	return numberOfSymmetricePoint;
}

bool Rectangle::isEqual(const Rectangle& rec) const
{
	return  getPerimeter() == rec.getPerimeter() &&
            getNumberOfSymmetricePoint() == rec.getNumberOfSymmetricePoint();
}
