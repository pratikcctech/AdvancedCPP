#pragma once
#include <vector>
#include "Triangle.h"
#include "BBox.h"

class Triangulation
{
public:
    Triangulation(std::vector<Triangle> triangles);
    ~Triangulation();

    std::vector<Triangle> getTriangles();
    void NoOfTriangles(std::vector<Triangle>& triangles);
    BBox getBoundingBox();    
    BBox getBBox();

private:
    std::vector<Triangle> mTriangles;
    BBox mBBox;
};
