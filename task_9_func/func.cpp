#include "func.hpp"
#include <iostream>
#include <algorithm>
#include <valarray>

namespace matrixNs {

    void readMatrix(std::vector<std::vector<int>>& matrix, int& n) {
        std::cout << "Введите размерность матрицы (n): ";
        std::cin >> n;

        matrix.resize(n, std::vector<int>(n, 0));

        std::cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }

    // Функция проверки наличия дубликатов минимального элемента
    bool hasMinElementDuplicates(const std::vector<std::vector<int>>& matrix, int n) {
        int minElement = matrix[0][0];

        // Находим минимальный элемент
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                minElement = std::min(minElement, matrix[i][j]);
            }
        }

        // Считаем количество вхождений минимального элемента
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minElement) {
                    ++count;
                }
            }
        }

        return count >= 2;
    }

    // Функция проверки, является ли число простым
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }

        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool TwoElemModule(const std::vector<std::vector<int>>& matrix, int n) {

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isPrime(abs(matrix[i][j]))) {
                    count++;
                }
            }
        }

        return count >= 2;
    }

    // Функция упорядочивания строк по убыванию произведений элементов
    void sortRowsByProduct(std::vector<std::vector<int>> &matrix) {
        std::sort(matrix.begin(), matrix.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            int numOne = 1, numTwo = 1;

            // Вычисляем произведение элементов в строке
            for (int i : a) {
                std::cout << i << " ";
                numOne *= i;
            }
            std::cout << "prod a " << numOne << std::endl;

            for (int i : b) {
                numTwo *= i;
                std::cout << i << " ";
            }
            std::cout << "prod B " << numTwo << std::endl;


            return numOne > numTwo;
        });
    }

    // Функция записи матрицы
    void writeMatrix(const std::vector<std::vector<int>>& matrix, int n) {
        std::cout << "Упорядоченная матрица: " << std::endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}
// -5 2 1
// 2 -5 3
// 1 2 3
