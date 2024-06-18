#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция для вычисления определителя матрицы
double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double det = 0;
        for (int i = 0; i < n; ++i) {
            vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (k != i) {
                        submatrix[j - 1][k < i ? k : k - 1] = matrix[j][k];
                    }
                }
            }
            det += pow(-1, i) * matrix[0][i] * determinant(submatrix);
        }
        return det;
    }
}

// Функция для метода Крамера
vector<double> kramerMethod(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    vector<double> solution(n);
    double detA = determinant(A);

    if (detA == 0) {
        cout << "Система не имеет единственного решения." << endl;
        return solution;
    }

    for (int i = 0; i < n; ++i) {
        vector<vector<double>> Ai(A);
        for (int j = 0; j < n; ++j) {
            Ai[j][i] = b[j];
        }
        solution[i] = determinant(Ai) / detA;
    }

    return solution;
}

// Функция для метода Якоби
vector<double> jacobiMethod(const vector<vector<double>>& A, const vector<double>& b, double tolerance = 1e-6) {
    int n = A.size();
    vector<double> x(n, 0);
    vector<double> xPrev(n);
    double maxDiff;
    int iterations = 0;

    do {
        xPrev = x;
        for (int i = 0; i < n; ++i) {
            x[i] = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    x[i] -= A[i][j] * xPrev[j];
                }
            }
            x[i] /= A[i][i];
        }
        maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            maxDiff = max(maxDiff, abs(x[i] - xPrev[i]));
        }
        iterations++;
    } while (maxDiff > tolerance);

    cout << "Число итераций: " << iterations << endl;

    return x;
}

int main() {
    // Задание матрицы коэффициентов и вектора свободных членов
    vector<vector<double>> A = {
            {0, 2, 2},
            {5, -2, 5},
            {2, 2, 5}
    };
    vector<double> b = {-1, 2, 0};

    // Решение методом Крамера
    vector<double> solutionKramer = kramerMethod(A, b);
    cout << "Решение методом Крамера:" << endl;
    for (int i = 0; i < solutionKramer.size(); ++i) {
        cout << "x" << i + 1 << " = " << solutionKramer[i] << endl;
    }

    // Решение методом Якоби
    vector<double> solutionJacobi = jacobiMethod(A, b);
    cout << "Решение методом Якоби:" << endl;
    for (int i = 0; i < solutionJacobi.size(); ++i) {
        cout << "x" << i + 1 << " = " << solutionJacobi[i] << endl;
    }

    return 0;
}
