#Филипьева Ксения, НБИбд-02-23 
#task03.ру 
#Вычислить значение z = sign(x) + sign(y), где числа x и y вводятся с клавиатуры, 
#а функция sign(x) и sign(y) определяется таким образом: 


x = float(input("Введите число x: "))
y = float(input("Введите число y: "))

def sign(num):
    if num > 0:
        return 1
    elif num == 0:
        return 0
    else:
        return -1

sign_x = sign(x)
sign_y = sign(y)

z = sign_x + sign_y

print("Значение z =", z)
