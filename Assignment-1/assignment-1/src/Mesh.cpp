#include<vector>
#include<algorithm>
#include<iostream>
#include "../headers/Mesh.h"
#include "../headers/Writer.h"


Mesh::Mesh(std::vector<Triangle> triangles)
{
    mTriangles = triangles;
}

Mesh::~Mesh()
{
}

// Function to check aspect ratio of a triangle...
void Mesh::checkAspectRatio(std::vector<Triangle> triangles)
{
    Writer writer;
    std::vector<Triangle> badTriangle;

    for(Triangle triangle : triangles)
    {
        // Maxium side of a triange...
        double maxSide = std::max({triangle.side1(),triangle.side2(),triangle.side3()});
        //Minimum side of a riangle...
        double minSide = std::min({triangle.side1(),triangle.side2(),triangle.side3()});
        //Asepct ratio
        double aspectRatio = maxSide / minSide;

        if(aspectRatio > 5)
            badTriangle.push_back(triangle);
    }
    std::cout<<"-------------ASPECT RATIO OF TRIANGLE-------------"<<std::endl;
    std::cout<<"No. of not desired triangles : "<<badTriangle.size()<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    writer.write("output/BadAspect.txt",badTriangle);

}

void Mesh::checkSkewnessRatio(std::vector<Triangle> triangles)
{
    Writer writer;
    std::vector<Triangle> badTriangle;
    for(Triangle triangle : triangles)
    {
        double maxAngle = std::max({triangle.angle1(),triangle.angle2(),triangle.angle3()});
        double minAngle = std::min({triangle.angle1(),triangle.angle2(),triangle.angle3()});
        
        double skewnessRatioWithMaxAngle = (maxAngle - 90) / (180 - 90);
        double skewnessRatioWithMinAngle = (90 - minAngle) / 90;
        double skewnessRatio = std::max(skewnessRatioWithMaxAngle , skewnessRatioWithMinAngle);
        
        //Condition for checking skewness ratio....
        if(skewnessRatio >= 0.85 ){
            badTriangle.push_back(triangle);
        }
    }
    std::cout<<"-------------SKEWNESS RATIO OF TRIANGLE-------------"<<std::endl;
    std::cout<<"No. of not desired triangles : "<<badTriangle.size()<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    writer.write("output/BadSkewness.txt",badTriangle);
     
}

