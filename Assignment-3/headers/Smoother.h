#pragma once
#include "Geometry.h"
#include "Triangulation.h"

class Smoother
{
public:
	Smoother(Triangulation triangulation);
	~Smoother();

	void smoothing(std::vector<Triangle>& triangles);
	Point3D getNormal(Point3D p1, Point3D p2, Point3D p3);

private:
	Triangulation mTriangulation;
	Point3D mCenter;
	double mRadius;
};
