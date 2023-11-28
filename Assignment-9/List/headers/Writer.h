#pragma once
#include<string>
#include "Triangle.h"
#include <list>
class Writer
{
public:
    Writer();
    ~Writer();

    void write(std::string filePath ,std::list<Triangle>& triangles);

};