#include <iostream>


int main() {
    system("chcp 65001");
    unsigned int x;
    int i; // Позиция бита (от 0 до 31)

    std::cout << "Введите число x (от 0 до 31): ";
    std::cin >> x;

    std::cout << "Введите позицию i (от 0 до 31): ";
    std::cin >> i;

    if (i >= 0 && i <= 31) {
        x &= ~(1 << i);
        std::cout << "Результат после установки i-го бита в 0: " << x << std::endl;
    } else {
        std::cout << "Неверно введено значение x или i" << std::endl;
        return 0;
    }
}