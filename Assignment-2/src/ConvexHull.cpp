#include "../headers/ConvexHull.h"
#include <vector>
#include <fstream>
#include <iostream> // Include this for 'cout'
#include "../headers/Point3D.h"
#include <cmath> //for calculating power and squareroot operations
using namespace std;
std::vector<Point3D> points;
// Constructor
ConvexHull::ConvexHull(std::vector<Point3D> point)
{
    points = point;
}

// Destructor
ConvexHull::~ConvexHull() {}

// This is convex hull function
std::vector<Point3D> ConvexHull::convex()
{

    std::vector<Point3D> hull = convexHull(points);
    std::cout<<hull.size()<<std::endl;
    return hull;
}

std::vector<Point3D> ConvexHull::convexHull(std::vector<Point3D> &points)
{
    int n = points.size();
    if (n < 4)
    {
        return points;
    }

    std::vector<Point3D> hull;

    // Find the points with the minimum and maximum x coordinates.
    int minIdx = 0, maxIdx = 0;

    for (int i = 1; i < n; i++)
    {
        if (points[i].x() < points[minIdx].x())
        {
            minIdx = i;
        }
        else if (points[i].x() == points[minIdx].x())
        {
            if (points[i].y() < points[minIdx].y())
            {
                minIdx = i;
            }
            else if (points[i].y() == points[minIdx].y())
            {
                if (points[i].z() < points[minIdx].z())
                {
                    minIdx = i;
                }
            }
        }
        if (points[i].x() > points[maxIdx].x())
        {
            maxIdx = i;
        }
        else if (points[i].x() == points[maxIdx].x())
        {
            if (points[i].y() > points[maxIdx].y())
            {
                maxIdx = i;
            }
            else if (points[i].y() == points[maxIdx].y())
            {
                if (points[i].z() > points[maxIdx].z())
                {
                    maxIdx = i;
                }
            }
        }
    }
    hull.push_back(points[maxIdx]);
    hull.push_back(points[minIdx]);
    // Recursively find the convex hull on the left and right of the line formed by minIdx and maxIdx.
    findHull(points[minIdx], points[maxIdx], points, hull);
    findHull(points[maxIdx], points[minIdx], points, hull);

    return hull;
}

// To calculate farthest point
double ConvexHull::distance(Point3D &a, Point3D &b, Point3D &c)
{
    double num = (b.y() - a.y()) * (c.z() - a.z()) - (b.z() - a.z()) * (c.y() - a.y());
    double den = (b.x() - a.x()) * (c.z() - a.z()) - (b.z() - a.z()) * (c.x() - a.x());
    return num / den;

    // double A = a.y() * (b.z() - a.z()) - a.z() * (b.y() - a.y());
    // double B = a.z() * (b.x() - a.x()) - a.x() * (b.z() - a.z());
    // double C = a.x() * (b.y() - a.y()) - a.y() * (b.x() - a.x());
    // double D = -(A * a.x() + B * a.y() + C * a.z());

    // double num = A * c.x() + B * b.y() + C * c.z() + D;
    // double den = sqrt((pow(A, 2)) + (pow(B, 2)) + (pow(C, 2)));
    // double di = num / den;
    // return di;
}

// This function is to find hull points
void ConvexHull::findHull(Point3D &a, Point3D &b, std::vector<Point3D> &points, std::vector<Point3D> &hull)
{
    std::vector<Point3D> s1, s2;

    if (points.empty())
    {
        return;
    }

    Point3D farthest = points[0];
    double maxDist = 0.0;

    for (Point3D &p : points)
    {
        double dist = distance(a, b, p);
        if (dist > maxDist)
        {
            maxDist = dist;
            farthest = p;
        }
    }

    for (Point3D &p : points)
    {
        if (distance(a, farthest, p) > 0)
        {
            s1.push_back(p); // farthest point pushing into vector<Point3D> s1
        }
    }

    for (Point3D &p : points)
    {
        if (distance(farthest, b, p) > 0)
        {
            s2.push_back(p); // farthest point pushing into vector<Point3D> s2
        }
    }

    findHull(a, farthest, s1, hull);
    hull.push_back(farthest);
    findHull(farthest, b, s2, hull);
}
