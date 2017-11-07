#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle(int xl=0, int xr=0, int yl=0, int yr=0, int numberOfSymmetricePoint=0);
	bool operator<(const Rectangle&) const;
    bool operator>(const Rectangle&) const;
    bool operator==(const Rectangle&) const;

	int getLeftX() const;
	int getRightX() const;
	int getLeftY() const;
	int getRightY() const;
	int getPerimeter() const;
	int getNumberOfSymmetricePoint() const;
	bool isEqual(const Rectangle&) const;
private:
	int xl, xr, yl, yr;
	int numberOfSymmetricePoint;
};

#endif
