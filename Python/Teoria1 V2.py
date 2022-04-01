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

def Pasar_Archivo (numero, actual, ultimo):
    archivo = open("Tarea1 V2.txt", "a")
    
    if actual == 0:
        archivo.write("{")
        archivo.write(numero)
        archivo.write(" ,")
    
    elif actual == ultimo:
        archivo.write(numero)
        archivo.write("}")
        archivo.close()
    
    else:
        archivo.write(numero)
        archivo.write(" ,")


def Borrar_Archivo_Existente():
    archivo = open("Tarea1 V2.txt", "w")
    archivo.close()
    

print("Ingrese un numero entre 0-1000")
k = int(input(""))

Borrar_Archivo_Existente()

#Numero de combinaciones
largo = 2 ** k

for i in range (0,largo):
    num = Trans_Binario(i)
    num = Relleno(num, k)
    Pasar_Archivo(num, i, largo-1)