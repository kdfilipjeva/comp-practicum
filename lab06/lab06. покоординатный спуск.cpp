#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

// Функция для оптимизации
double f(double x1, double x2) {
    return x1 + 5 * x2 + std::exp(x1 * x1 + x2 * x2);
}

// Метод покоординатного спуска
std::vector<double> coordinate_descent(double x1, double x2, double learning_rate, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        // Фиксируем x2, оптимизируем x1
        double grad_x1 = 2 * x1 * std::exp(x1 * x1 + x2 * x2) + 1;
        x1 -= learning_rate * grad_x1;

        // Фиксируем x1, оптимизируем x2
        double grad_x2 = 2 * x2 * std::exp(x1 * x1 + x2 * x2) + 5;
        x2 -= learning_rate * grad_x2;
    }
    return {x1, x2};
}

int main() {
    double x1 = 0.0, x2 = 0.0;
    double learning_rate = 0.01;
    int max_iter = 10000;

    std::vector<double> result = coordinate_descent(x1, x2, learning_rate, max_iter);

    std::cout << "Оптимальные значения x1 и x2: " << result[0] << ", " << result[1] << std::endl;
    std::cout << "Минимальное значение функции: " << f(result[0], result[1]) << std::endl;

    return 0;
}
