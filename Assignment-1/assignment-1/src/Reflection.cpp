#include <cmath>
#include <cstdlib>
#include "../headers/Reflection.h"
#include "../headers/Writer.h"

Reflection::Reflection()
{
}

Reflection::~Reflection()
{
}

void Reflection::reflect(std::vector<Triangle> &triangles, Plane refPlane)
{
    Point3D normalVector(refPlane.getNormalVector().x(), refPlane.getNormalVector().y(), refPlane.getNormalVector().z());
    Point3D planePoint(refPlane.getPlanePoint3D()[0].x(), refPlane.getPlanePoint3D()[0].y(), refPlane.getPlanePoint3D()[0].z());
    
    //ai+bj+ck form of vector
    const double a = normalVector.x();
    const double b = normalVector.y();
    const double c = normalVector.z();

    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));

    Point3D normalised_unit_vector(a / div, b / div, c / div);

    //uX+uY+uZ form of unit_vector
    double uX = normalised_unit_vector.x();
    double uY = normalised_unit_vector.y();
    double uZ = normalised_unit_vector.z();

    double x1 = planePoint.x(), y1 = planePoint.y(), z1 = planePoint.z();

    for (auto triangle : triangles)
    {
        double tx = triangle.p1().x();
        double ty = triangle.p1().y();
        double tz = triangle.p1().z();

        //distance of point from the plane
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        Point3D p1 = Point3D(tx + (2 * dist * uX), ty + (2 * dist * uY), tz + (2 * dist * uZ));

        tx = triangle.p2().x();
        ty = triangle.p2().y();
        tz = triangle.p2().z();
        dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        Point3D p2 = Point3D(tx + (2 * dist * uX), ty + (2 * dist * uY), tz + (2 * dist * uZ));

        tx = triangle.p3().x();
        ty = triangle.p3().y();
        tz = triangle.p3().z();
        dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        Point3D p3 = Point3D(tx + (2 * dist * uX), ty + (2 * dist * uY), tz + (2 * dist * uZ));

        mReflectedTriangles.push_back(Triangle(p1, p2, p3));
    }
}

std::vector<Triangle> Reflection::getReflectedTriangles()
{
    return mReflectedTriangles;
}