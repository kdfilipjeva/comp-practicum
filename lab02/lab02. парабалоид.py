from sympy import symbols, Eq, solve

# Определение символьных переменных
x, y, z = symbols('x y z')

# Уравнение эллиптического параболоида (пример)
elliptic_paraboloid_eq = Eq(x**2 + y**2 - z, 0)

# Плоскость (пример)
plane_eq = Eq(x + 2*y - z, 5)

# Прямая (пример)
line_eq = Eq(x - 3*y, 1)

# Точка в пространстве (пример)
point = (3, -1, 5)

# Проверка пересечения плоскости и эллиптического параболоида
intersection_plane = solve((elliptic_paraboloid_eq, plane_eq), (x, y, z))

# Проверка принадлежности точки эллиптическому параболоиду
point_check = elliptic_paraboloid_eq.subs({x: point[0], y: point[1], z: point[2]})

# Вывод результатов
print("Пересечение плоскости и эллиптического параболоида:", intersection_plane)
print("Принадлежность точки эллиптическому параболоиду:", point_check)
