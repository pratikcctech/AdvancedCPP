#pragma once
#include <vector>
#include "Triangle.h"
#include "BBox.h"
class Explode
{
public:
    Explode(std::vector<Triangle> triangles);
    ~Explode();
    std::vector<Triangle> Exploder(std::vector<Triangle> &triangles);

private:
    BBox mBBox;
    double distance, vX, vY, vZ;
};