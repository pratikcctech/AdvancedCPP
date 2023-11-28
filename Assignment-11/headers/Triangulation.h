#pragma once
#include <vector>
#include<map>
#include "Triangle.h"
#include "BBox.h"

class Triangulation
{

public:
    Triangulation(std::vector<Triangle> triangles);
    ~Triangulation();

    std::vector<Triangle> getTriangles();
    std::map<Triangle, double> getArea();
    void printArea();


private:
    std::vector<Triangle> mTriangles;
    std::map<Triangle, double> tArea;
    BBox mBBox;

    void setArea();
    void printTriangle(Triangle triangle);
    double getDist(Point3D p1, Point3D p2);
};
