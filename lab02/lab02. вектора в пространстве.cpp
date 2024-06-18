#include <iostream>
#include <cmath>
#include <vector>
#include <random>

struct Vector {
    double x, y, z;

    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    double dotProduct(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector crossProduct(const Vector& other) const {
        return Vector(y * other.z - z * other.y,
                      z * other.x - x * other.z,
                      x * other.y - y * other.x);
    }
};

double angleBetween(const Vector& v1, const Vector& v2) {
    double dot = v1.dotProduct(v2);
    double lengths = v1.length() * v2.length();
    return std::acos(dot / lengths);
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);

    // Создание трех случайных векторов
    std::vector<Vector> vectors;
    for (int i = 0; i < 3; ++i) {
        vectors.emplace_back(dis(gen), dis(gen), dis(gen));
    }

    // Нахождение длин каждого вектора
    for (int i = 0; i < 3; ++i) {
        std::cout << "Длина вектора " << i + 1 << ": " << vectors[i].length() << std::endl;
    }

    // Нахождение углов между парами векторов
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            double angle = angleBetween(vectors[i], vectors[j]);
            std::cout << "Угол между вектором " << i + 1 << " и вектором " << j + 1 << ": " << angle << " радиан" << std::endl;
        }
    }

    // Нахождение суммы и разности векторов попарно
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            Vector sum = Vector(vectors[i].x + vectors[j].x, vectors[i].y + vectors[j].y, vectors[i].z + vectors[j].z);
            Vector diff = Vector(vectors[i].x - vectors[j].x, vectors[i].y - vectors[j].y, vectors[i].z - vectors[j].z);
            std::cout << "Сумма вектора " << i + 1 << " и вектора " << j + 1 << ": (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;
            std::cout << "Разность вектора " << i + 1 << " и вектора " << j + 1 << ": (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << std::endl;
        }
    }

    // Проверка, лежат ли векторы в одной плоскости
    Vector cross = vectors[0].crossProduct(vectors[1]);
    bool inPlane = std::abs(cross.dotProduct(vectors[2])) < 1e-6;
    std::cout << "Векторы" << (inPlane ? "" : " не") << " в одной плоскости." << std::endl;

    // Поиск параллельных векторов
    bool parallelFound = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (vectors[i].crossProduct(vectors[j]).length() < 1e-6) {
                std::cout << "Вектор " << i + 1 << " и вектор " << j + 1 << " параллельны." << std::endl;
                parallelFound = true;
            }
        }
    }
    if (!parallelFound) {
        std::cout << "Параллельных векторов не найдено." << std::endl;
    }

    // Нахождение смешанного произведения
    double scalarTripleProduct = vectors[0].dotProduct(vectors[1].crossProduct(vectors[2]));
    std::cout << "Смешанное произведение трех векторов: " << scalarTripleProduct << std::endl;

    return 0;
}
