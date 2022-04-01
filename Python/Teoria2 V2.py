import random

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
    archivo = open("Tarea2 V2.txt", "a")
    
    archivo.write(numero)
    archivo.write(" ,")


def Borrar_Archivo_Existente():
    archivo = open("Tarea2 V2.txt", "w")
    archivo.close()
    

def Universo(k):
    #Numero de combinaciones
    largo = 2 ** k

    for i in range (0,largo):
        num = Trans_Binario(i)
        num = Relleno(num, k)
        Pasar_Archivo(num, i, largo-1)


Borrar_Archivo_Existente()
print("Seleccione una opcion")
print("1. Ingresar un numero \n2. Generar un numero aleatorio entre 0-1000")
op = int(input(""))

if op == 1:
    print("Ingrese el valor del universo")
    num = int(input(""))
    
    archivo = open("Tarea2 V2.txt", "a")
    archivo.write("{")
    for i in range (0,num+1):
        Universo(i)
        archivo.write(" ,")
        

    
elif op == 2:
    
    num = random.randint(0, 10)
    print("Numero aleatorio igual a: " + str(num))
    
    archivo = open("Tarea2 V2.txt", "a")
    archivo.write("{")
    for i in range (0,num+1):
        Universo(i)
        
    archivo.write("}")
    archivo.close()

else:
    print("Ingresar numero valido")