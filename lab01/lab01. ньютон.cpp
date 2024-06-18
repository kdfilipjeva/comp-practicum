#include <iostream>
#include <cmath>
#include <stdexcept>

double f(double x) {
    return exp(-x) - sqrt(x - 1);
}

double f_prime(double x) {
    return -exp(-x) - 1 / (2 * sqrt(x - 1));
}

double newton_raphson(double x0, double epsilon = 1e-6, int max_iterations = 1000) {
    double x = x0;
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        double fx = f(x);
        double fpx = f_prime(x);

        if (std::abs(fpx) < 1e-12) {
            throw std::runtime_error("Производная слишком мала, возможна дивергенция.");
        }

        double x_new = x - fx / fpx;

        // Ensure we don't get into the domain error of sqrt
        if (x_new <= 1) {
            throw std::runtime_error("x_new стало меньше или равно 1, задайте большее начальное приближение.");
        }

        if (std::abs(x_new - x) < epsilon) {
            return x_new;
        }

        x = x_new;
    }

    throw std::runtime_error("Метод Ньютона не сошелся за указанное количество итераций");
}

int main() {
    try {
        double root = newton_raphson(1.1); // Начальное приближение должно быть больше 1, чтобы sqrt(x-1) была определена
        std::cout << "Корень уравнения: " << root << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
