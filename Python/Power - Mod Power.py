number = float(input(""))
power = float(input(""))
module = float(input(""))

#Checa si potencia y numero es entero
if number % int(number) == 0 and power % int(power) == 0:
    number  = int(number) ** int(power)
else:
    number = number ** power

print(number)

#Checa si Modulo y numero es entero
if number % int(number) == 0 and module % int(module) == 0:
    number  = int(number) % int(module)
else:
    number = number % module

print(number)