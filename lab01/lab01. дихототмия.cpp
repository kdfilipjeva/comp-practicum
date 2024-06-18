#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return exp(-x) - sqrt(x - 1);
}

double bisection_method(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "Bisection method fails." << std::endl;
        return -1;
    }
    double c = a;
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        }
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a = 1.1, b = 2.0, epsilon = 1e-6;
    double root = bisection_method(a, b, epsilon);
    std::cout << "Корень уравнения: " << std::setprecision(10) << root << std::endl;
    return 0;
}

