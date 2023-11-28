# Assignment 9 - Implemetation of sequential containers List, Vector, Deque
 
## Overview
 
This assignment involves use of sequential containers such as list, vector and deque.
 
## Updated Function Definition
 
1. **Function File:**
   - Function Definition: `/src/Reader.cpp` file Reader class object reads the file.
   - The file provided is `.stl` file so the reader reads data of triangles present in the `.stl` file and  stores in the vector of triangles of class triangulation.
   ```
       std::list<Triangle> mTriangles;
   ```
   - Similarly getPoints() method in `/src/Reader.cpp` file also stores Point3D in the file in the vector of points.
   `void Reader::getPoints(std::list<Point3D> &points)`
   - In `/src/Writer.cpp` file `void Writer::write(std::string filePath ,std::list<Triangle>& triangles)`
   function writes Points in the file given as an argument.
 
2. **Usage:**
   - The program reads **.stl** file and returns the points of triangles in the **.txt** file.
   - Reader reads the **.stl** file and writer writes in the **.txt** file.
 
3. **Part 2 and 3**
   - The above steps are equally applicable for other containers such as `std::list` and `std::deque` also.  