#pragma once
#include <vector>
#include "Point3D.h" // Make sure to include the correct header for Point3D

class ConvexHull {
public:
    ConvexHull(std::vector<Point3D> points); // Constructor
    ~ConvexHull(); // Destructor
    std::vector<Point3D> convex();

    // Function declaration for convexHull
    std::vector<Point3D> convexHull(std::vector<Point3D>& points);
    
private:
    double distance(Point3D& a, Point3D& b, Point3D& c);
    void findHull(Point3D& a, Point3D& b, std::vector<Point3D>& points, std::vector<Point3D>& hull);
};
