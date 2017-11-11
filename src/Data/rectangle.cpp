#include "rectangle.h"

Rectangle::Rectangle(int x1, int x2, int y1, int y2, int orginalPoints)
	: xMin(x1 <= x2 ? x1 : x2),
	  xMax(x1 <= x2 ? x2 : x1),
	  yMin(y1 <= y2 ? y1 : y2),
	  yMax(y1 <= y2 ? y2 : y1),
	  orginalPoints(orginalPoints < 0 ? 0 : orginalPoints)
{}

bool Rectangle::operator==(const Rectangle& rec) const
{
    return  getMinX() == rec.getMinX() &&
            getMaxX() == rec.getMaxX() &&
            getMinY() == rec.getMinY() &&
            getMaxY() == rec.getMaxY() &&
            getOrginalPoints() == rec.getOrginalPoints();
}
bool Rectangle::operator!=(const Rectangle& rec) const
{
    return !(*this == rec);
}

bool Rectangle::operator<(const Rectangle& rec) const
{
    if(getPerimeter() < rec.getPerimeter() ||
	   getPerimeter() == rec.getPerimeter() && getOrginalPoints() > rec.getOrginalPoints()) {
        return true;
    }else {
        return false;
    }
}
bool Rectangle::operator>(const Rectangle& rec) const
{
    return !(*this <= rec);
}
bool Rectangle::operator<=(const Rectangle& rec) const
{
    if(getPerimeter() < rec.getPerimeter() ||
	   getPerimeter() == rec.getPerimeter() && getOrginalPoints() >= rec.getOrginalPoints()) {
        return true;
    }else {
        return false;
    }
}
bool Rectangle::operator>=(const Rectangle& rec) const
{
    return !(*this < rec);
}

std::ostream& operator<<(std::ostream& os,const Rectangle& rec)
{
    os << "[(" << rec.getMinX() << "," << rec.getMinY() << "),(" << rec.getMaxX() << "," << rec.getMaxY() << ")," << rec.getOrginalPoints() << "]";
    return os;
}

int Rectangle::getMinX() const
{
	return xMin;
}
int Rectangle::getMaxX() const
{
	return xMax;
}
int Rectangle::getMinY() const
{
	return yMin;
}
int Rectangle::getMaxY() const
{
	return yMax;
}

int Rectangle::getPerimeter() const
{
	return (getMaxX()-getMinX() + getMaxY()-getMinY())*2;
}

int Rectangle::getOrginalPoints() const
{
	return orginalPoints;
}

bool Rectangle::isEqual(const Rectangle& rec) const
{
	return  getPerimeter() == rec.getPerimeter() &&
            getOrginalPoints() == rec.getOrginalPoints();
}
