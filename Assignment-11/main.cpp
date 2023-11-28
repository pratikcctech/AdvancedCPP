#include<iostream>
#include<vector>
#include "headers/Reader.h"
#include "headers/Triangle.h"
#include "headers/Triangulation.h"
#include "headers/Writer.h"

int main()
{
    std::vector<Triangle> triangles;
    Reader reader("resources/cubeModel.stl");
    reader.getTriangles(triangles);

    Triangulation triangulation(triangles);
    triangulation.printArea();

    Writer writer;

    std::vector<Triangle> outTriangles=triangulation.getTriangles();
    writer.write("output.txt", outTriangles);

    std::cout<<"Press enter to exit\n";
}