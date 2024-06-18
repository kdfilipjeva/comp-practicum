#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Структура для хранения коэффициентов сплайна
struct SplineCoeff {
    double a, b, c, d, x;
};

// Функция для построения кубического сплайна
vector<SplineCoeff> cubicSpline(const vector<double>& x, const vector<double>& y) {
    int n = x.size() - 1;
    vector<double> h(n), alpha(n), l(n+1, 1.0), mu(n), z(n+1), b(n), c(n+1), d(n);

    for (int i = 0; i < n; ++i) {
        h[i] = x[i+1] - x[i];
    }

    for (int i = 1; i < n; ++i) {
        alpha[i] = (3/h[i]) * (y[i+1] - y[i]) - (3/h[i-1]) * (y[i] - y[i-1]);
    }

    for (int i = 1; i < n; ++i) {
        l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    for (int j = n-1; j >= 0; --j) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (y[j+1] - y[j]) / h[j] - h[j] * (c[j+1] + 2 * c[j]) / 3;
        d[j] = (c[j+1] - c[j]) / (3 * h[j]);
    }

    vector<SplineCoeff> splines(n);
    for (int i = 0; i < n; ++i) {
        splines[i] = {y[i], b[i], c[i], d[i], x[i]};
    }

    return splines;
}

// Функция для вычисления значения сплайна в заданной точке
double evaluateSpline(const vector<SplineCoeff>& splines, double x_star) {
    for (const auto& spline : splines) {
        if (spline.x <= x_star && x_star <= spline.x + 1.0) {
            double dx = x_star - spline.x;
            return spline.a + spline.b * dx + spline.c * dx * dx + spline.d * dx * dx * dx;
        }
    }
    return NAN; // Если x_star вне диапазона
}

int main() {
    vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    vector<double> y = {0.0, 0.5, 0.86603, 0.0, 0.86603};

    vector<SplineCoeff> splines = cubicSpline(x, y);

    double x_star = 1.5;
    double y_star = evaluateSpline(splines, x_star);

    cout << "Значение функции в точке x* = " << x_star << ": " << y_star << endl;

    return 0;
}
