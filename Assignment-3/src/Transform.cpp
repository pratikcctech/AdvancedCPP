#include <iostream>
#include "../headers/Transform.h"
#include "../headers/Matrix.h"
#include "../headers/Point3D.h"
#include "../headers/BBox.h"

Transform::Transform(std::vector<Triangle>& triangles)
: mTriangles(triangles)
{
    
}

Transform::~Transform()
{
}

void Transform::scale(double scale)
{
    BBox bbox(mTriangles);
    Point3D center=bbox.getCenter();

    translate(-center.x(),-center.y(),-center.z());

    for (int i = 0; i < mTriangles.size(); i++) {
        Point3D p1=createScaledPoint(mTriangles[i].p1(), scale);
        Point3D p2=createScaledPoint(mTriangles[i].p2(), scale);
        Point3D p3=createScaledPoint(mTriangles[i].p3(), scale);
        mTriangles[i]=Triangle(p1, p2, p3);
    }
    
    translate(center.x(),center.y(),center.z());
}

Point3D Transform::createScaledPoint(Point3D point, double scale)
{
    Matrix matrix;
    std::vector<std::vector<double>> scalingMatrix = matrix.createScaleMatrix(scale);
    std::vector<double> pointHomogeneous = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> scaledPointHomogeneous = matrix.multiplyMatrixVector(scalingMatrix, pointHomogeneous);

    double scaledX = scaledPointHomogeneous[0] / scaledPointHomogeneous[3];
    double scaledY = scaledPointHomogeneous[1] / scaledPointHomogeneous[3];
    double scaledZ = scaledPointHomogeneous[2] / scaledPointHomogeneous[3];

    return Point3D(scaledX, scaledY, scaledZ);
}

void Transform::translate(double transX, double transY, double transZ) 
{

    for (int i = 0; i < mTriangles.size(); i++) {
        Point3D p1=createTranslatedPoint(mTriangles[i].p1(), transX, transY, transZ);
        Point3D p2=createTranslatedPoint(mTriangles[i].p2(), transX, transY, transZ);
        Point3D p3=createTranslatedPoint(mTriangles[i].p3(), transX, transY, transZ);
        mTriangles[i]=Triangle(p1, p2, p3);
    }

}

Point3D Transform::createTranslatedPoint(Point3D point, double transX, double transY, double transZ)
{
    Matrix matrix;
    std::vector<std::vector<double>> transMatrix = matrix.createTranslationMatrix(transX, transY, transZ);
    std::vector<double> pointHomogeneous = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> transPointHomogeneous = matrix.multiplyMatrixVector(transMatrix, pointHomogeneous);
    return Point3D(transPointHomogeneous[0], transPointHomogeneous[1], transPointHomogeneous[2]);
}