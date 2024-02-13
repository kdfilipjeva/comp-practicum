#Филипьева Ксения, НБИбд-02-23 
#task01.ру 
#Составить программу для рассчета значений функций 


import math

e = int(input('e: '))
f = int(input('f: '))
g = int(input('g: '))
h = int(input('h: '))

a = math.sqrt(abs(e - (1/f)) + g)
b = math.sin(e) + math.cos(h)
c = (g)/ (e*f-1)

print(f'a = {a}, b = {b}, c = {c}')
