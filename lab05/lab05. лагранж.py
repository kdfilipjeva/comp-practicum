import numpy as np

# Данные
x = np.array([0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi])
y = np.sin(x)

# Интерполяция Лагранжа
def lagrange_interpolation(x, y, x_star):
    n = len(x)
    y_star = 0
    for i in range(n):
        l_i = 1
        for j in range(n):
            if i != j:
                l_i *= (x_star - x[j]) / (x[i] - x[j])
        y_star += l_i * y[i]
    return y_star

# Вычисление значения функции в точке x* = 0.25π
x_star = 0.25 * np.pi
y_star = lagrange_interpolation(x, y, x_star)

# Истинное значение функции в точке x* = 0.25π
y_true = np.sin(x_star)

# Вычисление погрешности
error = abs(y_true - y_star)

print(f"Значение интерполяции в точке x* = {x_star}: {y_star}")
print(f"Истинное значение функции в точке x* = {x_star}: {y_true}")
print(f"Погрешность: {error}")
