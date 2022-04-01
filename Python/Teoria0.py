numero= int(input(""))
residuo = 2
binario = 0

print ("Transformando a binario....")

if numero > 1:
    while numero > 1:
            
        residuo = numero % 2
        numero = numero // 2
            
        if binario == 0:
            binario = str(residuo)
                
        else:
            binario = str(residuo) + binario
    
    binario = str(numero) + binario
            
else:
    binario = str(numero)

print("El Valor Binario de su numero es: " + binario)
