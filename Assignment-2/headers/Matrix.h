#pragma once
#include <vector>
#include "Point3D.h"

class Matrix 
{
public:
    Matrix();
    ~Matrix();
    
    std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector);
    std::vector<std::vector<double>> createScaleMatrix(double scale);
    std::vector<std::vector<double>> createTranslationMatrix(double transX, double transY, double transZ);
    std::vector<std::vector<double>> createIdentityMatrix(int size);
};