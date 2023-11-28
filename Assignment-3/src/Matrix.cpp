#include<math.h>
#include "../headers/Matrix.h"
#include "../headers/Point3D.h"

Matrix::Matrix() 
{
}

Matrix::~Matrix()
{
}

std::vector<double> Matrix::multiplyMatrixVector(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) 
{
    std::vector<double> result(4, 0.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}

std::vector<std::vector<double>> Matrix::createScaleMatrix(double scale)
{
    std::vector<std::vector<double>> scalingMatrix=createIdentityMatrix(4);

    scalingMatrix[0][0] = scale;
    scalingMatrix[1][1] = scale;
    scalingMatrix[2][2] = scale;

    return scalingMatrix;
}

std::vector<std::vector<double>> Matrix::createTranslationMatrix(double transX, double transY, double transZ)
{
    std::vector<std::vector<double>> transMatrix = createScaleMatrix(1);

    transMatrix[0][3] = transX;
    transMatrix[1][3] = transY;
    transMatrix[2][3] = transZ;

    return transMatrix;
}

std::vector<std::vector<double>> Matrix::createIdentityMatrix(int size)
{
    std::vector<std::vector<double>> identityMatrix(size, std::vector<double>(size, 0.0));
    for (int i = 0; i < size; i++) {
        identityMatrix[i][i] = 1.0;
    }
    return identityMatrix;
}

