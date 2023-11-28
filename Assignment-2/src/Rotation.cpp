#include <math.h>
#include<vector>
#include <iostream>
#include "../headers/Triangle.h"
#include "../headers/Rotation.h"

Rotation::Rotation(Triangulation &mt)
:mTriangulation(nullptr) //here, assign null pointer to the mTriangulation pointer variable
{
  //here, mTriangulation variable will store the address of the triangulation which comes form constructor.
  mTriangulation = &mt;
  
}
Rotation::~Rotation()
{
}
//Main function for rotation of a shape
std::vector<Triangle> Rotation::rotateShape(Point3D center){
    std::cout << "Enter the axis of rotation: " << std::endl;
    double xa, ya, za;
    std::cin >> xa >> ya >> za;
    Point3D p(xa, ya, za);
    std::cout << "Enter the angle of rotation: " << std::endl;
    double degree;
    std::cin >> degree;
    //translate all the points to the origin:
    std::vector<Triangle> vec;
    //iterate from all triangles from triangulation
    for(Triangle &triangle: mTriangulation->getTriangles()){
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();
        //update the variables and translate them to origin
        p1.setX(p1.x()-center.x());
        p1.setY(p1.y()-center.y());
        p1.setZ(p1.z()-center.z());
                                    
        p2.setX(p2.x()-center.x());
        p2.setY(p2.y()-center.y());
        p2.setZ(p2.z()-center.z());
                                    
        p3.setX(p3.x()-center.x());
        p3.setY(p3.y()-center.y());
        p3.setZ(p3.z()-center.z());
                                    
       Triangle t(p1, p2, p3);
       vec.push_back(t);
    }

    //rotate all points around given axis at a certain angle.
    char axis;
    if(p.x() == 1) axis = 'x';
    else if(p.y() == 1) axis = 'y';
    else axis = 'z';
    std::vector<Triangle> vec2;
    //iterate over all triangles and rotate all points
    for(Triangle triangle: vec){
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();
        Point3D np1 = rotate(p1, degree, axis);
        Point3D np2 = rotate(p2, degree, axis);
        Point3D np3 = rotate(p3, degree, axis);
        vec2.push_back(Triangle(np1, np2, np3));
    }
    std::vector<Triangle> vec3;
    //after rotation at origin, translate the points back to its center.
    for(Triangle triangle: vec2){
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();
       
        p1.setX(p1.x()+center.x());
        p1.setY(p1.y()+center.y());
        p1.setZ(p1.z()+center.z());
                                    
        p2.setX(p2.x()+center.x());
        p2.setY(p2.y()+center.y());
        p2.setZ(p2.z()+center.z());
                                    
        p3.setX(p3.x()+center.x());
        p3.setY(p3.y()+center.y());
        p3.setZ(p3.z()+center.z());
                                    
       Triangle t(p1, p2, p3);
       vec3.push_back(t);
    }
    return vec3;
}
// main function for rotation of every single point
Point3D Rotation::rotate(Point3D p, double degree, char axis){
    double angle = degree*M_PI/180;
    double xd, yd, zd;
    switch(axis){
        case 'x':{
          double xp = p.x();
          double yp = p.y();
          double zp = p.z();
          //matrix multiplication / rotation matrix for rotating point around x axis
          xd = xp;
          yd = (yp*cos(angle)) - (zp*sin(angle));
          zd = (yp*sin(angle)) + (zp*cos(angle));
        break;
        }
        case 'y':{
          double xp = p.x();
          double yp = p.y();
          double zp = p.z();

          //matrix multiplication / rotation matrix for rotating point around y axis
          xd = (zp*sin(angle)) + (xp*cos(angle));
          yd = yp;
          zd = (zp*cos(angle)) - (xp*sin(angle));
          break;
        }
        case 'z':{
          double xp = p.x();
          double yp = p.y();
          double zp = p.z();
          
          //matrix multiplication / rotation matrix for rotating point around x axis
          xd = (xp*cos(angle)) - (yp*sin(angle));
          yd = (xp*sin(angle)) + (yp*cos(angle));
          zd = zp;
        }
    }
    return Point3D(xd, yd, zd);
}