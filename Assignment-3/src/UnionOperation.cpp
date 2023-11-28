#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../headers/Reader.h"
#include "../headers/Point3D.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Geometry.h"
#include "../headers/Matrix.h"
#include "../headers/UnionOperation.h"
#include "../headers/Writer.h"
#include "../headers/Plane.h"

UnionOperation::UnionOperation(std::vector<Triangle> &trianglesOfGeometry1, std::vector<Triangle> &trianglesOfGeometry2)
    : mTrianglesOfGeometry1(trianglesOfGeometry1),
      mTrianglesOfGeometry2(trianglesOfGeometry2),
      mCenteroidOfGeometry1(0.0, 0.0, 0.0),
      mCenteroidOfGeometry2(0.0, 0.0, 0.0),
      mPlane(0.0, 0.0, 0.0, 0.0),
      mIntersectionPoints(std::vector<Point3D>{})
{
    std::vector<Point3D> intersectionPoints;
    mIntersectionPoints = intersectionPoints;
}

UnionOperation::~UnionOperation()
{
}

double UnionOperation::length(Point3D p1, Point3D p2)
{
    return sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2) + pow(p1.z() - p2.z(), 2));
}

std::vector<Triangle> &UnionOperation ::getTrianglesOfGeometry1()
{
    return mTrianglesOfGeometry1;
}
std::vector<Triangle> &UnionOperation ::getTrianglesOfGeometry2()
{
    return mTrianglesOfGeometry2;
}
std::vector<Point3D> &UnionOperation ::getIntersectionPoints()
{
    return mIntersectionPoints;
}

void UnionOperation::translateTriangles(std::vector<Triangle> &outTriangles1, std::vector<Triangle> &outTriangles2, Point3D CenteroidOfGeometry1, Point3D CenteroidOfGeometry2)
{
    double transX = 0.0;
    double transY = 0.0;
    double transZ = 0.0;
    if (mCenteroidOfGeometry1.x() > mCenteroidOfGeometry2.x())
    {
        transX = mTrianglesOfGeometry1[0].p1().x() - mCenteroidOfGeometry2.x();
        transY = mTrianglesOfGeometry1[0].p1().y() - mCenteroidOfGeometry2.y();
        transZ = mTrianglesOfGeometry1[0].p1().z() - mCenteroidOfGeometry2.z();
    }
    else
    {
        transX = mTrianglesOfGeometry2[0].p1().x() - mCenteroidOfGeometry1.x();
        transY = mTrianglesOfGeometry2[0].p1().y() - mCenteroidOfGeometry1.y();
        transZ = mTrianglesOfGeometry2[0].p1().z() - mCenteroidOfGeometry1.z();
    }

    for (int i = 0; i < mTrianglesOfGeometry2.size(); i++)
    {
        Point3D p1 = createTranslatedPoint(mTrianglesOfGeometry2[i].p1(), -transX, -transY, -transZ);
        Point3D p2 = createTranslatedPoint(mTrianglesOfGeometry2[i].p2(), -transX, -transY, -transZ);
        Point3D p3 = createTranslatedPoint(mTrianglesOfGeometry2[i].p3(), -transX, -transY, -transZ);
        mTrianglesOfGeometry2[i] = Triangle(p1, p2, p3);
    }
}

Point3D UnionOperation::createTranslatedPoint(Point3D point, double transX, double transY, double transZ)
{
    Matrix matrix;
    std::vector<std::vector<double>> translateMatrix = matrix.createTranslationMatrix(transX, transY, transZ);
    std::vector<double> pointHomogeneous = {point.x(), point.y(), point.z(), 1.0};
    std::vector<double> transPointHomogeneous = matrix.multiplyMatrixVector(translateMatrix, pointHomogeneous);
    return Point3D(transPointHomogeneous[0], transPointHomogeneous[1], transPointHomogeneous[2]);
}

void UnionOperation::mergeGeometry(std::string filePath1, std::string filePath2, std::vector<Triangle> &trianglesOfGeometry1, std::vector<Triangle> &trianglesOfGeometry2)
{
    Reader reader1(filePath1);
    reader1.getTriangles(trianglesOfGeometry1);

    Reader reader2(filePath2);
    reader2.getTriangles(trianglesOfGeometry2);

    Triangulation triangulationOfGeometry1(trianglesOfGeometry1);
    Triangulation triangulationOfGeometry2(trianglesOfGeometry2);
    Point3D CenteroidOfGeometry1 = triangulationOfGeometry1.getBoundingBox().getCenter();
    Point3D CenteroidOfGeometry2 = triangulationOfGeometry2.getBoundingBox().getCenter();

    mTrianglesOfGeometry1 = triangulationOfGeometry1.getTriangles();
    mTrianglesOfGeometry2 = triangulationOfGeometry2.getTriangles();
    translateTriangles(mTrianglesOfGeometry1, mTrianglesOfGeometry2, CenteroidOfGeometry1, CenteroidOfGeometry2);
    getIntersectionOfGeomtries(mTrianglesOfGeometry1, mTrianglesOfGeometry2);
}

