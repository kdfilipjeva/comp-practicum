#include <iostream>
#include <cmath>
#include <iomanip>

// Функция для первого интеграла
double f1(double x) {
    return pow(x, 4) / (9 + pow(x, 2));
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

    // Первое задание
    double integral1_rect = rectangleMethod(f1, 1, 2, n);
    double integral1_trap = trapezoidMethod(f1, 1, 2, n);
    double integral1_simp = simpsonMethod(f1, 1, 2, n);

    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Метод прямоугольников: " << integral1_rect << std::endl;
    std::cout << "Метод трапеций: " << integral1_trap << std::endl;
    std::cout << "Метод Симпсона: " << integral1_simp << std::endl;

    return 0;
}
