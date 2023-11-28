#pragma once
#include <list>
#include "Triangle.h"
#include "BBox.h"

class Triangulation
{

public:
    Triangulation(std::list<Triangle> triangles);
    ~Triangulation();

    std::list<Triangle> getTriangles();

private:
    std::list<Triangle> mTriangles;
    BBox mBBox;
};
