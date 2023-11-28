#pragma once
#include "Point3D.h"
#include <vector>

class Triangle
{
public:
    Triangle(Point3D p1, Point3D p2, Point3D p3);
    ~Triangle();

    Point3D p1();
    Point3D p2();
    Point3D p3();

    void setNormal(Point3D normal);
    Point3D getNormal();

    //Getters to get values of sides of tringle.....
    double side1();
    double side2();
    double side3();

    //Getters to get values of angles of tringle...
    double angle1();
    double angle2();
    double angle3();

    //Function to calculate angle...
    double calculateAngle(double s1, double s2, double s3);

    
private:
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
    Point3D mNormal;

    //Sides of triangle...
    double mSide1;
    double mSide2;
    double mSide3;

    //Angles of triangle...
    double mAngle1;
    double mAngle2;
    double mAngle3;
};
