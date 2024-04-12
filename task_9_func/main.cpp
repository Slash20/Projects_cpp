#include <iostream>
#include <vector>
#include "func.hpp"


int main() {

    system("chcp 65001");

    int n;
    std::vector<std::vector<int>> matrix;

    matrixNs::readMatrix(matrix, n);

    if (matrixNs::hasMinElementDuplicates(matrix, n) && matrixNs::TwoElemModule(matrix, n)) {
        matrixNs::sortRowsByProduct(matrix);
        matrixNs::writeMatrix(matrix, n);
    } else {
        std::cout << "Нет нужных элементов в матрице." << std::endl;
    }

    return 0;
}
