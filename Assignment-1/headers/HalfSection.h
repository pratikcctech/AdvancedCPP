#pragma once
#include<vector>
#include"Triangle.h"
#include"Point3D.h"
#include"BBox.h"

class HalfSection
{
   public:
    HalfSection();
    ~HalfSection();

    void createHalfSection(std::vector<Triangle>& triangles, Point3D mCenter, double offset);
};
