#pragma once
#include <vector>
#include "Triangle.h"
#include "BBox.h"
#include "Point3D.h"
class Translation
{
public:
    Translation(std::vector<Triangle> triangles);
    ~Translation();
    std::vector<Triangle> translate(std::vector<Triangle>& triangles);
    std::vector<Triangle> transTriangles;

private:   
    BBox mBBox;
    double distance,vX,vY,vZ;
    double originalX,originalY,originalZ;
    double transX,transY,transZ;
    double length,uVec,vVec,wVec;
    Point3D getUnitVector(Point3D dirVector);
};

