// Задача 1
#include <iostream>

int main() {
    system("chcp 65001");
    int a, b, c;

    std::cout << "Введите число a большее нуля: ";
    std::cin >> a;

    std::cout << "Введите число b большее нуля: ";
    std::cin >> b;

    std::cout << "Введите число c большее нуля: ";
    std::cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        std::cout << "Введены не натуральные числа!" << std::endl;
        exit(0);
    } else if(a % c == 0 && b % c == 0) {
        std::cout << (a+b)/c << std::endl;
    } else if (a % c == 0 && b % c != 0) {
        std::cout << (a/c)+b << std::endl;
    } else {
        std::cout << a-b-c << std::endl;
    }

    return 0;
}
