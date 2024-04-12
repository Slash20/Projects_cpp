// Лаброраторная работа №7. Массивы
// Вариант 4.

// Подзадача 1. Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
// Если в последовательности
// нет ни одного простого числа, упорядочить последовательность по невозрастанию.

#include <iostream>

int main() {
    system("chcp 65001");

    int n;
    std::cout << "Введите последовательность n";
    std::cin >> n;

    if (n > 10000) {
        std::cout << "Последовательность слишком большая!";
        return 0;
    }

    int sequence[10000];

    // Ввод последовательности и проверка на простые числа
    bool hasPrime = false;
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];

        if (!hasPrime) {
            if (sequence[i] > 1) {
                bool isPrime = true;
                for (int j = 2; j * j <= sequence[i]; j++) {
                    if (sequence[i] % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    hasPrime = true;
                }
            }
        }
    }

    // Если нет простых чисел, упорядочиваем по невозрастанию и выводим
    if (!hasPrime) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sequence[i] < sequence[j]) {
                    int temp = sequence[i];
                    sequence[i] = sequence[j];
                    sequence[j] = temp;
                }
            }
        }
    }

    // Вывод последовательности
    for (int i = 0; i < n; i++) {
        std::cout << sequence[i] << " ";
    }

    return 0;
}



// Подзадача 2.
// Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
// Упорядочить последовательность по неубыванию первой цифры числа,
// числа с одинаковыми первыми цифрами дополнительно упорядочить
// по неубыванию наименьшей цифры числа, числа с одинаковыми первыми цифрами и
// одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.

//int main() {
//    system("chcp 65001");
//
//    int n; // Ввод количества погследовательности
//    std::cin >> n;
//
//    if (n > 1000) {
//        std::cout << "Размер последовательности слишком большой!";
//        return 0;
//    }
//    int values[1000];
//    int firstDigits[1000];
//    int minDigits[1000];
//
//    for (int i = 0; i < n; i++) {
//        std::cin >> values[i];
//        firstDigits[i] = values[i];
//        while (firstDigits[i] >= 10) {
//            firstDigits[i] /= 10;
//        }
//        minDigits[i] = values[i] % 10;
//        int temp = values[i];
//        while (temp >= 10) {
//            temp /= 10;
//            minDigits[i] = std::min(minDigits[i], temp % 10);
//        }
//    }
//
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (firstDigits[j] > firstDigits[j + 1] ||
//                (firstDigits[j] == firstDigits[j + 1] && minDigits[j] > minDigits[j + 1]) ||
//                (firstDigits[j] == firstDigits[j + 1] && minDigits[j] == minDigits[j + 1] && values[j] > values[j + 1])) {
//                // Обмен значений
//                std::swap(values[j], values[j + 1]);
////                int tempValue = values[j];
////                values[j] = values[j + 1];
////                values[j + 1] = tempValue;
//                int tempFirstDigit = firstDigits[j];
//                firstDigits[j] = firstDigits[j + 1];
//                firstDigits[j + 1] = tempFirstDigit;
//                int tempMinDigit = minDigits[j];
//                minDigits[j] = minDigits[j + 1];
//                minDigits[j + 1] = tempMinDigit;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        std::cout << values[i] << " ";
//    }
//
//    return 0;
//}


// Подзадача 3.
// Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку
// с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.

//
//int main() {
//    system("chcp 65001");
//    int n, m;
//    std::cin >> n >> m;
//
//    int matrix[100][100];
//
//    // Ввод матрицы
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            std::cin >> matrix[i][j];
//        }
//    }
//
//    int minSum = INT_MAX; // Начальное значение для наименьшей суммы
//    int minRowIndex = -1; // Индекс строки с наименьшей суммой
//
//    // Находим строку с наименьшей суммой
//    for (int i = 0; i < n; i++) {
//        int rowSum = 0;
//        for (int j = 0; j < m; j++) {
//            rowSum += matrix[i][j];
//        }
//        if (rowSum < minSum) {
//            minSum = rowSum;
//            minRowIndex = i;
//        }
//    }
//    std::cout << minRowIndex << std::endl;
//    std::cout << minSum << std::endl;
//    // Заменяем все элементы этой строки на сумму
//    for (int j = 0; j < m; j++) {
//        matrix[minRowIndex][j] = minSum;
//    }
//
//    // Вывод матрицы
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            std::cout << matrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//
//}

// Подзадача 4.
// Сначала введите последовательность. Затем удалите и продублируйте элементы.
// Затем выведите полученную последовательность (каждый элемент по одному разу).
// Используйте в программе только один массив.

// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
// Удалить из последовательности числа-палиндромы,
// а среди оставшихся продублировать простые числа.

bool isPalindrome(int num) {
    int reversedNum = 0;
    int temp = num;

    while (temp > 0) {
        reversedNum = reversedNum * 10 + temp % 10;
        temp /= 10;
    }

    return num == reversedNum;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i < num / 2 + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {


//    int maxSize = 1000;
//    int mas[maxSize];
//    int n;
//
//    std::cin >> n;
//
//    // Ввод последовательности
//    for (int i = 0; i < n; i++) {
//        std::cin >> mas[i];
//    }
//
//    // Удаление чисел-палиндромов
//    int i = 0;
//    while (i < n) {
//        if (isPalindrome(mas[i])) {
//            for (int j = i; j < n - 1; j++) {
//                mas[j] = mas[j + 1];
//            }
//            n--;
//        } else {
//            i++;
//        }
//    }
//
//    // Дублирование простых чисел
//    i = 0;
//    while (i < n) {
//        if (isPrime(mas[i])) {
//            for (int j = n; j > i; j--) {
//                mas[j] = mas[j - 1];
//            }
//            n++;
//            i++;
//        }
//        i++;
//    }
//
//    // Вывод полученной последовательности
//    for (int i = 0; i < n; i++) {
//        std::cout << mas[i] << " ";
//    }

    return 0;
}

