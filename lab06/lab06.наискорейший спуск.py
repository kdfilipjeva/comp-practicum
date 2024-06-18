import numpy as np
from scipy.optimize import minimize

# Функция
def f(x):
    return x[0] + 2*x[1] + 4*np.sqrt(1 + x[0]**2 + x[1]**2)

# Начальная точка
x0 = np.array([0.0, 0.0])

# Метод наискорейшего спуска
result = minimize(f, x0, method='CG')

print('Оптимальные значения x1 и x2:', result.x)
print('Минимальное значение функции:', result.fun)
