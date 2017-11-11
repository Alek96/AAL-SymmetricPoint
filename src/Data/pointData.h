#ifndef POINTDATA_H
#define POINTDATA_H

#include "rectangle.h"

#include <vector>

class PointData
{
public:
    PointData();
    PointData(const PointData&);
    PointData(PointData&&);
	PointData& operator=(const PointData&);
	PointData& operator=(PointData&&);
    virtual ~PointData();

    bool operator==(const PointData&) const;
    bool operator!=(const PointData&) const;

    friend std::ostream& operator<<(std::ostream&, const PointData&);

    void pushPoint(int x, int y);
    std::pair<int,int> getPoint(int n) const;
    int getSize() const;

    void changeSymmetrically(int n); //move
    bool isOrginal(int n) const;
    int getOrginalPoints() const;
    Rectangle getRectangle() const;

private:
    int _size;
    std::vector<int> xAxis;
    std::vector<int> yAxis;
    std::vector<bool> orginal;
    int orginalPoints;
};

#endif //POINTDATA_H
