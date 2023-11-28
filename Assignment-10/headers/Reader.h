#pragma once
#include <deque>
#include <string>
#include "Triangle.h"

class Reader {
public:
    Reader(std::string filePath);
    ~Reader();

    void getTriangles(std::deque<Triangle>& triangles);

private:
    std::string mFilePath;
};