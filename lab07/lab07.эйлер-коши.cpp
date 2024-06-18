#include <iostream>
#include <vector>
#include <cmath>

double f1(double x, double y) {
    return -y * tan(x) + sin(2 * x);
}

std::vector<double> euler_method(double (*f)(double, double), double y0, double x0, double x_end, double h) {
    int n = (x_end - x0) / h;
    std::vector<double> x(n+1), y(n+1);
    x[0] = x0;
    y[0] = y0;
    for (int i = 0; i < n; ++i) {
        x[i+1] = x[i] + h;
        y[i+1] = y[i] + h * f(x[i], y[i]);
    }
    return y;
}

int main() {
    double x0 = 0, y0 = -1, x_end = 1, h = 0.1;
    auto y = euler_method(f1, y0, x0, x_end, h);

    for (int i = 0; i < y.size(); ++i) {
        std::cout << "x: " << x0 + i*h << ", y: " << y[i] << std::endl;
    }

    return 0;
}
