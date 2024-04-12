// Вариант 4.


#include <iostream>
#include <cmath>


//bool isPrime(int num) {
//    if (num < 2) {
//        return false;
//    }
//
//    for (int i = 2; i <= sqrt(num); ++i) {
//        if (num % i == 0) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//
//void bubbleSort(int* arr, int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] < arr[j + 1]) {
//                std::swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//
//int main() {
//    system("chcp 65001");
//
//    int n;
//    std::cout << "Введите количество элементов в последовательности: ";
//    std::cin >> n;
//
//
//    int* sequence = new int[n];
//
//    std::cout << "Введите элементы последовательности: " << std::endl;
//    for (int i = 0; i < n; ++i) {
//        std::cin >> sequence[i];
//    }
//
//
//    bool hasPrimes = false;
//    for (int i = 0; i < n; ++i) {
//        if (isPrime(sequence[i])) {
//            hasPrimes = true;
//            break;
//        }
//    }
//
//
//    if (!hasPrimes) {
//        bubbleSort(sequence, n);
//    }
//
//
//    std::cout << "Результат:" << std::endl;
//    for (int i = 0; i < n; ++i) {
//        std::cout << sequence[i] << " ";
//    }
//    std::cout << std::endl;
//
//
//    delete[] sequence;
//
//    return 0;
//}


#include <iostream>

//int main() {
//    system("chcp 65001");
//
//    int n;
//    std::cout << "Введите последовательность n: ";
//    std::cin >> n;
//
//    if (n > 10000) {
//        std::cout << "Последовательность слишком большая!";
//        return 0;
//    }
//
//    // Создаем динамический массив
//    int* sequence = new int[n];
//
//    // Ввод последовательности и проверка на простые числа
//    bool hasPrime = false;
//    for (int i = 0; i < n; i++) {
//        std::cin >> sequence[i];
//
//        if (!hasPrime) {
//            if (sequence[i] > 1) {
//                bool isPrime = true;
//                for (int j = 2; j * j <= sequence[i]; j++) {
//                    if (sequence[i] % j == 0) {
//                        isPrime = false;
//                        break;
//                    }
//                }
//                if (isPrime) {
//                    hasPrime = true;
//                }
//            }
//        }
//    }
//
//    // Если нет простых чисел, упорядочиваем по невозрастанию и выводим
//    if (!hasPrime) {
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (sequence[i] < sequence[j]) {
//                    int temp = sequence[i];
//                    sequence[i] = sequence[j];
//                    sequence[j] = temp;
//                }
//            }
//        }
//    }
//
//    // Вывод последовательности
//    std::cout << "Измененная последовательность: ";
//    for (int i = 0; i < n; i++) {
//        std::cout << sequence[i] << " ";
//    }
//
//    // Освобождаем выделенную память
//    delete[] sequence;
//
//    return 0;
//}


// Вариант 4.


void findAndReplaceMinRow(int** matrix, int rows, int cols) {

    int minRow = 0;
    int minSum = INT_MAX;

    for (int i = 0; i < rows; ++i) {
        int currentSum = 0;
        for (int j = 0; j < cols; ++j) {
            currentSum += matrix[i][j];
        }

        if (currentSum < minSum) {
            minSum = currentSum;
            minRow = i;
        }
    }


    for (int j = 0; j < cols; ++j) {
        matrix[minRow][j] = minSum;
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    system("chcp 65001");
    int rows, cols;

    std::cout << "Введите количество строк и столбцов матрицы: ";
    std::cin >> rows >> cols;


    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }


    std::cout << "Введите элементы матрицы: " << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }


    findAndReplaceMinRow(matrix, rows, cols);


    std::cout << "Измененная матрица: " << std::endl;
    printMatrix(matrix, rows, cols);


//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
    delete[] matrix;

    return 0;
}
