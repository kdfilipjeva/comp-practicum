import numpy as np
import math

def euler_method(f, y0, x0, x_end, h):
    n = int((x_end - x0) / h)
    x = np.linspace(x0, x_end, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        y[i+1] = y[i] + h * f(x[i], y[i])
    return x, y

def f1(x, y):
    return -y * math.tan(x) + math.sin(2*x)

x0, y0 = 0, -1
x_end, h = 1, 0.1

x, y = euler_method(f1, y0, x0, x_end, h)

for xi, yi in zip(x, y):
    print(f"x: {xi:.1f}, y: {yi:.4f}")
