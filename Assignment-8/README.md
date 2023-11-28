# Assignment 8: Algorithms and Iterators Workshop


# Description
This assignment focuses on understanding and applying algorithms and iterators in C++. It explores the use of standard algorithms provided by 
the Standard Template Library (STL) and the usage of iterators for data manipulation and processing.

**Contents**
1) About Algorithms and Iterators
2) Usage and Characteristics
3) Example Usage
4) How to Run the Examples
5) About Algorithms and Iterators
6) Algorithms: Algorithms in C++ are reusable functions used to perform specific tasks on collections of elements. They are provided by the STL 
and operate on data structures such as vectors, lists, etc.

## Iterators: 
    Iterators are objects used to traverse and manipulate elements within a container.
    They act as pointers pointing to elements in a sequence and provide a way to access elements in a container.

## **Usage and Characteristics**
**Algorithms:**
STL provides a rich set of algorithms like sort, find, transform, etc.<br>
They perform operations on elements within containers and can take iterators as arguments.<br>
**Iterators:**
Different types of iterators (e.g., begin, end, const_iterator) allow various operations on containers.<br>
They support movement through containers and provide access to elements.<br>
##
    ```for (auto it = triangles.begin(); it != triangles.end(); ++it)
  {
    std::cout << (*it).p1().x() << " " << (*it).p1().y() << " " << (*it).p1().z() << std::endl;
    std::cout << (*it).p2().x() << " " << (*it).p2().y() << " " << (*it).p2().z() << std::endl;
    std::cout << (*it).p3().x() << " " << (*it).p3().y() << " " << (*it).p3().z() << std::endl;
  }```
