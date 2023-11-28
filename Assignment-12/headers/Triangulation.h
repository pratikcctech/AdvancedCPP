#pragma once
#include <vector>
#include "Triangle.h"
#include "BBox.h"

class Triangulation : public Triangle
{

public:
    Triangulation(std::vector<Triangle> triangles);
    Triangulation();
    ~Triangulation();
    virtual void print();

    std::vector<Triangle> getTriangles();


private:
    std::vector<Triangle> mTriangles;
    BBox mBBox;
};
