#include "iostream"
#include "../headers/Translation.h"
#include "../headers/Point3D.h"
#include <cmath>

Translation :: Translation(std::vector<Triangle> triangles)
:mBBox(triangles)
{
}
Translation::~Translation()
{
}

// Function takes the input triangles vector and return the translated triangles vector
std::vector<Triangle> Translation::translate(std::vector<Triangle>& triangles)
{
    std::cout<<"Enter the distnace for translation"<<std::endl;
    std::cin>>distance;

    std::cout <<"Enter the direction vector co-ordinates" << std::endl;
    std::cin>>vX;
    std::cin>>vY;
    std::cin>>vZ;

    Point3D vecPoint(vX,vY,vZ);
    Point3D unitVecPoint = getUnitVector(vecPoint);
    
    for(auto triangle:triangles)
    {
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();
        
        originalX=p1.x();
        originalY=p1.y();
        originalZ=p1.z();

        transX = originalX + (distance * unitVecPoint.x());
        transY = originalY + (distance * unitVecPoint.y());
        transZ = originalZ + (distance * unitVecPoint.z());

        Point3D transP1(transX,transY,transZ);

        originalX=p2.x();
        originalY=p2.y();
        originalZ=p2.z();

        transX = originalX + (distance * unitVecPoint.x());
        transY = originalY + (distance * unitVecPoint.y());
        transZ = originalZ + (distance * unitVecPoint.z());

        Point3D transP2(transX,transY,transZ);

        originalX=p3.x();
        originalY=p3.y();
        originalZ=p3.z();

        transX = originalX + (distance * unitVecPoint.x());
        transY = originalY + (distance * unitVecPoint.y());
        transZ = originalZ + (distance * unitVecPoint.z());

        Point3D transP3(transX,transY,transZ);

        Triangle transTriangle(transP1,transP2,transP3);
        transTriangles.push_back(transTriangle);
    }
    return transTriangles;
}

// To convert the direction vecotr to unit direction vector
Point3D Translation :: getUnitVector(Point3D dirVector)
{
    length = sqrt(vX * vX + vY * vY + vZ * vZ);
    uVec = vX / length;
    vVec = vY / length;
    wVec = vZ / length;
    Point3D vecPoint(uVec,vVec,wVec);
    return vecPoint;
}