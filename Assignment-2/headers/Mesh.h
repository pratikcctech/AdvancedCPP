#pragma once

#include<vector>
#include "Point3D.h"
#include "Triangle.h"

class Mesh
{

    public:
        Mesh(std::vector<Triangle> triangles);
        ~Mesh();

        void checkAspectRatio(std::vector<Triangle> mTriangles);

        void checkSkewnessRatio(std::vector<Triangle> mTriangles);

    private:
        std::vector<Triangle> mTriangles;
};


