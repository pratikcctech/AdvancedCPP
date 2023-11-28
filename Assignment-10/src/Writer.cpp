#include<fstream>
#include "../headers/Writer.h"
#include <string>

Writer::Writer(/* args */)
{
}

Writer::~Writer()
{
}

void Writer::write(std::string filePath ,std::deque<Triangle>& triangles)
{
  std::ofstream dataFile;
  dataFile.open(filePath);
  
  for (Triangle triangle:triangles)
  {   
      std::string s1=std::to_string(int(triangle.p1().x()));
      std::string s2=std::to_string(int(triangle.p1().y())); 
      std::string s3=std::to_string(int(triangle.p1().z()));
      std::string s=s1+" "+s2+" "+s3+" ";
      dataFile <<s<< std::endl;
      dataFile << triangle.p2().x() << " " << triangle.p2().y() << " "<< triangle.p2().z() << std::endl;
      dataFile << triangle.p3().x() << " " << triangle.p3().y() << " "<< triangle.p3().z() << std::endl;
      dataFile << triangle.p1().x() << " " << triangle.p1().y() << " "<< triangle.p1().z() << std::endl;
  }
  dataFile.close();
};