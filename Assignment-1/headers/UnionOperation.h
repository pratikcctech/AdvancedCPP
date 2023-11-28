#include <vector>
#include "Triangle.h"
#include "Plane.h"
#include <string>

class UnionOperation
{
public:
    UnionOperation(std::vector<Triangle> &trianglesOfGeometry1, std::vector<Triangle> &trianglesOfGeometry2);
    ~UnionOperation();
    void translateTriangles(std::vector<Triangle> &outTriangles1, std::vector<Triangle> &outTriangles2, Point3D CenteroidOfGeometry1, Point3D CenteroidOfGeometry2);
    void mergeGeometry(std::string filePath1, std::string filePath2, std::vector<Triangle> &trianglesOfGeometry1, std::vector<Triangle> &trianglesOfGeometry2);
    void getIntersectionOfGeomtries(std::vector<Triangle> TrianglesOfGeometry1, std::vector<Triangle> TrianglesOfGeometry2);
    bool comparePoints(Point3D a, Point3D b);
    double length(Point3D p1, Point3D p2);
    std::vector<Triangle> &getTrianglesOfGeometry1();
    std::vector<Triangle> &getTrianglesOfGeometry2();
    std::vector<Point3D> &getIntersectionPoints();

private:
    Point3D createTranslatedPoint(Point3D point, double transX, double transY, double transZ);
    std::vector<Triangle> &mTrianglesOfGeometry1;
    std::vector<Triangle> &mTrianglesOfGeometry2;
    Point3D mCenteroidOfGeometry1;
    Point3D mCenteroidOfGeometry2;
    Plane mPlane;
    std::vector<Point3D> mIntersectionPoints;
};
