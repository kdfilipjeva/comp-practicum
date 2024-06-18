#include <iostream>
#include <cmath>

double g(double x) {
    return exp(-2 * x) + 1;
}

int main() {
    const double epsilon = 1e-6;
    double x0 = 1.5; // начальное приближение
    double x1;

    do {
        x1 = g(x0);
        if (fabs(x1 - x0) < epsilon) break;
        x0 = x1;
    } while (true);

    std::cout << "Корень уравнения: " << x1 << std::endl;

    return 0;
}
