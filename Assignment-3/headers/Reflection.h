#pragma once
#include<vector>
#include"Plane.h"
#include "Triangle.h"
 
class Reflection
{
    public:
        Reflection();
        ~Reflection();
 
        void reflect(std::vector<Triangle>& triangles, Plane refPlane);
        std::vector<Triangle> getReflectedTriangles();
 
    private:
        std::vector<Triangle> mReflectedTriangles;
};