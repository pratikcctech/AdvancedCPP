# Assignment 13 - Implementation of Interfacing of C++ functions with C code.
## Overview
 
This assignment involves using **C** code to implement specific part of the program.
This is applicable for most of the languages just the keywords or the methods can be different.
The objective is to make the program faster by directly treating a part code as **C** program.
 
## Function Declaration and Definition
 
1. **Function File:**
   - Function declaration: `/src/printLib.h` contains the part of the code which I want to implement as a **C** function but reference it through a **C++** file.
   - I have implemented a macro `#ifdef __cplusplus` which recogns which file the file is being included into, so if it is included in **C++** file, it will run
     `extern "C" {}`.
   - In `/src/printLib.cpp` file we are implementing the `void printMsg()` function.
   ```
   void printMsg()
  {
    printf("Error! File Not Found!\n");
  }
    ```
   - Function `printMsg()` print error message.
 
2. **Usage:**
   - In file `/src/Reader.cpp` above file is included. Function `void Reader::getTriangles(std::vector<Triangle>& triangles)` uses the `void printMsg()` function.
   - When reader is unable to read the file it calls the function and print error on console.
   - Basically the use of the **extern "C"** keyword is to tell the C++ compiler not to do mangling while writing symbols in the **ObjectDump** file.
   - 
