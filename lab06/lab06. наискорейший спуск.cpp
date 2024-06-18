#include <iostream>
#include <cmath>
#include <vector>

// Функция для оптимизации
double f(double x1, double x2) {
    return x1 + 2 * x2 + 4 * std::sqrt(1 + x1 * x1 + x2 * x2);
}

// Градиент функции
std::vector<double> gradient(double x1, double x2) {
    double denom = std::sqrt(1 + x1 * x1 + x2 * x2);
    double grad_x1 = 1 + (4 * x1 / denom);
    double grad_x2 = 2 + (4 * x2 / denom);
    return {grad_x1, grad_x2};
}

// Метод наискорейшего спуска
std::vector<double> gradient_descent(double x1, double x2, double learning_rate, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        std::vector<double> grad = gradient(x1, x2);
        x1 -= learning_rate * grad[0];
        x2 -= learning_rate * grad[1];
    }
    return {x1, x2};
}

int main() {
    double x1 = 0.0, x2 = 0.0;
    double learning_rate = 0.01;
    int max_iter = 10000;

    std::vector<double> result = gradient_descent(x1, x2, learning_rate, max_iter);

    std::cout << "Оптимальные значения x1 и x2: " << result[0] << ", " << result[1] << std::endl;
    std::cout << "Минимальное значение функции: " << f(result[0], result[1]) << std::endl;

    return 0;
}
