#include <cmath>
#include <cstdlib>
#include <iostream>
#include "../headers/Plane.h"

Plane::Plane()
    : mNormalVector(0, 0, 0)
{
    getPlaneParameters();
}

Plane::Plane(double A, double B, double C, double D)
    : mA(0.0),
      mB(0.0),
      mC(0.0),
      mD(0.0),
      mNormalVector(0.0, 0.0, 0.0),
      mPlanePoint3D(std::vector<Point3D>{})
{
    mA = A;
    mB = B;
    mC = C;
    mD = D;
}

Plane::Plane(Point3D normalVector, Point3D planePoint3D)
    : mNormalVector(normalVector)
{
    this->mPlanePoint3D.push_back(planePoint3D);
}

Plane::~Plane()
{
}

void Plane::getPlaneParameters()
{
    double vX, vY, vZ, pX, pY, pZ;
    std::cout << "Enter Normal Vector :" << std::endl;
    std::cout << "Enter vX :" << std::endl;
    std::cin >> vX;

    std::cout << "Enter vY :" << std::endl;
    std::cin >> vY;

    std::cout << "Enter vZ :" << std::endl;
    std::cin >> vZ;

    mNormalVector = Point3D(vX, vY, vZ);

    std::cout << "Enter Point on the plane :" << std::endl;
    std::cout << "Enter pX :" << std::endl;
    std::cin >> pX;

    std::cout << "Enter pY :" << std::endl;
    std::cin >> pY;

    std::cout << "Enter pZ :" << std::endl;
    std::cin >> pZ;
    mPlanePoint3D.push_back(Point3D(vX, vY, vZ));
}

Point3D Plane::getNormalVector()
{
    return mNormalVector;
}

std::vector<Point3D> Plane::getPlanePoint3D()
{
    return mPlanePoint3D;
}

std::vector<Point3D> Plane::getPointProjectionOnPlane(std::vector<Point3D> points)
{
    std::vector<Point3D> returnPoints;
    const double a = mNormalVector.x();
    const double b = mNormalVector.y();
    const double c = mNormalVector.z();
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));

    Point3D normalised_unit_vector(a / div, b / div, c / div);

    for (auto point : points)
    {
        double tx = point.x();
        double ty = point.y();
        double tz = point.z();

        double x1 = mPlanePoint3D[0].x(), y1 = mPlanePoint3D[0].y(), z1 = mPlanePoint3D[0].z();
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        Point3D pPoint = Point3D((tx + (dist * normalised_unit_vector.x())), (ty + (dist * normalised_unit_vector.y())), (tz + (dist * normalised_unit_vector.z())));
        returnPoints.push_back(pPoint);
    }
    return returnPoints;
}
Point3D Plane::calculateCrossProduct(Point3D &v1, Point3D &v2)
{
    Point3D result(0.0, 0.0, 0.0);
    result.setX((v1.y() * v2.z()) - (v1.z() * v2.y()));
    result.setY((v1.z() * v2.x()) - (v1.x() * v2.z()));
    result.setZ((v1.x() * v2.y()) - (v1.y() * v2.x()));
    return result;
}

double Plane::calculateDotProduct(Point3D &v1, Point3D &v2)
{
    return (v1.x() * v2.x()) + (v1.y() * v2.y()) + (v1.z() * v2.z());
}

Point3D Plane::linePlaneIntersection(std::vector<Point3D> plane, std::vector<Point3D> line)
{
    Point3D v1(plane[1].x() - plane[0].x(), plane[1].y() - plane[0].y(), plane[1].z() - plane[0].z());
    Point3D v2(plane[2].x() - plane[0].x(), plane[2].y() - plane[0].y(), plane[2].z() - plane[0].z());

    Point3D normal_vector = calculateCrossProduct(v1, v2);

    Plane planeObj(0.0, 0.0, 0.0, 0.0);
    mA = normal_vector.x();
    mB = normal_vector.y();
    mC = normal_vector.z();
    mD = -calculateDotProduct(normal_vector, plane[0]);

    Point3D direction_vector(line[1].x() - line[0].x(), line[1].y() - line[0].y(), line[1].z() - line[0].z());
    double t = 0.0;
    double denominator = calculateDotProduct(normal_vector, direction_vector);
    if (denominator != 0.0)
    {
        t = (-mD - mA * line[0].x() - mB * line[0].y() - mC * line[0].z()) / denominator;
        Point3D intersection_point(line[0].x() + t * direction_vector.x(), line[0].y() + t * direction_vector.y(), line[0].z() + t * direction_vector.z());
        return intersection_point;
    }
    else
    {
        Point3D intersection_point(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);
        return intersection_point;
    }
}
