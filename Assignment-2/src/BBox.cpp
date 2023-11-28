#include <iostream>
#include <cmath>
#include "../headers/BBox.h"
#include "../headers/Writer.h"
#include "../headers/Triangle.h"
#include "../headers/Point3D.h"
#include "../headers/HalfSection.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

BBox::BBox(std::vector<Triangle> triangles)
    : mMin(0, 0, 0),
      mMax(0, 0, 0),
      mCenter(0, 0, 0)
{
    calculateBBox(triangles);
    mRadius = sqrt(pow(mCenter.x() - mMax.x(), 2) + pow(mCenter.y() - mMax.y(), 2) + pow(mCenter.z() - mMax.z(), 2));
}

BBox::~BBox()
{
}

void BBox::calculateBBox(std::vector<Triangle> triangles)
{

    mMax = Point3D(__DBL_MIN__, __DBL_MIN__, __DBL_MIN__);
    mMin = Point3D(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);

    for (Triangle triangle : triangles)
    {
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();

        compareAndUpdate(p1, mMin, mMax);
        compareAndUpdate(p2, mMin, mMax);
        compareAndUpdate(p3, mMin, mMax);
    }

    mCenter = Point3D((mMin.x() + mMax.x()) / 2, (mMin.y() + mMax.y()) / 2, (mMin.z() + mMax.z()) / 2);
    generateBBox();
}

void BBox::generateBBox()
{
    // 8 points of Bounding Box


    mData.push_back(Point3D(mMin.x(), mMin.y(), mMin.z()));

    mData.push_back(Point3D(mMax.x(), mMin.y(), mMin.z()));

    mData.push_back(Point3D(mMax.x(), mMax.y(), mMin.z()));

    mData.push_back(Point3D(mMin.x(), mMax.y(), mMin.z()));

    mData.push_back(Point3D(mMin.x(), mMin.y(), mMax.z()));

    mData.push_back(Point3D(mMax.x(), mMin.y(), mMax.z()));

    mData.push_back(Point3D(mMax.x(), mMax.y(), mMax.z()));

    mData.push_back(Point3D(mMin.x(), mMax.y(), mMax.z()));
}

void BBox::write()
{
    std::ofstream dataFile("output/BBox.txt");

    dataFile << mData[0].x() << " " << mData[0].y() << " " << mData[0].z() << std::endl;

    dataFile << mData[1].x() << " " << mData[1].y() << " " << mData[1].z() << std::endl;

    dataFile << mData[2].x() << " " << mData[2].y() << " " << mData[2].z() << std::endl;

    dataFile << mData[3].x() << " " << mData[3].y() << " " << mData[3].z() << std::endl;

    dataFile << mData[0].x() << " " << mData[0].y() << " " << mData[0].z() << std::endl;

    dataFile << mData[4].x() << " " << mData[4].y() << " " << mData[4].z() << std::endl;

    dataFile << mData[5].x() << " " << mData[5].y() << " " << mData[5].z() << std::endl;

    dataFile << mData[6].x() << " " << mData[6].y() << " " << mData[6].z() << std::endl;

    dataFile << mData[7].x() << " " << mData[7].y() << " " << mData[7].z() << std::endl;

    dataFile << mData[4].x() << " " << mData[4].y() << " " << mData[4].z() << std::endl;

    dataFile << mData[7].x() << " " << mData[7].y() << " " << mData[7].z() << std::endl;

    dataFile << mData[3].x() << " " << mData[3].y() << " " << mData[3].z() << std::endl;

    dataFile << mData[2].x() << " " << mData[2].y() << " " << mData[2].z() << std::endl;

    dataFile << mData[6].x() << " " << mData[6].y() << " " << mData[6].z() << std::endl;

    dataFile << mData[5].x() << " " << mData[5].y() << " " << mData[5].z() << std::endl;

    dataFile << mData[1].x() << " " << mData[1].y() << " " << mData[1].z() << std::endl;

    dataFile.close();
}

void BBox::compareAndUpdate(Point3D pointToCompare, Point3D &min, Point3D &max)
{
    if (pointToCompare.x() > max.x())
        max.setX(pointToCompare.x());

    if (pointToCompare.y() > max.y())
        max.setY(pointToCompare.y());

    if (pointToCompare.z() > max.z())
        max.setZ(pointToCompare.z());

    if (pointToCompare.x() < min.x())
        min.setX(pointToCompare.x());

    if (pointToCompare.y() < min.y())
        min.setY(pointToCompare.y());

    if (pointToCompare.z() < min.z())
        min.setZ(pointToCompare.z());
}

Point3D BBox::getCenter()
{
    return mCenter;
}

double BBox::getRadius()
{
    return mRadius;
}

Point3D BBox :: getMMin()
{
    return mMin;
}

Point3D BBox :: getMMax()
{
    return mMax;
}
