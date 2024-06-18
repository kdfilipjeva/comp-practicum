import math

def g(x):
    return math.exp(-2 * x) + 1

def find_root(epsilon=1e-6, x0=1.5):
    while True:
        x1 = g(x0)
        if abs(x1 - x0) < epsilon:
            break
        x0 = x1
    return x1

root = find_root()
print(f"Корень уравнения: {root}")
