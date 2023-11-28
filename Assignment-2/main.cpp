#include <iostream>
#include <vector>

// individual headers should be included below last header
#include "headers/ConvexHull.h"
#include "headers/Explode.h"
#include "headers/HalfSection.h"
#include "headers/Mesh.h"
#include "headers/Physical_properties.h"
#include "headers/Reflection.h"
#include "headers/Rotation.h"
#include "headers/Reader.h"
#include "headers/Smoother.h"
#include "headers/Triangulation.h"
#include "headers/Transform.h"
#include "headers/Translation.h"
#include "headers/UnionOperation.h"
#include "headers/Writer.h"

int main()
{
    std::vector<Triangle> triangles;
    Reader reader("resources/cubeModel-2.stl");
    reader.getTriangles(triangles);

    Triangulation triangulation(triangles);
    std::vector<Triangle> outTriangles = triangulation.getTriangles();

    Writer writer;

    int featureId;
    std::cout << "Enter the feature ID: " << std::endl
              << "1. Surface area " << std::endl
              << "2. Mirror " << std::endl
              << "3. Bounding box " << std::endl
              << "4. Translate " << std::endl
              << "5. Rotate " << std::endl
              << "6. Scale " << std::endl
              << "7. Half section " << std::endl
              << "8. Convex Hull " << std::endl
              << "9. Intersection boundary " << std::endl
              << "10. Smoothing " << std::endl
              << "11. Explode " << std::endl
              << "12. Mesh Quality check" << std::endl;

    std::cin >> featureId;
    switch (featureId)
    {
        case 1:
        {
            Properties properties(outTriangles);
            std::cout << properties.get_surface_area() << std::endl;
            break;
        }
        case 2:
        {
            // get reflection about plane
            Plane refPlane;
            Reflection reflectShape;
            reflectShape.reflect(triangles, refPlane);
            std::vector<Triangle> reflectedTriangles = reflectShape.getReflectedTriangles();

            // plot reflection about plane
            writer.write("output/reflectedShape.txt", reflectedTriangles);

            // get bounding box points
            std::vector<Triangle> shapeTriangles;
            reader.getTriangles(shapeTriangles);
            BBox shapeBoundingBox(shapeTriangles);
            shapeBoundingBox.write();
            Reader readBoundingBoxOfCube("output/BBox.txt");

            // project bounding box points on the plane
            std::vector<Point3D> boundingBoxPoints;
            readBoundingBoxOfCube.getPoints(boundingBoxPoints);
            std::vector<Point3D> planeVector = refPlane.getPointProjectionOnPlane(boundingBoxPoints);

            // plot plane
            writer.write("output/plane.txt", planeVector);
            break;
        }

        case 3:
        {
            BBox bb(outTriangles);
            bb.write();
            break;
        }

        case 4:
        {
            Translation translation(triangles);
            std::vector<Triangle> traslatedGeometery = translation.translate(triangles);
            writer.write("output/translatedOutput.txt", traslatedGeometery);
            break;
        }

        case 5:
        {
            Rotation rotation(triangulation);
            BBox boundaryBox(triangles);
            Point3D centerPoint = boundaryBox.getCenter();
            std::vector<Triangle> rotatedGeometry = rotation.rotateShape(centerPoint);
            writer.write("output/rotatedOutput.txt", rotatedGeometry);
            break;
        }

        case 6:
        {
            Transform transform(outTriangles);
            transform.scale(2);
            break;
        }

        case 7:
        {
            BBox BBox = triangulation.getBoundingBox();
            Point3D mCenter = BBox.getCenter();
            HalfSection hobj;
            double offset;
            std::cout << "Enter the offset" << std::endl;
            std::cin >> offset;
            hobj.createHalfSection(triangles, mCenter, offset);
            break;
        }

        case 8:
        {
            std::vector<Point3D> points;
            reader.getPointsFromSTL(points);
            ConvexHull con(points);
            std::vector<Point3D> Hull = con.convex();

            writer.write("output/convexhullpoints.txt", Hull);
            break;
        }

        case 9:
        {
            std::vector<Triangle> trianglesOfGeometry1;
            std::vector<Triangle> trianglesOfGeometry2;
            UnionOperation unionoperation(trianglesOfGeometry1, trianglesOfGeometry2);

            // Creating the object of Union operation
            unionoperation.mergeGeometry("resources\\cube1.stl", "resources\\cube2.stl", trianglesOfGeometry1, trianglesOfGeometry2);
            std::vector<Point3D> intersectingPoints;
            intersectingPoints = unionoperation.getIntersectionPoints();

            // Creating the object of writer class
            Writer writer;

            // std::vector<Triangle> outTriangles=triangulation.getTriangles();
            writer.write("output\\geometry1.txt", unionoperation.getTrianglesOfGeometry1());
            writer.write("output\\geometry2.txt", unionoperation.getTrianglesOfGeometry2());
            writer.write("output\\intersection.txt", intersectingPoints);
            break;
        }

        case 10:
        {
            std::vector<Triangle> triangles2;
            Reader reader2("resources/cubeModel.stl");
            reader2.getTrianglesNormals(triangles2);

            Triangulation triangulation2(triangles2);
            std::vector<Triangle> outTriangles2 = triangulation2.getTriangles();

            Smoother smoother(triangulation2);
            smoother.smoothing(outTriangles2);
            writer.write("output/smoothed.txt", outTriangles2);
            break;
        }

        case 11:
        {
            char response;
            std::cout << "Calculate No of Triangles , press Y/N " << std::endl;
            std::cin >> response;
            if (response == 'Y')
            {
                triangulation.NoOfTriangles(triangles);
            }

            Explode exploder(outTriangles);

            std::vector<Triangle> ExplodeGeometry = exploder.Exploder(triangles);

            writer.write("output/output2.txt", ExplodeGeometry);
            break;
        }

        case 12:
        {
            Mesh mesh(triangles);
            // calling aspect ratio function....
            mesh.checkAspectRatio(triangles);
            // caliing skewness ratio function
            mesh.checkSkewnessRatio(triangles);
            break;
        }

        default:
            break;
    }

    writer.write("output/output.txt", outTriangles);
    return 0;
}