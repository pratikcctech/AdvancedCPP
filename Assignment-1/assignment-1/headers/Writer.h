#pragma once
#include <vector>
#include <string>
#include "Triangle.h"


//creating the class name Writer to write the given Point into the database and accessing it creating the member function named write.
class Writer
{
public:
    Writer();
    ~Writer();

    void write(std::string filePath ,std::vector<Triangle>& triangles);
    void write(std::string filePath, std::vector<Point3D>&Points);
};
