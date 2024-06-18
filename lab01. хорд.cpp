#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return exp(-x) - sqrt(x - 1);
}

double secant_method(double x0, double x1, double epsilon) {
    int iteration = 0;
    double f_x0 = f(x0);
    double f_x1 = f(x1);

    while (fabs(x1 - x0) > epsilon && !std::isnan(f_x1) && !std::isinf(f_x1)) {
        iteration++;
        double denominator = f_x1 - f_x0;
        if (fabs(denominator) < epsilon) {
            std::cerr << "Denominator too small. Terminating to avoid division by zero." << std::endl;
            break;
        }
        double x2 = x1 - f_x1 * (x1 - x0) / denominator;
        x0 = x1;
        x1 = x2;
        f_x0 = f_x1;
        f_x1 = f(x1);
        std::cout << "Iteration " << iteration << ": x = " << std::setprecision(10) << x1 << ", f(x) = " << f_x1 << std::endl;
    }

    if (std::isnan(f_x1) || std::isinf(f_x1)) {
        std::cerr << "Computation resulted in an invalid number. Terminating." << std::endl;
    }

    return x1;
}

int main() {
    double x0 = 1.0;
    double x1 = 1.1;
    double epsilon = 1e-6;
    double root = secant_method(x0, x1, epsilon);
    std::cout << "Root: " << std::setprecision(10) << root << std::endl;
    return 0;
}
