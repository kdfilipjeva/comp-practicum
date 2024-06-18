import numpy as np
from scipy.optimize import minimize

# Функция
def f(x):
    return x[0] + 5*x[1] + np.exp(x[0]**2 + x[1]**2)

# Начальная точка
x0 = np.array([0.0, 0.0])

# Метод покоординатного спуска
result = minimize(f, x0, method='Powell')

print('Оптимальные значения x1 и x2:', result.x)
print('Минимальное значение функции:', result.fun)
