#include<cmath>

#include"../headers/Physical_properties.h"

Properties :: Properties(std::vector<Triangle> &triangles)
{
    this->triangles = triangles;
}

Properties :: ~Properties()
{
}

//this function calculates the distance between two points and returns it as float value
float Properties:: cal_distance(Point3D p1, Point3D p2){
    return sqrt( ( p1.x() - p2.x())*(p1.x() - p2.x()) + ( p1.y() - p2.y())*(p1.y() - p2.y()) + ( p1.z() - p2.z())*(p1.z() - p2.z()) );
}

//this function takes 3 points and calculates the distance between them by calling the function called 
// cal_distance then from these lines it will calculate area by herons formula and return the area
float Properties:: cal_area(Point3D p1, Point3D p2, Point3D p3){
    float l1 = cal_distance(p1, p2);
    float l2 = cal_distance(p2, p3);
    float l3 = cal_distance(p3, p1);
    float semi_perimeter = (l1 + l2 + l3)/2;
    return sqrt( semi_perimeter * (semi_perimeter - l1) * (semi_perimeter - l2) * (semi_perimeter - l3) );
}

//This function will iterate over triangles and calculate the area of the triangles by calling the function
//called cal_area with 3 points as the parameters and store the result in area 
float Properties:: get_surface_area()
{
    float area{};
    for(Triangle triangle : triangles){
        area += cal_area(triangle.p1(), triangle.p2(), triangle.p3());
    }
    return area;
}