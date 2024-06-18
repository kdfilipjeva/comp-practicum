import math

def f(x):
    return math.exp(-x) - math.sqrt(x - 1)

def bisection_method(a, b, epsilon):
    if f(a) * f(b) >= 0:
        print("Bisection method fails.")
        return None
    c = a
    while (b - a) >= epsilon:
        c = (a + b) / 2
        if f(c) == 0.0:
            break
        if f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return c

# Пример использования:
a = 1.1
b = 2.0
epsilon = 1e-6
root = bisection_method(a, b, epsilon)
print(f"Корень уравнения: {root}")

