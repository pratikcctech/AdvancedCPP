#pragma once
#include <vector>
#include "Triangulation.h"

class Rotation
{
public:
    //Arged constructor which takes address of Triangulation as argument
    Rotation(Triangulation &mt);
    //Rotation Destructor
    ~Rotation();
    //rotateShape function which takes a point which represents an axis and angle in degrees on which we want to rotate shape.
    std::vector<Triangle> rotateShape(Point3D center);
    //function to rotate individual point which takes parameters as given point, angle in degrees and 
    //axis of rotation.
    Point3D rotate(Point3D p, double degree, char axis);
    
private:
    //Pointer to Triangulation variable which stores Triangulation data (vector of triangles)
    Triangulation* mTriangulation;
    
};