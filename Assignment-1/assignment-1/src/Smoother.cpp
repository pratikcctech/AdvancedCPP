#include <cmath>
#include "..\headers\Smoother.h"

Smoother::Smoother(Triangulation triangulation)
	: mTriangulation(std::vector<Triangle>{}),
	  mRadius(0),
	  mCenter(0, 0, 0)
{
	mTriangulation = triangulation;
	mRadius = mTriangulation.getBBox().getRadius();
	mCenter = mTriangulation.getBBox().getCenter();
}

Smoother::~Smoother()
{
}

void Smoother::smoothing(std::vector<Triangle> &triangles)
{
	std::vector<Triangle> newTriangles;

	for (Triangle triangle : triangles)
	{
		Point3D p1 = triangle.p1();
		Point3D p2 = triangle.p2();
		Point3D p3 = triangle.p3();
		Point3D normal = triangle.getNormal();

		float centroid_x = (p1.x() + p2.x() + p3.x()) / 3;
		float centroid_y = (p1.y() + p2.y() + p3.y()) / 3;
		float centroid_z = (p1.z() + p2.z() + p3.z()) / 3;

		Point3D centroid = Point3D(centroid_x, centroid_y, centroid_z);

		double distance = sqrt(pow(mTriangulation.getBBox().getCenter().x() - centroid.x(), 2) +
							   pow(mTriangulation.getBBox().getCenter().y() - centroid.y(), 2) +
							   pow(mTriangulation.getBBox().getCenter().z() - centroid.z(), 2));

		double difference = mRadius - distance;

		centroid.setX(centroid.x() + (difference * normal.x()));
		centroid.setY(centroid.y() + (difference * normal.y()));
		centroid.setZ(centroid.z() + (difference * normal.z()));

		Triangle newTriangle = Triangle(p1, p2, centroid);
		Point3D newNormal = getNormal(p1, p2, centroid);
		newTriangle.setNormal(newNormal);

		newTriangles.push_back(Triangle(p1, p2, centroid));

		newTriangle = Triangle(centroid, p2, p3);
		newNormal = getNormal(centroid, p2, p3);
		newTriangle.setNormal(newNormal);

		newTriangles.push_back(Triangle(centroid, p2, p3));

		newTriangle = Triangle(p3, p1, centroid);
		newNormal = getNormal(p3, p1, centroid);
		newTriangle.setNormal(newNormal);

		newTriangles.push_back(Triangle(p3, p1, centroid));
	}
	triangles.clear();
	triangles = newTriangles;
}

Point3D Smoother::getNormal(Point3D p1, Point3D p2, Point3D p3)
{
	Point3D v1(p2.x() - p1.x(), p2.y() - p1.y(), p2.z() - p1.z());
	Point3D v2(p3.x() - p1.x(), p3.y() - p1.y(), p3.z() - p1.z());

	double normal_x = (v1.y() * v2.z()) - (v1.z() * v2.y());
	double normal_y = (v1.z() * v2.x()) - (v1.x() * v2.z());
	double normal_z = (v1.x() * v2.y()) - (v1.y() * v2.x());

	return Point3D(-1 * normal_x, -1 * normal_y, -1 * normal_z);
}
