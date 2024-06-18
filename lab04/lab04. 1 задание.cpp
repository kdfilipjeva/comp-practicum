#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(5) << val << " ";
        }
        cout << endl;
    }
}

// Функция для метода Гаусса
vector<double> gaussMethod(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Прямой ход
    for (int i = 0; i < n - 1; ++i) {
        // Поиск ведущего элемента
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[pivot][i])) {
                pivot = j;
            }
        }

        // Перестановка строк (если необходимо)
        if (pivot != i) {
            swap(matrix[i], matrix[pivot]);
        }

        // Деление строки на ведущий элемент
        double pivotValue = matrix[i][i];
        for (int j = i; j < n + 1; ++j) {
            matrix[i][j] /= pivotValue;
        }

        // Вычитание кратных строк для обнуления элементов под диагональю
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i];
            for (int k = i; k < n + 1; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Обратный ход (обратная подстановка)
    vector<double> solution(n);
    solution[n - 1] = matrix[n - 1][n];
    for (int i = n - 2; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    return solution;
}

// Функция для матричного метода
vector<double> matrixMethod(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Нахождение обратной матрицы A
    vector<vector<double>> AInverse(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                AInverse[i][j] = 1.0;
            } else {
                AInverse[i][j] = 0.0;
            }
        }
    }

    // Метод Гаусса-Жордана для нахождения обратной матрицы
    for (int i = 0; i < n; ++i) {
        // Поиск ведущего элемента
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(A[j][i]) > abs(A[pivot][i])) {
                pivot = j;
            }
        }

        // Перестановка строк (если необходимо)
        if (pivot != i) {
            swap(A[i], A[pivot]);
            swap(AInverse[i], AInverse[pivot]);
        }

        // Деление строки на ведущий элемент
        double pivotValue = A[i][i];
        for (int j = 0; j < n; ++j) {
            A[i][j] /= pivotValue;
            AInverse[i][j] /= pivotValue;
        }

        // Вычитание кратных строк для обнуления элементов над и под диагональю
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = A[j][i];
                for (int k = 0; k < n; ++k) {
                    A[j][k] -= factor * A[i][k];
                    AInverse[j][k] -= factor * AInverse[i][k];
                }
            }
        }
    }

    // Умножение обратной матрицы на вектор свободных членов
    vector<double> solution(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            solution[i] += AInverse[i][j] * b[j];
        }
    }

    return solution;
}

int main() {
    // Задание матрицы коэффициентов и вектора свободных членов
    vector<vector<double>> matrix = {
            {2.0, -7.0, 8.0, -4.0, 57.0},
            {0.0, -1.0, 4.0, -1.0, 24.0},
            {3.0, -4.0, 2.0, -1.0, 28.0},
            {-9.0, 1.0, -4.0, 6.0, 12.0}
    };

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    // Решение методом Гаусса
    vector<double> solutionGauss = gaussMethod(matrix);
    cout << "Решение методом Гаусса:" << endl;
    for (double val : solutionGauss) {
        cout << "x" << solutionGauss.size() - val << " = " << val << endl;
    }


    // Решение матричным методом
    vector<vector<double>> A = {
            {2.0, -7.0, 8.0, -4.0},
            {0.0, -1.0, 4.0, -1.0},
            {3.0, -4.0, 2.0, -1.0},
            {-9.0, 1.0, -4.0, 6.0}
    };
    vector<double> b = {57.0, 24.0, 28.0, 12.0};
    vector<double> solutionMatrix = matrixMethod(A, b);
    cout << "Решение матричным методом:" << endl;
    for (double val : solutionMatrix) {
        cout << "x" << solutionMatrix.size() - val << " = " << val << endl;
    }

    return 0;
}
