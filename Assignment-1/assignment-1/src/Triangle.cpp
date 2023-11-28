#include <vector>
#include<cmath>
#include "../headers/Triangle.h"

#define PI 3.1415926535
Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3)
:mP1(0,0,0),
mP2(0,0,0),
mP3(0,0,0),
mNormal(0,0,0)
{
    mP1=p1;
    mP2=p2;
    mP3=p3;

    // Sides calculation.......
    mSide1 = sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()) + (p2.z() - p1.z()) * (p2.z() - p1.z()));
    mSide2 = sqrt((p3.x() - p2.x()) * (p3.x() - p2.x()) + (p3.y() - p2.y()) * (p3.y() - p2.y()) + (p3.z() - p2.z()) * (p3.z() - p2.z()));
    mSide3 = sqrt((p1.x() - p3.x()) * (p1.x() - p3.x()) + (p1.y() - p3.y()) * (p1.y() - p3.y()) + (p1.z() - p3.z()) * (p1.z() - p3.z()));

    // Angles calculation...
    mAngle1 = calculateAngle(mSide1, mSide2, mSide3);
    mAngle2 = calculateAngle(mSide2, mSide1, mSide3);
    mAngle3 = calculateAngle(mSide3, mSide1, mSide2);
}

Triangle::~Triangle()
{
}

Point3D Triangle::p1()
{
    return mP1;
}

Point3D Triangle::p2()
{
    return mP2;
}

Point3D Triangle::p3()
{
    return mP3;
}

void Triangle::setNormal(Point3D normal)
{
    mNormal = normal;
}
Point3D Triangle :: getNormal()
{
    return mNormal;
}

// Getters for sides of triangle...
double Triangle :: side1()
{
    return mSide1;
}

double Triangle :: side2()
{
    return mSide2;
}

double Triangle :: side3()
{
    return mSide3;
}

//Getters for angles of a triangle...
double Triangle :: angle1()
{
    return mAngle1;
}

double Triangle :: angle2()
{
    return mAngle2;
}

double Triangle :: angle3()
{
    return mAngle3;
}

//Function to calculate angles of triangle...
double Triangle :: calculateAngle(double S1, double S2, double S3)
{
    double angleInRadian{};

    angleInRadian = acos((S2 * S2 + S3 * S3 - S1 * S1) / (2 * S2 * S3));

    double angleInDegree = angleInRadian * 180 / PI;

    return angleInDegree;
}
