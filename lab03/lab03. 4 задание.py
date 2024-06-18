import math
def functional_series_sum(x, precision=1e-6):
    sum = 0.0
    k = 1
    while True:
        term = (-1) ** k / (math.sin(k * x) + 9 + k ** 2)
        if abs(term) < precision:
            break
        sum += term
        k += 1
    return sum

if __name__ == "__main__":
    x = float(input("Введите значение x: "))
    precision = 1e-6
    result = functional_series_sum(x, precision)
    print(f"Сумма функционального ряда при x = {x} с точностью до {precision}: {result:.7f}")
