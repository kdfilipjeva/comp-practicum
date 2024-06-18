#include <iostream>
#include <cmath>
#include <iomanip>

// Функция для второго интеграла
double f2(double x) {
    return exp(-2 * x) * sin(9 * x);
}

// Метод прямоугольников
double rectangleMethod(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

// Метод трапеций
double trapezoidMethod(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    return result * h;
}

// Метод Симпсона
double simpsonMethod(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++; // Убедимся, что n четное
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        result += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * f(a + i * h);
    }
    return result * h / 3.0;
}

int main() {
    const double precision = 1e-6;
    const int n = 1000000; // Количество разбиений для достижения требуемой точности

    // Второе задание
    double integral2_rect = rectangleMethod(f2, 0, 100, n); // Интеграл на бесконечности можно аппроксимировать большим числом
    double integral2_trap = trapezoidMethod(f2, 0, 100, n);
    double integral2_simp = simpsonMethod(f2, 0, 100, n);

    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Метод прямоугольников: " << integral2_rect << std::endl;
    std::cout << "Метод трапеций: " << integral2_trap << std::endl;
    std::cout << "Метод Симпсона: " << integral2_simp << std::endl;

    return 0;
}
