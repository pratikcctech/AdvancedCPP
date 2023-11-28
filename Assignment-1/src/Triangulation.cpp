#include<iostream>
#include "../headers/Triangulation.h"

Triangulation::Triangulation(std::vector<Triangle> triangles)
: mBBox(triangles)
{
    mTriangles = triangles;
}

Triangulation::~Triangulation()
{
}

std::vector<Triangle> Triangulation::getTriangles()
{
    return mTriangles;
}
void Triangulation::NoOfTriangles(std::vector<Triangle>& triangles)
{
    std ::cout<< "Total Number of triangles: " << triangles.size() << std::endl;
}

BBox Triangulation :: getBoundingBox()
{
    return mBBox;
}

BBox Triangulation::getBBox()
{
    return mBBox;
}
