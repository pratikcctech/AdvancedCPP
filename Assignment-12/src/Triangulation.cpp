#include<iostream>
#include "../headers/Triangulation.h"

Triangulation::Triangulation(std::vector<Triangle> triangles)
:mBBox(triangles)
{
    mTriangles=triangles;
}

Triangulation::Triangulation()
{
}

Triangulation::~Triangulation()
{
}

std::vector<Triangle> Triangulation::getTriangles()
{
    return mTriangles;
}

void Triangulation::print()
{
    std::cout<<"Triangulation class"<<std::endl;
}
