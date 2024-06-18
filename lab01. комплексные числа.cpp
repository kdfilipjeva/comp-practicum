#include <iostream>
#include <complex>
#include <cmath>

// Функция для форматирования комплексного числа в строку вида "a + bi"
std::string complexToString(const std::complex<double>& c) {
    std::ostringstream oss;
    oss << c.real();
    if (c.imag() >= 0) {
        oss << " + " << c.imag() << "i";
    } else {
        oss << " - " << -c.imag() << "i";
    }
    return oss.str();
}

int main() {
    // Определение комплексных чисел
    std::complex<double> z1(-1, 1);
    std::complex<double> z2(-3, -1);
    std::complex<double> z3(1, 2);

    // Сумма
    std::complex<double> sum = z1 + z2;
    std::cout << "Сумма: " << complexToString(sum) << std::endl;

    // Разность
    std::complex<double> diff = z1 - z2;
    std::cout << "Разность: " << complexToString(diff) << std::endl;

    // Произведение
    std::complex<double> prod = z1 * z2;
    std::cout << "Произведение: " << complexToString(prod) << std::endl;

    // Частное
    std::complex<double> quot = z1 / z2;
    std::cout << "Частное: " << complexToString(quot) << std::endl;

    // Четвертая степень z3
    std::complex<double> z3_pow4 = std::pow(z3, 4);
    std::cout << "z3 в четвертой степени: " << complexToString(z3_pow4) << std::endl;

    // Корень третьей степени из z3
    std::complex<double> z3_root3 = std::pow(z3, 1.0/3);
    std::cout << "Корень третьей степени из z3: " << complexToString(z3_root3) << std::endl;

    return 0;
}
