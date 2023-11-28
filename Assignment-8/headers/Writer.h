#pragma once
#include<vector>
#include<string>
#include "Triangle.h"
class Writer
{
public:
    Writer();
    ~Writer();

    void write(std::string filePath ,std::vector<Triangle>& triangles);

};