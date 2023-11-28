#pragma once

#include<vector>

#include"Triangle.h"

class Properties{
    public:
    Properties(std::vector<Triangle>& triangles);
    float get_surface_area();
    ~Properties();
    private:
    std::vector<Triangle> triangles;
    float cal_area(Point3D p1, Point3D p2, Point3D p3);
    float cal_distance(Point3D p1, Point3D p2);
};