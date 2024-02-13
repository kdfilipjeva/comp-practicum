//Филипьева Ксения, НБИбд-02-23 
//task05.cpp 
//Даны два массива одного размера, заполненные случайными числами. 
//Получить третий массив, каждый элемент которого равен минимальному из элементов с тем же номером в заданных массивах.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    int n;
    std::cout << "Введите размер массивов: ";
    std::cin >> n;

    std::vector<int> array1(n);
    std::vector<int> array2(n);
    std::vector<int> array3(n);

    for (int i = 0; i < n; ++i) {
        array1[i] = rand() % 100 + 1; // Random number between 1 and 100
        array2[i] = rand() % 100 + 1; // Random number between 1 and 100
        array3[i] = std::min(array1[i], array2[i]);
    }

    std::cout << "Первый массив:";
    for (int num : array1) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::cout << "Второй массив:";
    for (int num : array2) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::cout << "Третий массив:";
    for (int num : array3) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}

