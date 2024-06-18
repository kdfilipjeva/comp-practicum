import numpy as np

def zeidel_method(A, b, tolerance=0.01):
  """
  Реализует метод Зейделя для решения системы линейных уравнений.

  Args:
    A: Матрица коэффициентов.
    b: Вектор свободных членов.
    tolerance: Точность решения.

  Returns:
    Вектор решений или None, если метод не сошелся.
  """
  n = len(A)
  x = np.zeros(n)  # Инициализация начального приближения
  x_prev = np.zeros(n)
  iterations = 0
  max_diff = tolerance + 1

  while max_diff > tolerance:
    x_prev = x.copy()
    for i in range(n):
      x[i] = b[i]
      for j in range(n):
        if j != i:
          x[i] -= A[i][j] * x[j]
      x[i] /= A[i][i]

    max_diff = np.max(np.abs(x - x_prev))
    iterations += 1

  if iterations < 100:
    print(f"Метод Зейделя сошелся за {iterations} итераций.")
    return x
  else:
    print("Метод Зейделя не сошелся.")
    return None

# Задание матрицы коэффициентов и вектора свободных членов
A = np.array([
    [-24, -6, 4, 7],
    [-8, 21, 4, -2],
    [6, 6, 16, 0],
    [-7, -7, 5, 24]
])
b = np.array([130, 139, 84, -165])

# Решение методом Зейделя
solution = zeidel_method(A, b)

if solution is not None:
  print("Решение системы уравнений методом Зейделя:")
  print(solution)
