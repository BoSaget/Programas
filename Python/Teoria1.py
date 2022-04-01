def Trans_Binario (numero):
    
    residuo = 2
    binario = 0

    #print ("Transformando a binario....")

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
        
    return binario


def Relleno (cadena, largo):
    
    if(largo == len(cadena)):
        return cadena
    else:
        for x in range (0, largo - len(cadena)):
            cadena = "0" + cadena
            
    return cadena


def Pasar_Archivo (cadenas, ultimo):
    archivo = open("Tarea1.txt", "w")
    archivo.write("{")
    
    for numero in cadenas:
        if ultimo == numero:
            archivo.write(numero)
        
        else:
            archivo.write(numero)
            archivo.write(" ,")
    
    archivo.write("}")
    archivo.close()


k = int(input(""))
cadenas = []
#Cantidad de datos
largo = 2 ** k


if k > 0:    
    print("Calculando todas las cadenas del numero dado")

    for x in range(0, largo):
        cadena = Trans_Binario(x)
        cadena = Relleno(cadena, k)
        cadenas.append(cadena)
        
elif k < 0:
    print ("Numero invalido, favor de ingresar un numero entre 0 y 1000")
    
else:
    cadenas.append("e")
    cadena = "e"

#print(cadenas)
#cadena tiene el ultimo numero
Pasar_Archivo(cadenas, cadena)