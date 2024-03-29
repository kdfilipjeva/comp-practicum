#Филипьева Ксения, НБИбд-02-23 
#task05.ру 
#Даны два массива одного размера, заполненные случайными числами. 
#Получить третий массив, каждый элемент которого равен минимальному из элементов с тем же номером в заданных массивах.

import random

# Генерируем два массива одинакового размера
n = int(input("Введите размер массивов: "))
array1 = [random.randint(1, 100) for _ in range(n)]
array2 = [random.randint(1, 100) for _ in range(n)]

# Создаем третий массив, каждый элемент равен минимальному из элементов с тем же номером в двух других массивах
array3 = [min(array1[i], array2[i]) for i in range(n)]

print("Первый массив:", array1)
print("Второй массив:", array2)
print("Третий массив:", array3)
