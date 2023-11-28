# Assignment 6: Implementation of Lambda Function with capture clause and mutable.

## Overview

In this assignment, a lambda expression named `displayMsg` has been implemented in the `Reader.cpp` file with capture clause and `mutable` keyword.
The purpose of this lambda expression is to provide a message indicating that the file was not found.

## use cases

    whenever you want to create a function that will only contain simple expressions

## Implementation Steps

1. **Implemented a lambda expression for the printing the message .**
    
    **suse of that lamda function was used in `getTriangles` function in location `Assignment-6\src\Reader.cpp`**.

   ```std::string message="Error Message";
    auto printMsgFileNotFound = [&message]()mutable
    {
        message = "File not found";
        return message;
    };```

2. **Due to mutable keyword the value of string got changed from `std::string msg = "file checking"`  to `std::msg = "File not found"`**

3. **i used the `mutable` keyword in the lamda function to be clear about the msg on the lamda function**

4. **This expression returns string to print `File not found` on the console if file was not found.**

    ```if (!dataFile.is_open())
    {
        std::cout << displayMsgFileNotFound() << std::endl;
        return;
    }```


