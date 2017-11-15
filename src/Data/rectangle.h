#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
public:
	Rectangle(int x1=0, int x2=0, int y1=0, int y2=0, int orginalPoints=0);

	Rectangle(const Rectangle&) = default;
	Rectangle(Rectangle&&) = default;
	Rectangle& operator=(const Rectangle&) = default;
	Rectangle& operator=(Rectangle&&) = default;
	//virtual ~Rectangle() = default;

    bool operator==(const Rectangle&) const;
    bool operator!=(const Rectangle&) const;
	bool operator<(const Rectangle&) const;
    bool operator>(const Rectangle&) const;
	bool operator<=(const Rectangle&) const;
    bool operator>=(const Rectangle&) const;

    friend std::ostream& operator<<(std::ostream&, const Rectangle&);

	bool isEqual(const Rectangle&) const;
	int getMinX() const;
	int getMaxX() const;
	int getMinY() const;
	int getMaxY() const;
	int getPerimeter() const;
	int getOrginalPoints() const;
private:
	int xMin, xMax, yMin, yMax;
	int orginalPoints;
};

#endif
