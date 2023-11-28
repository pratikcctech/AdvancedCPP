# Assignment 6: Implementation of Lambda Function with capture clause and mutable.

## Overview

In this assignment, a lambda expression named `printMsgFileNotFound` has been implemented in the `Reader.cpp` file with capture clause and `mutable` keyword.The purpose of this lambda expression is to provide a message indicating that the file was not found.

## Implementation Steps

1. **Implemented a lambda expression `getTriangles` function in location `Ex6\Updated Sketchees\src\Reader.cpp`**.

   ```std::string msg="Error Msg";
    auto printMsgFileNotFound = [&msg]()mutable
    {
        msg = "File not found";
        return msg;
    };```

2. **We used mutable keyword in order to specify that the variables in the capture clause be `mutable` not `const`**.
3. **Due to mutable keyword the value of string got changed from `std::string msg = "Error msg"`  to `std::msg = "File not found"`**
4. **This expression returns string to print `File not found` on the console if file was not found.**


