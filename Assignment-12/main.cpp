#include "headers/Reader.h"
#include"headers/BBox.h"
#include "headers/Writer.h"
#include "headers/Geometry.h"

void printClassName(Point3D obj)
{
    obj.print();
}
 
int main()
{
    //get original shape points
    std::vector<Triangle> triangles;
    Reader readShape("D:\\Sketcher Exercise\\Ex12\\Updated Sketchers\\resources\\cubeModel.stl");
    readShape.getTriangles(triangles);

    //plot original shape points
    Writer writeGeometry;
    writeGeometry.write("Shape.txt", triangles);

    Point3D pointobj;
    Triangle triangleobj;
    Triangulation triangulationobj;

    printClassName(pointobj);
    printClassName(triangleobj);
    printClassName(triangulationobj);

    return 0;
}