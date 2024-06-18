import numpy as np

def progonka(a, b, c, d):
  """
  Реализует метод прогонки для решения трехдиагональной системы линейных уравнений.

  Args:
    a: Нижняя диагональ матрицы.
    b: Главная диагональ матрицы.
    c: Верхняя диагональ матрицы.
    d: Вектор свободных членов.

  Returns:
    Вектор решений.
  """
  n = len(b)
  alpha = np.zeros(n)
  beta = np.zeros(n)
  x = np.zeros(n)

  # Прямой ход
  alpha[0] = -c[0] / b[0]
  beta[0] = d[0] / b[0]
  for i in range(1, n):
    alpha[i] = -c[i] / (b[i] + a[i] * alpha[i - 1])
    beta[i] = (d[i] - a[i] * beta[i - 1]) / (b[i] + a[i] * alpha[i - 1])

  # Обратный ход
  x[n - 1] = beta[n - 1]
  for i in range(n - 2, -1, -1):
    x[i] = alpha[i] * x[i + 1] + beta[i]

  return x

# Задание диагоналей и вектора свободных членов
a = np.array([0, -6, 6, -7, 5])  # Нижняя диагональ
b = np.array([7, 19, -18, -11, -7])  # Главная диагональ
c = np.array([-5, -9, 7, -2, 0])  # Верхняя диагональ
d = np.array([38, 14, -45, 30, 48])  # Вектор свободных членов

# Решение методом прогонки
solution = progonka(a, b, c, d)

print("Решение системы уравнений методом прогонки:")
print(solution)
