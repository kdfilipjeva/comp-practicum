//Филипьева Ксения, НБИбд-02-23 
//task03.cpp 
//Вычислить значение z = sign(x) + sign(y), где числа x и y вводятся с клавиатуры, 
//а функция sign(x) и sign(y) определяется таким образом: 

#include <iostream>

int sign(float num) {
    if (num > 0) {
        return 1;
    } else if (num == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    float x, y;
    std::cout << "Введите число x: ";
    std::cin >> x;
    std::cout << "Введите число y: ";
    std::cin >> y;

    int sign_x = sign(x);
    int sign_y = sign(y);
    int z = sign_x + sign_y;

    std::cout << "Значение z = " << z << std::endl;
    return 0;
}

