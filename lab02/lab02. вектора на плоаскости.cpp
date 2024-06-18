#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Структура для представления вектора
struct Vector {
    double x;
    double y;
};

// Функция для генерации случайного вектора
Vector generateRandomVector() {
    Vector v;
    v.x = static_cast<double>(rand()) / RAND_MAX * 20 - 10; // от -10 до 10
    v.y = static_cast<double>(rand()) / RAND_MAX * 20 - 10; // от -10 до 10
    return v;
}

// Функция для вычисления длины вектора
double vectorLength(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Функция для вычисления скалярного произведения двух векторов
double dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// Функция для вычисления угла между двумя векторами
double angleBetweenVectors(const Vector& v1, const Vector& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = vectorLength(v1);
    double len2 = vectorLength(v2);
    return acos(dot / (len1 * len2)) * 180.0 / M_PI;
}

// Функция для вычисления суммы двух векторов
Vector vectorSum(const Vector& v1, const Vector& v2) {
    Vector sum;
    sum.x = v1.x + v2.x;
    sum.y = v1.y + v2.y;
    return sum;
}

// Функция для вычисления разности двух векторов
Vector vectorDifference(const Vector& v1, const Vector& v2) {
    Vector diff;
    diff.x = v1.x - v2.x;
    diff.y = v1.y - v2.y;
    return diff;
}

// Функция для проверки параллельности двух векторов
bool areParallel(const Vector& v1, const Vector& v2) {
    return (v1.x * v2.y - v1.y * v2.x) == 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Генерация трех случайных векторов
    Vector v1 = generateRandomVector();
    Vector v2 = generateRandomVector();
    Vector v3 = generateRandomVector();

    // Вычисление длин векторов
    double length1 = vectorLength(v1);
    double length2 = vectorLength(v2);
    double length3 = vectorLength(v3);

    // Вычисление углов между векторами
    double angle12 = angleBetweenVectors(v1, v2);
    double angle13 = angleBetweenVectors(v1, v3);
    double angle23 = angleBetweenVectors(v2, v3);

    // Вычисление сумм и разностей векторов
    Vector sum12 = vectorSum(v1, v2);
    Vector diff12 = vectorDifference(v1, v2);

    Vector sum13 = vectorSum(v1, v3);
    Vector diff13 = vectorDifference(v1, v3);

    Vector sum23 = vectorSum(v2, v3);
    Vector diff23 = vectorDifference(v2, v3);

    // Проверка параллельности векторов
    bool parallel12 = areParallel(v1, v2);
    bool parallel13 = areParallel(v1, v3);
    bool parallel23 = areParallel(v2, v3);

    // Вывод результатов
    std::cout << "Вектор 1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Вектор 2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "Вектор 3: (" << v3.x << ", " << v3.y << ")\n";

    std::cout << "Длины: " << length1 << ", " << length2 << ", " << length3 << "\n";
    std::cout << "Углы: " << angle12 << " градусов, " << angle13 << " градусов, " << angle23 << " градусов\n";

    std::cout << "Сумма V1 + V2: (" << sum12.x << ", " << sum12.y << ")\n";
    std::cout << "Разность V1 - V2: (" << diff12.x << ", " << diff12.y << ")\n";

    std::cout << "Сумма V1 + V3: (" << sum13.x << ", " << sum13.y << ")\n";
    std::cout << "Разность V1 - V3: (" << diff13.x << ", " << diff13.y << ")\n";

    std::cout << "Сумма V2 + V3: (" << sum23.x << ", " << sum23.y << ")\n";
    std::cout << "Разность V2 - V3: (" << diff23.x << ", " << diff23.y << ")\n";

    std::cout << "Параллельны ли V1 и V2: " << (parallel12 ? "Да" : "Нет") << "\n";
    std::cout << "Параллельны ли V1 и V3: " << (parallel13 ? "Да" : "Нет") << "\n";
    std::cout << "Параллельны ли V2 и V3: " << (parallel23 ? "Да" : "Нет") << "\n";

    return 0;
}
