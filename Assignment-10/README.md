# Assignment 10 - Implemetation of sequential container Deque Part2
 
## Overview
 
This assignment involves use of sequential container deque and string concatenation.
 
## Updated Function Definition
 
1. **Function File:**
   - Function Definition: `Assignment-10/src/Reader.cpp` file Reader class object reads the file.
   - The file provided is `.stl` file so the reader reads data of triangles present in the `.stl` file and  stores in the vector of triangles of class triangulation.
   ```
       std::list<Triangle> mTriangles;
   ```
 
   - In `Assignment-10/src/Writer.cpp` function `Writer::write()` vertex Points are written in the text file separated by space character `" "` ad concatenation.
   - For concatenation purpose, return type double is then converted into string using `std::to_string` function.
    ```
      std::string s1=std::to_string(int(triangle.p1().x()));
      std::string s2=std::to_string(int(triangle.p1().y())); 
      std::string s3=std::to_string(int(triangle.p1().z()));
      std::string s=s1+" "+s2+" "+s3+" ";
      dataFile <<s<< std::endl;
    ```
   - Function `write()`writes Points in the file given as an argument.
 

 
3. **Part2 and 3**
   - The above steps are equally applicable for other containers such as `std::list` and `std::vector` also.  

2. **Usage:**
- The program reads **.stl** file and returns the points of triangles in the **.txt** file.
- Reader reads the **.stl** file and writer writes in the **.txt** file.