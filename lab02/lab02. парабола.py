import math
import random

# Генерация случайных параметров параболы и координат точки
a = random.uniform(1, 10)
b = random.uniform(-10, 10)
c = random.uniform(-10, 10)
point_x = random.uniform(-100, 100)
point_y = random.uniform(-100, 100)

# Функция для проверки принадлежности точки параболе
def belongs_to_parabola(a, b, c, point_x, point_y):
    return point_y == a * point_x ** 2 + b * point_x + c

# Функция для нахождения координат фокуса параболы
def focus_coordinates(a, b, c):
    focus_x = -b / (2 * a)
    focus_y = c - (b ** 2 - 1) / (4 * a)
    return focus_x, focus_y

# Функция для нахождения расстояния от директрисы параболы до фокуса
def distance_to_directrix(a):
    return 1 / (4 * abs(a))

# Проверка принадлежности точки параболе
if belongs_to_parabola(a, b, c, point_x, point_y):
    print("Точка принадлежит параболе.")
else:
    print("Точка не принадлежит параболе.")

# Нахождение координат фокуса параболы
focus_x, focus_y = focus_coordinates(a, b, c)
print("Координаты фокуса параболы:", (focus_x, focus_y))

# Нахождение расстояния от директрисы параболы до фокуса
distance = distance_to_directrix(a)
print("Расстояние от директрисы до фокуса:", distance)
