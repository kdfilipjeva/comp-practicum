def series_sum(precision=1e-6):
    sum = 0.0
    k = 1
    while True:
        term1 = 9 / (2 ** (k - 1))
        term2 = (-1) ** (k - 1) / (2 * 3 ** (k - 1))
        term = term1 + term2
        if abs(term) < precision:
            break
        sum += term
        k += 1
    return sum

if __name__ == "__main__":
    precision = 1e-6
    result = series_sum(precision)
    print(f"Сумма ряда с точностью до {precision}: {result:.7f}")
