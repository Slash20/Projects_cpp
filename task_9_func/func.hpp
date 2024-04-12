#include <vector>


namespace matrixNs {
    void readMatrix(std::vector<std::vector<int>>& matrix, int& n);
    bool hasMinElementDuplicates(const std::vector<std::vector<int>>& matrix, int n);
    bool isPrime(int num);
    bool TwoElemModule(const std::vector<std::vector<int>>& matrix, int n);
    void sortRowsByProduct(std::vector<std::vector<int>> &matrix);
    void writeMatrix(const std::vector<std::vector<int>>& matrix, int n);
}
