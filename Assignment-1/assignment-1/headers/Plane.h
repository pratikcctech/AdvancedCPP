#pragma once
#include<vector>
#include"Point3D.h"
#include"Triangle.h"
 
class Plane
{
    public:
        Plane(double A, double B, double C, double D);
        Plane();
        Plane(Point3D normalVector, Point3D planePoint3D);
        ~Plane();
        Point3D getNormalVector();
        std::vector<Point3D> getPlanePoint3D();
        std::vector<Point3D> getPointProjectionOnPlane(std::vector<Point3D> points);
        Point3D linePlaneIntersection(std::vector<Point3D> plane, std::vector<Point3D> line);
        Point3D calculateCrossProduct(Point3D &v1, Point3D &v2);
        double calculateDotProduct(Point3D &v1, Point3D &v2);
    private:
       void  getPlaneParameters();
 
    private:
        Point3D mNormalVector;
        double mA,mB,mC,mD;
        std::vector<Point3D> mPlanePoint3D;

};