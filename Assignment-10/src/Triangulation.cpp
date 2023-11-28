#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"

Triangulation::Triangulation(std::deque<Triangle> triangles)
:mBBox(triangles)
{
    mTriangles=triangles;
}

Triangulation::~Triangulation()
{
}

std::deque<Triangle> Triangulation::getTriangles(){
    return mTriangles;
}