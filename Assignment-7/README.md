# Assignment 7: Genralized capture with initialization

## Overview

In this assignment, a lambda expression named `displayMsg` has been implemented in the `Reader.cpp` file with `Genralized capture with initialization`.

## purpose

```The purpose of this lambda expression is to provide a message indicating that the file was not found.```

## Implementation Steps

1. **Implemented a lambda expression `getTriangles` function in location `Ex6\Updated Sketchees\src\Reader.cpp`**.
   ```
    std::string message="file checking";
    auto printMsgFileNotFound = [message = "File not found"]()mutable
    {
        return message;
    };

2. **Defined `displayMsg` with `Genralized capture with initialization` as `[msg = "File not found"]`**.

3. **the use of this lamda function is to be useful for theb temporary use with the short time.**

4. **This expression returns string to print `File not found` on the console if file was not found.**

```if (!dataFile.is_open())
    {
        std::cout << displayMsg() << std::endl;
        return;
    }```
