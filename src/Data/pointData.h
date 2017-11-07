#ifndef POINTDATA_H
#define POINTDATA_H

#include <memory>
#include <vector>

class PointData
{
public:
    PointData();
    virtual ~PointData();
    void pushPoint(int x, int y);
    std::pair<int,int> getPoint(int n);
    int getSize();
    void changeSymmetrically(int n);
    int getNumberOfSymmetricePoint();

private:
    int _size;
    std::vector<int> xAxis;
    std::vector<int> yAxis;
    std::vector<bool> symmetric;
    int numberOfSymmetricePoint;
};

#endif //POINTDATA_H
