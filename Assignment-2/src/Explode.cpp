#include "iostream"
#include "../headers/Explode.h"
#include "../headers/Point3D.h"
#include <cmath>

Explode ::Explode(std::vector<Triangle> triangles)
    : mBBox(triangles)
{
}
Explode::~Explode()
{
}

std::vector<Triangle> Explode::Exploder(std::vector<Triangle> &triangles)
{
    std::vector<Triangle> outtriangles;
    std::cout << "Enter the distnace" << std::endl;
    std::cin >> distance;

    for (int i = 0; i < triangles.size(); i++)
    {

        vX = triangles[i].getNormal().x();
        vY = triangles[i].getNormal().y();
        vZ = triangles[i].getNormal().z();

        double length = sqrt(vX * vX + vY * vY + vZ * vZ);
        double uVec = vX / length;
        double vVec = vY / length;
        double wVec = vZ / length;

        int count = 0;

        Point3D p1 = triangles[i].p1();
        Point3D p2 = triangles[i].p2();
        Point3D p3 = triangles[i].p3();

        double x = p1.x();
        double y = p1.y();
        double z = p1.z();

        double X1 = x + (distance * uVec);
        double Y1 = y + (distance * vVec);
        double Z1 = z + (distance * wVec);

        Point3D transP1(X1, Y1, Z1);

        x = p2.x();
        y = p2.y();
        z = p2.z();

        X1 = x + (distance * uVec);
        Y1 = y + (distance * vVec);
        Z1 = z + (distance * wVec);

        Point3D transP2(X1, Y1, Z1);

        x = p3.x();
        y = p3.y();
        z = p3.z();

        X1 = x + (distance * uVec);
        Y1 = y + (distance * vVec);
        Z1 = z + (distance * wVec);

        Point3D transP3(X1, Y1, Z1);
        Triangle triangle(transP1, transP2, transP3);
        outtriangles.push_back(triangle);
    }

    return outtriangles;
}