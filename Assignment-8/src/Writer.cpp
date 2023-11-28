#include <fstream>
#include "../headers/Writer.h"
#include "iostream"

Writer::Writer(/* args */)
{
}

Writer::~Writer()
{
}

void Writer::write(std::string filePath, std::vector<Triangle> &triangles)
{
  std::ofstream dataFile;
  //opening the file to write the all the data point from the vector
  dataFile.open(filePath);


  //using iterator in for loop to iterate it
  for (auto it = triangles.begin(); it != triangles.end(); ++it)
  {
    std::cout << (*it).p1().x() << " " << (*it).p1().y() << " " << (*it).p1().z() << std::endl;
    std::cout << (*it).p2().x() << " " << (*it).p2().y() << " " << (*it).p2().z() << std::endl;
    std::cout << (*it).p3().x() << " " << (*it).p3().y() << " " << (*it).p3().z() << std::endl;
  }

  for (Triangle triangle : triangles)
  {
    dataFile << triangle.p1().x() << " " << triangle.p1().y() << " " << triangle.p1().z() << std::endl;
    dataFile << triangle.p2().x() << " " << triangle.p2().y() << " " << triangle.p2().z() << std::endl;
    dataFile << triangle.p3().x() << " " << triangle.p3().y() << " " << triangle.p3().z() << std::endl;
    dataFile << triangle.p1().x() << " " << triangle.p1().y() << " " << triangle.p1().z() << std::endl;
  }
  dataFile.close();
};