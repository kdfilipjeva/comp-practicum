#include <iostream>
#include <vector>
#include <cmath>

double f2(double x, double y) {
    return (y*y + x*x * y) / (x*x*x);
}

std::vector<double> improved_euler_method(double (*f)(double, double), double y0, double x0, double x_end, double h) {
    int n = (x_end - x0) / h;
    std::vector<double> x(n+1), y(n+1);
    x[0] = x0;
    y[0] = y0;
    for (int i = 0; i < n; ++i) {
        x[i+1] = x[i] + h;
        double k1 = f(x[i], y[i]);
        double k2 = f(x[i] + h, y[i] + h * k1);
        y[i+1] = y[i] + h * (k1 + k2) / 2;
    }
    return y;
}

int main() {
    double x0 = 1, y0 = 0.5, x_end = 2, h = 0.1;
    auto y = improved_euler_method(f2, y0, x0, x_end, h);

    for (int i = 0; i < y.size(); ++i) {
        std::cout << "x: " << x0 + i*h << ", y: " << y[i] << std::endl;
    }

    return 0;
}
