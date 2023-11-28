# Assignment 11 - Use of `std::map` Container in C++ STL
 
## Overview
 
This assignment focuses on the utilization of the `std::map` container in C++ STL. In the `Assignment-11/headers/Triangulation.h` file, a `std::map<Triangle, double> tArea` is declared to store pairs of `Triangle` objects and their areas. The container is populated using the `void Triangulation::setArea()` function. Additionally, two methods are available to retrieve and print the areas:
 
1. **Print Areas:**
   - Method: `void Triangulation::printArea()`
   - Prints the stored areas of triangles to the console.
 
2. **Get Areas:**
   - Method: `std::map<Triangle, double> Triangulation::getArea()`
   - Returns the entire `std::map` containing triangles and their areas.
 
## Implementation 
 
 **Declaration:**
   - File: `Assignment-11/headers/Triangulation.h`
   - Declaration of `std::map<Triangle, double> tArea`.
 
 **Population:**
   - Method: `void Triangulation::setArea()`
   - Populates the `std::map` container with pairs of `Triangle` objects and their areas.
 

 
 **Get Areas:**
   - Method: `std::map<Triangle, double> Triangulation::getArea()`
   - Returns the entire `std::map` containing triangles and their areas.

 **Print Areas:**
   - Method: `void Triangulation::printArea()`
   - Prints the stored areas of triangles to the console.
 
## Usage
 
1. **Instantiate Triangulation:**
   - Instantiate a `Triangulation` object, e.g., `Triangulation triangulation(triangles);`.
 
2. **Print Areas:**
   - Call the `printArea` method to print the stored areas.
     ```cpp
     // Example
     triangulation.printArea();
     ```
 
3. **Get Areas:**
   - Call the `getArea` method to retrieve the entire `std::map` containing triangles and their areas.
## Testing in `main.cpp`
 
```cpp
// main.cpp
 
#include "Triangulation.h"
 
int main() {
    // Create a vector of triangles
    std::vector<Triangle> triangles;
 
    // Create a Triangulation object
    Triangulation triangulation(triangles);
 
    // Print Areas
    triangulation.printArea();
 
    return 0;
}