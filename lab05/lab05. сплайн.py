import numpy as np
from scipy.interpolate import CubicSpline

# Данные
x = np.array([0.0, 1.0, 2.0, 3.0, 4.0])
y = np.array([0.0, 0.5, 0.86603, 0.0, 0.86603])

# Построение кубического сплайна
cs = CubicSpline(x, y, bc_type='natural')

# Вычисление значения функции в точке x* = 1.5
x_star = 1.5
y_star = cs(x_star)

print(f"Значение функции в точке x* = {x_star}: {y_star}")
