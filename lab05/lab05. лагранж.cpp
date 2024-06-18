#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Интерполяция Лагранжа
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double x_star) {
    int n = x.size();
    double y_star = 0;

    for (int i = 0; i < n; ++i) {
        double l_i = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                l_i *= (x_star - x[j]) / (x[i] - x[j]);
            }
        }
        y_star += l_i * y[i];
    }
    return y_star;
}

int main() {
    // Данные
    vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    vector<double> y;
    for (double xi : x) {
        y.push_back(sin(xi));
    }

    // Вычисление значения функции в точке x* = 0.25π
    double x_star = 0.25 * M_PI;
    double y_star = lagrangeInterpolation(x, y, x_star);

    // Истинное значение функции в точке x* = 0.25π
    double y_true = sin(x_star);

    // Вычисление погрешности
    double error = abs(y_true - y_star);

    cout << "Значение интерполяции в точке x* = " << x_star << ": " << y_star << endl;
    cout << "Истинное значение функции в точке x* = " << x_star << ": " << y_true << endl;
    cout << "Погрешность: " << error << endl;

    return 0;
}
