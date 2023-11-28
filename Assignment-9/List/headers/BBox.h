#pragma once
#include <list>
#include "Triangle.h"

class BBox
{
public:
    BBox(std::list<Triangle> triangles);
    ~BBox();


private:
    void calculateBBox(std::list<Triangle> triangles);
    void compareAndUpdate(Point3D refP, Point3D& min, Point3D& max);

private:
    Point3D mMin;
    Point3D mMax;
    Point3D mCenter;
};