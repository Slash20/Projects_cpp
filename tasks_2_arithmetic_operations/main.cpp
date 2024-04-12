#include <iostream>

int main() {
    system("chcp 65001");

    int h, a;

    std::cout << "Введите высоту (h): ";
    std::cin >> h;

    std::cout << "Введите сторону треугольника (a): ";
    std::cin >> a;

    if (0 < h && a < 100000000 && h < 100000000) {
        double s = a * h * h; // Формула площади треугольника
        std::cout << "Площадь треугольника равна " << s << std::endl;
    } else {
        std::cout << "Введены некорректные значения" << std::endl;
    }
    return 0;
}
