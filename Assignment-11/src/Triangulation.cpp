#include <iostream>
#include <algorithm>
#include <utility>
#include "../headers/Triangulation.h"
#include <Math.h>

Triangulation::Triangulation(std::vector<Triangle> triangles)
    : mBBox(triangles)
{
    mTriangles = triangles;
}

Triangulation::~Triangulation()
{
}

double Triangulation::getDist(Point3D p1, Point3D p2)
{
    double dist = sqrt(pow((p1.x() - p2.x()), 2.0) + pow((p1.y() - p2.y()), 2.0) + pow((p1.z() - p2.z()), 2.0));
    return dist;
}

std::vector<Triangle> Triangulation::getTriangles()
{
    return mTriangles;
}

std::map<Triangle, double> Triangulation::getArea()
{
    return tArea;
}

void Triangulation::printTriangle(Triangle triangle)
{
    std::cout <<"("<< triangle.p1().x() << "," << triangle.p1().y() << ","<< triangle.p1().z()<<")" << std::endl;
    std::cout <<"("<< triangle.p2().x() << " " << triangle.p2().y() << " "<< triangle.p2().z() <<")"<< std::endl;
    std::cout <<"("<< triangle.p3().x() << " " << triangle.p3().y() << " "<< triangle.p3().z() <<")"<< std::endl;
}

void Triangulation::printArea()
{
    setArea();
    int i{0};
    for (auto pair : tArea)
    {
        std::cout << "[ Triangle-" << i << std::endl;
        printTriangle(pair.first);
        std::cout <<"Area-"<<pair.second<<" ]"<<std::endl;
        i++;
    }
}

void Triangulation::setArea()
{
    std::cout<<"Inside setArea";
    for (auto triangle : mTriangles)
    {
        double a = getDist(triangle.p1(), triangle.p2());
        double b = getDist(triangle.p1(), triangle.p3());
        double c = getDist(triangle.p3(), triangle.p2());

        double s = (a + b + c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));

        tArea.insert(std::make_pair(triangle, area));
    }
}
