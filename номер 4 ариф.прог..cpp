//Филипьева Ксения, НБИбд-02-23
//task04.cpp
//Выяснить является ли заданное число n членом арифметической прогрессии, первый член которой равен f, а шаг равен s.
//Эти три числа вводятся с клавиатуры

#include <iostream>

int main() {
    int f, s, n;
    std::cout << "Введите первый член арифметической прогрессии: ";
    std::cin >> f;
    std::cout << "Введите шаг арифметической прогрессии: ";
    std::cin >> s;
    std::cout << "Введите число n: ";
    std::cin >> n;
    if ((n - f) % s == 0) {
        std::cout << "Число " << n << " является членом арифметической прогрессии с первым членом " << f << " и шагом " << s << ".\n";
    } else {
        std::cout << "Число " << n << " не является членом арифметической прогрессии с первым членом " << f << " и шагом " << s << ".\n";
    }
    return 0;
}

