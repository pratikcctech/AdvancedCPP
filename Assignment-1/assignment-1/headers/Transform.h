#pragma once 

#include <vector>
#include "Triangle.h"
class Transform
{
public:
    Transform(std::vector<Triangle>& triangles);
    ~Transform();

    void translate(double transX, double transY, double transZ);
    void scale(double scale);

private:
    Point3D createScaledPoint(Point3D point, double scale);
    Point3D createTranslatedPoint(Point3D point, double transX, double transY, double transZ);
    std::vector<Triangle>& mTriangles;
};
