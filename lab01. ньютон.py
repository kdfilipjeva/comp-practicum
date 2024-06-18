import math


def f(x):
    return math.exp(-x) - math.sqrt(x - 1)


def f_prime(x):
    return -math.exp(-x) - 1 / (2 * math.sqrt(x - 1))


def newton_raphson(x0, epsilon=1e-6, max_iterations=1000):
    x = x0
    for iteration in range(max_iterations):
        fx = f(x)
        fpx = f_prime(x)

        if abs(fpx) < 1e-12:
            print("Производная слишком мала, возможна дивергенция.")
            break

        x_new = x - fx / fpx

        # Ensure we don't get into the domain error of sqrt
        if x_new <= 1:
            print("x_new стало меньше или равно 1, задайте большее начальное приближение.")
            break

        if abs(x_new - x) < epsilon:
            return x_new

        x = x_new

    raise ValueError("Метод Ньютона не сошелся за указанное количество итераций")


try:
    root = newton_raphson(1.1)  # Начальное приближение должно быть больше 1, чтобы sqrt(x-1) была определена
    print(f"Корень уравнения: {root:.6f}")
except ValueError as e:
    print(e)
