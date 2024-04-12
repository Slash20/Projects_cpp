#include <iostream>
#include <vector>


int main() {

    int n = 10;


    std::vector<int> arr(n);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    arr.push_back(6);



//    for (int i = 0; i < arr.size(); ++i) {
//        std::cout << arr[i] << std::endl;
//    }

// 1. За счет каких средств языка С++ получается изменять длину массива std::vector?

//    arr.resize(10);
//    arr.clear();
//    arr.insert(arr.begin() + 1, 3); // Вставка элемента
//    arr.erase(arr.begin() + 2); // Удаление по индексу
//    arr.pop_back(); // Удаление из конца
//    arr.push_back(23); // Добавление в конец

// 2. Что такое capacity и чем оно отличается от size? Что делает shrink_to_fit, resize, reserve?

// arr.size() - текущее кол-во реальных объектов
// arr.capacity(); - это кол-во объектов, под которые зарезервирована память.

//arr.shrink_to_fit() - уменьшает capacity до size
//arr.resize() - устанавливает новый размер вектора
//arr.reserve() - увеличивает capacity, но не изменяет size

// 3. Что обозначают знаки < и > при создании std::vector?

//Знаки < и > при создании std::vector означают создание так называемого "шаблона"

// 4. Продемонстрируйте работу push_back, erase, insert, clear.

// arr.push_back(4); Добавление в конец вектора элемент
//    for (int i = 0; i < arr.size(); ++i) {
//        std::cout << arr[i] << std::endl;
//    }

// arr.erase(arr.begin() + 2); Удаление по индексу
//    for (int i = 0; i < arr.size(); ++i) {
//        std::cout << arr[i] << std::endl;
//    }

// arr.insert(arr.begin() + 1, 5); // Вставка элемента перед вторым
//    for (int i = 0; i < arr.size(); ++i) {
//        std::cout << arr[i] << std::endl;
//    }

//arr.clear(); // Очищает вектор

//   5. В чем отличие функции at и []? И почему в С++ сделали именно так?

//    for (unsigned i=0; i<arr.size(); i++)
//        std::cout << arr.at(i);


    std::cout << arr.at(10001);
    std::cout << arr[10001];


//    for (unsigned i=0; i<arr.size(); i++)
//        std::cout << ' ' << arr.at(i);
//    std::cout << '\n';


    return 0;
}
