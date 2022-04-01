cadena = input("")
numero = 0
posicion = len(cadena)-1

while posicion > -1:
    aux = (len(cadena)-1) - posicion
    if cadena[posicion] == "1" and numero == 0:
        numero = 2 ** aux
    elif cadena[posicion] == "1":
        numero = numero + (2**aux)
        
    posicion = posicion - 1
        
print("El valor decimal del numero binario ingresado es:" + str(numero))
    