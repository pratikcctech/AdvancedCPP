#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include"../headers/Triangle.h"
#include"../headers/HalfSection.h"
#include"../headers/BBox.h"
#include"../headers/Point3D.h"
#include"../headers/Writer.h"

using namespace std;

HalfSection :: HalfSection(){}

HalfSection :: ~HalfSection(){}

/// @brief This function creates the halfsection of the shape from the STL file
/// @param triangles 
/// @param mCenter 
/// @param offset

void HalfSection :: createHalfSection(std::vector<Triangle>& triangles, Point3D mCenter, double offset)
{
  Writer wobj;
  string filePath1, filePath2;

  string plane;
  cout << "Please, enter the plane for Halfsection - XY, YZ or XZ " << "\n";
  cin>>plane;

  std::vector<Triangle> H_Triangles1;
  std::vector<Triangle> H_Triangles2;

  Point3D p11(0,0,0);
  Point3D p12(0,0,0);
  Point3D p13(0,0,0);

  Point3D p21(0,0,0);
  Point3D p22(0,0,0);
  Point3D p23(0,0,0);
 
  for (Triangle triangle:triangles)
  {
    if(((plane.compare("YZ")) == 0) || ((plane.compare("yz")) == 0))
    {
      if(triangle.p1().x() >= mCenter.x())    //for YZ plane
      {
        p11.setX(mCenter.x()-offset);
        p11.setY(triangle.p1().y());
        p11.setZ(triangle.p1().z());
        
        p21.setX(triangle.p1().x()+offset);
        p21.setY(triangle.p1().y());
        p21.setZ(triangle.p1().z());
      }
      else
      {
        p11.setX(triangle.p1().x()-offset);
        p11.setY(triangle.p1().y());
        p11.setZ(triangle.p1().z());
        
        p21.setX(mCenter.x()+offset);
        p21.setY(triangle.p1().y());
        p21.setZ(triangle.p1().z());
      }
     
      if(triangle.p2().x() >= mCenter.x())
      {
        p12.setX(mCenter.x()-offset);
        p12.setY(triangle.p2().y());
        p12.setZ(triangle.p2().z());
        
        p22.setX(triangle.p2().x()+offset);
        p22.setY(triangle.p2().y());
        p22.setZ(triangle.p2().z());
      }
      else
      {
        p12.setX(triangle.p2().x()-offset);
        p12.setY(triangle.p2().y());
        p12.setZ(triangle.p2().z());

        p22.setX(mCenter.x()+offset);
        p22.setY(triangle.p2().y());
        p22.setZ(triangle.p2().z());
      }
 
      if(triangle.p3().x() >= mCenter.x())
      {
        p13.setX(mCenter.x()-offset);
        p13.setY(triangle.p3().y());
        p13.setZ(triangle.p3().z());

        p23.setX(triangle.p3().x()+offset);
        p23.setY(triangle.p3().y());
        p23.setZ(triangle.p3().z());
      }
      else
      {
        p13.setX(triangle.p3().x()-offset);
        p13.setY(triangle.p3().y());
        p13.setZ(triangle.p3().z());

        p23.setX(mCenter.x()+offset);
        p23.setY(triangle.p3().y());
        p23.setZ(triangle.p3().z());
      }
    }
    else if((plane.compare("XZ") == 0) || (plane.compare("xz") == 0))           //for XZ plane
    {
      if(triangle.p1().y() >= mCenter.y())
      {
        p11.setY(mCenter.y()-offset);
        p11.setX(triangle.p1().x());
        p11.setZ(triangle.p1().z());
        
        p21.setY(triangle.p1().y()+offset);
        p21.setX(triangle.p1().x());
        p21.setZ(triangle.p1().z());
      }
      else
      {
        p11.setY(triangle.p1().y()-offset);
        p11.setX(triangle.p1().x());
        p11.setZ(triangle.p1().z());
        
        p21.setY(mCenter.y()+offset);
        p21.setX(triangle.p1().x());
        p21.setZ(triangle.p1().z());
      }
     
      if(triangle.p2().y() >= mCenter.y())
      {
        p12.setY(mCenter.y()-offset);
        p12.setX(triangle.p2().x());
        p12.setZ(triangle.p2().z());
        
        p22.setY(triangle.p2().y()+offset);
        p22.setX(triangle.p2().x());
        p22.setZ(triangle.p2().z());
      }
      else
      {
        p12.setY(triangle.p2().y()-offset);
        p12.setX(triangle.p2().x());
        p12.setZ(triangle.p2().z());

        p22.setY(mCenter.y()+offset);
        p22.setX(triangle.p2().x());
        p22.setZ(triangle.p2().z());
      }
 
      if(triangle.p3().y() >= mCenter.y())
      {
        p13.setY(mCenter.y()-offset);
        p13.setX(triangle.p3().x());
        p13.setZ(triangle.p3().z());

        p23.setY(triangle.p3().y()+offset);
        p23.setX(triangle.p3().x());
        p23.setZ(triangle.p3().z());
      }
      else
      {
        p13.setY(triangle.p3().y()-offset);
        p13.setX(triangle.p3().x());
        p13.setZ(triangle.p3().z());

        p23.setY(mCenter.y()+offset);
        p23.setX(triangle.p3().x());
        p23.setZ(triangle.p3().z());
      }
    }
    else if((plane.compare("XY") == 0) || (plane.compare("xy") == 0))             //for XZ plane
    {
      if(triangle.p1().z() >= mCenter.z())
      {
        p11.setZ(mCenter.z()-offset);
        p11.setY(triangle.p1().y());
        p11.setX(triangle.p1().x());
        
        p21.setZ(triangle.p1().z()+offset);
        p21.setY(triangle.p1().y());
        p21.setX(triangle.p1().x());
      }
      else
      {
        p11.setZ(triangle.p1().z()-offset);
        p11.setY(triangle.p1().y());
        p11.setX(triangle.p1().x());
        
        p21.setZ(mCenter.z()+offset);
        p21.setY(triangle.p1().y());
        p21.setX(triangle.p1().x());
      }
     
      if(triangle.p2().z() >= mCenter.z())
      {
        p12.setZ(mCenter.z()-offset);
        p12.setY(triangle.p2().y());
        p12.setX(triangle.p2().x());
        
        p22.setZ(triangle.p2().z()+offset);
        p22.setY(triangle.p2().y());
        p22.setX(triangle.p2().x());
      }
      else
      {
        p12.setZ(triangle.p2().z()-offset);
        p12.setY(triangle.p2().y());
        p12.setX(triangle.p2().x());

        p22.setZ(mCenter.z()+offset);
        p22.setY(triangle.p2().y());
        p22.setX(triangle.p2().x());
      }
 
      if(triangle.p3().z() >= mCenter.z())
      {
        p13.setZ(mCenter.z()-offset);
        p13.setY(triangle.p3().y());
        p13.setX(triangle.p3().x());

        p23.setZ(triangle.p3().z()+offset);
        p23.setY(triangle.p3().y());
        p23.setX(triangle.p3().x());
      }
      else
      {
        p13.setZ(triangle.p3().z()-offset);
        p13.setY(triangle.p3().y());
        p13.setX(triangle.p3().x());

        p23.setZ(mCenter.z()+offset);
        p23.setY(triangle.p3().y());
        p23.setX(triangle.p3().x());
      }
    }
      
      Triangle H_Triangle1(p11,p12,p13);
      H_Triangles1.push_back(H_Triangle1);

      Triangle H_Triangle2(p21,p22,p23);
      H_Triangles2.push_back(H_Triangle2);
  }

  wobj.write("output/disect1.txt",H_Triangles1);
  wobj.write("output/disect2.txt",H_Triangles2);
}