#pragma once
#include "Point3D.h"

class Triangle : public Point3D
{
public:
    Triangle();
    Triangle(Point3D p1, Point3D p2, Point3D p3);
    ~Triangle();

    Point3D p1();
    Point3D p2();
    Point3D p3();
    virtual void print();

private:
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
};