#include "headers/Reader.h"
#include"headers/BBox.h"
#include "headers/Writer.h"
 
int main()
{
    //get original shape points
    std::vector<Triangle> triangles;
    Reader readShape("resources/cubeModel.stl");
    readShape.getTriangles(triangles);

    //plot original shape points
    Writer writeGeometry;
    writeGeometry.write("Shape.txt", triangles);

    return 0;
}