void UnionOperation::getIntersectionOfGeomtries(std::vector<Triangle> mTrianglesOfGeometry1, std::vector<Triangle> mTrianglesOfGeometry2)
{
    for (int i = 0; i < mTrianglesOfGeometry1.size(); i++)
    {
        for (int j = 0; j < mTrianglesOfGeometry2.size(); j++)
        {
            std::vector<Point3D> plane = {mTrianglesOfGeometry1[i].p1(), mTrianglesOfGeometry1[i].p2(), mTrianglesOfGeometry1[i].p3()};
            std::vector<Point3D> plane1 = {mTrianglesOfGeometry2[i].p1(), mTrianglesOfGeometry2[i].p2(), mTrianglesOfGeometry2[i].p3()};
            std::vector<Point3D> line1 = {mTrianglesOfGeometry2[j].p1(), mTrianglesOfGeometry2[j].p2()};
            std::vector<Point3D> line2 = {mTrianglesOfGeometry2[j].p2(), mTrianglesOfGeometry2[j].p3()};
            std::vector<Point3D> line3 = {mTrianglesOfGeometry2[j].p3(), mTrianglesOfGeometry2[j].p1()};
            Point3D point1(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);
            Point3D point2(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);
            Point3D point3(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);
            point1 = mPlane.linePlaneIntersection(plane, line1);
            point2 = mPlane.linePlaneIntersection(plane, line2);
            point3 = mPlane.linePlaneIntersection(plane, line3);

            Triangulation triangulation(mTrianglesOfGeometry1);
            Point3D mMin = triangulation.getBoundingBox().getMMin();
            Point3D mMax = triangulation.getBoundingBox().getMMax();

            
            if ((point1.x() != __DBL_MAX__ && point1.y() != __DBL_MAX__ && point1.z() != __DBL_MAX__) && (length(line1[0], point1) + length(line1[1], point1) == length(line1[0], line1[1])))
            {
                if ((mMin.x() <= point1.x() && mMax.x() >= point1.x()) && (mMin.y() <= point1.y() && mMax.y() >= point1.y()) && (mMin.z() <= point1.z() && mMax.z() >= point1.z()))
                {
                    mIntersectionPoints.push_back(point1);
                }
            }
            if ((point2.x() != __DBL_MAX__ && point2.y() != __DBL_MAX__ && point2.z() != __DBL_MAX__) && (length(line2[0], point2) + length(line2[1], point2) == length(line2[0], line2[1])))
            {
                if ((mMin.x() <= point2.x() && mMax.x() >= point2.x()) && (mMin.y() <= point2.y() && mMax.y() >= point2.y()) && (mMin.z() <= point2.z() && mMax.z() >= point2.z()))
                {
                    mIntersectionPoints.push_back(point2);
                }
            }
            if ((point3.x() != __DBL_MAX__ && point3.y() != __DBL_MAX__ && point3.z() != __DBL_MAX__) && (length(line3[0], point3) + length(line3[1], point3) == length(line3[0], line3[1])))
            {
                if ((mMin.x() <= point3.x() && mMax.x() >= point3.x()) && (mMin.y() <= point3.y() && mMax.y() >= point3.y()) && (mMin.z() <= point3.z() && mMax.z() >= point3.z()))
                {
                    mIntersectionPoints.push_back(point3);
                }
            }
        }
    }

    std::vector<Point3D> unqiuePointsOfIntersection;
    for (int i = 0; i < mIntersectionPoints.size(); i++)
    {
        if (unqiuePointsOfIntersection.size() == 0)
        {
            unqiuePointsOfIntersection.push_back(mIntersectionPoints[i]);
        }
        else
        {
            int checkDuplicate = 0;
            for (int j = 0; j < unqiuePointsOfIntersection.size(); j++)
            {
                if ((unqiuePointsOfIntersection[j].x() == mIntersectionPoints[i].x()) && (unqiuePointsOfIntersection[j].y() == mIntersectionPoints[i].y()) && (unqiuePointsOfIntersection[j].z() == mIntersectionPoints[i].z()))
                {
                    checkDuplicate = 1;
                    break;
                }
            }
            if (checkDuplicate == 0)
            {
                unqiuePointsOfIntersection.push_back(mIntersectionPoints[i]);
            }
        }
    }

    mIntersectionPoints = unqiuePointsOfIntersection;
}
