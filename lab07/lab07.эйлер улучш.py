import numpy as np
from scipy.optimize import minimize
def improved_euler_method(f, y0, x0, x_end, h):
    n = int((x_end - x0) / h)
    x = np.linspace(x0, x_end, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        k1 = f(x[i], y[i])
        k2 = f(x[i] + h, y[i] + h * k1)
        y[i+1] = y[i] + h * (k1 + k2) / 2
    return x, y

def f2(x, y):
    return (y**2 + x**2 * y) / (x**3)

x0, y0 = 1, 0.5
x_end, h = 2, 0.1

x, y = improved_euler_method(f2, y0, x0, x_end, h)

for xi, yi in zip(x, y):
    print(f"x: {xi:.1f}, y: {yi:.4f}")
