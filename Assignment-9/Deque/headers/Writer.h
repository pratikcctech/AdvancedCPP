#pragma once
#include<deque>
#include<string>
#include "Triangle.h"
class Writer
{
public:
    Writer();
    ~Writer();

    void write(std::string filePath ,std::deque<Triangle>& triangles);

};