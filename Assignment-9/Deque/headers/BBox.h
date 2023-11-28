#pragma onceBBox
#include <deque>
#include "Triangle.h"

class BBox
{
public:
    BBox(std::deque<Triangle> triangles);
    ~BBox();


private:
    void calculateBBox(std::deque<Triangle> triangles);
    void compareAndUpdate(Point3D refP, Point3D& min, Point3D& max);

private:
    Point3D mMin;
    Point3D mMax;
    Point3D mCenter;
};