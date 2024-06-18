import cmath

# Функция для форматирования комплексного числа в строку вида "a + bi"
def complex_to_string(c):
    real_part = c.real
    imag_part = c.imag
    if imag_part >= 0:
        return f"{real_part} + {imag_part}i"
    else:
        return f"{real_part} - {-imag_part}i"

# Определение комплексных чисел
z1 = complex(-1, 1)
z2 = complex(-3, -1)
z3 = complex(1, 2)

# Сумма
sum_z = z1 + z2
print(f"Сумма: {complex_to_string(sum_z)}")

# Разность
diff_z = z1 - z2
print(f"Разность: {complex_to_string(diff_z)}")

# Произведение
prod_z = z1 * z2
print(f"Произведение: {complex_to_string(prod_z)}")

# Частное
quot_z = z1 / z2
print(f"Частное: {complex_to_string(quot_z)}")

# Четвертая степень z3
z3_pow4 = z3 ** 4
print(f"z3 в четвертой степени: {complex_to_string(z3_pow4)}")

# Корень третьей степени из z3
z3_root3 = z3 ** (1/3)
print(f"Корень третьей степени из z3: {complex_to_string(z3_root3)}")
