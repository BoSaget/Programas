import os
import time 
import random

def generar_cadena(no_ficha):
    #Generacion de cadena para el modo aleatorio, estas cadenas seran de largo 10
    #No de Ficha determina si empieza en 1 o en 4, si el valor es False empieza en 1, de lo contrario empieza en 4
    
    aux = []
    cadena = []
    
    for i in range (0, 11):
        aux.insert(i, 0)
        
    if no_ficha == False:
        aux[0] = 1
        
    else:
        aux[0] = 4
    
    for i in range (0,10):
        movimiento = random.randint(1, 5)
        
        while movimiento == 2:
            movimiento = random.randint(1, 5)    
        
        #Generacion de limite para no pasarse de las esquinas    
        if aux[i] == 1:
            
            while movimiento == 3 or movimiento == 2:
                movimiento = random.randint(1, 5)
            
            if movimiento == 1 or movimiento == 4 or movimiento == 5:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
            
        elif aux[i] == 16:
            
            while movimiento == 3 or movimiento == 2:
                movimiento = random.randint(1, 5)
            
            if movimiento == 1 or movimiento == 4 or movimiento == 5:
                aux [i] = aux[i] - movimiento
                aux[i+1] = aux[i]
            
        elif aux[i] == 13:
            while movimiento == 2 or movimiento == 5:
                movimiento = random.randint(1, 4)
            
            if movimiento == 1:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
            elif movimiento == 4 or movimiento == 3:
                aux[i] = aux[i] - movimiento
                aux [i+1] = aux[i]
                
        elif aux[i] == 4:
            while movimiento == 2 or movimiento == 5:
                movimiento = random.randint(1, 4)
            
            if movimiento == 4 or movimiento == 3:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
            elif movimiento == 1:
                aux[i] = aux[i] - movimiento
                aux [i+1] = aux[i]
            
        #Generacion de limite de bordes laterales los numeros 1, 4, 13, 16 ya estan bloqueados por el limite de esquinas 
        elif aux[i] == 5 or aux[i] == 9:
            if movimiento == 5 or movimiento == 1:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
            elif movimiento == 3:
                aux[i] = aux[i] - movimiento
                aux [i+1] = aux[i]
                
            elif movimiento == 4:
                
                multiplicador = random.randint(-1, 1)
                
                while multiplicador == 0:
                    multiplicador = random.randint(-1, 1)
                    
                movimiento = movimiento * multiplicador
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
        
        elif aux[i] == 8 or aux[i] == 12:
            if movimiento == 3:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
            elif movimiento == 5 or movimiento == 1:
                aux[i] = aux[i] - movimiento
                aux [i+1] = aux[i]
            
            elif movimiento == 4:
                
                multiplicador = random.randint(-1, 1)
                
                while multiplicador == 0:
                    multiplicador = random.randint(-1, 1)
                    
                movimiento = movimiento * multiplicador
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
        
        #Generacion de limite de bordes horizontales
        elif aux[i] == 2 or aux[i] == 3:
            if movimiento == 5 or movimiento == 4 or movimiento == 3:
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
            elif movimiento == 1:
                
                multiplicador = random.randint(-1, 1)
                
                while multiplicador == 0:
                    multiplicador = random.randint(-1, 1)
                    
                movimiento = movimiento * multiplicador
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
        
        elif aux[i] == 14 or aux[i] == 15:
            if movimiento == 5 or movimiento == 3 or movimiento == 4:
                aux[i] = aux[i] - movimiento
                aux [i+1] = aux[i]
                
            elif movimiento == 1:
                
                multiplicador = random.randint(-1, 1)
                
                while multiplicador == 0:
                    multiplicador = random.randint(-1, 1)
                    
                movimiento = movimiento * multiplicador
                aux [i] = aux[i] + movimiento
                aux[i+1] = aux[i]
                
        else:
            multiplicador = random.randint(-1, 1)
            while multiplicador == 0:
                multiplicador = random.randint(-1, 1)
                
            movimiento = movimiento * multiplicador
            aux [i] = aux[i] + movimiento
            aux[i+1] = aux[i]
    for i in range(0, 10):
        cadena.insert(i, aux[i])
               
    return cadena    
        
def proceso(cadena1, cadena2):
    
    if cadena2 == '0':
        print("Modo Una Ficha")
        
                
    else:
        print("Modo Dos Fichas")
        primer_turno = random.randint(0, 1)
        
        #Si el valor de primer_turno es igual a 0, va a empezar la ficha1 el juego, de lo contrario la ficha2 va a empezar el juego
        if primer_turno == 0:
            for i in range (0, len(cadena2)):
                print("Ficha1 tiro: " + str(cadena1[i]) + "Ficha2 tiro: " + str(cadena2[i]))
                
        else:
            for i in range (0, len(cadena1)):
                print("Ficha2 tiro: " + cadena2[i] + "Ficha1 tiro: " + cadena1[i])
                
    a=input("")

def ejemplo_tablero():
    
    print ("Puedes usar el ejemplo del tablero para crear tus cadenas")
    
    print("---------------------")
    print("| 1  | 2  | 3  | 4  |")
    print("---------------------")
    print("| 5  | 6  | 7  | 8  |")
    print("---------------------")
    print("| 9  | 10 | 11 | 12 |")
    print("---------------------")
    print("| 13 | 14 | 15 | 16 |")
    print("---------------------")

def automatico(fichas):
    
    os.system("cls")
    if fichas == 1:
        print ("Una Ficha Modo Automatico")
        cadena = generar_cadena(False)
        proceso(cadena, '0')
        
    else:
        print ("Dos Fichas Modo Automatico")
        cadena1 = generar_cadena(False)
        cadena2 = generar_cadena(True)
        proceso(cadena1, cadena2)

def manual(fichas):
    
    os.system("cls")
    if fichas == 1:
        print ("Una Ficha Modo Manual")
        
    else:
        print ("Dos Fichas Modo Manual")
        
    print ("Seleccione una opcion")
    print ("1. Introducir Cadena de Movimientos")
    print ("2. Generar Aleatoriamente la Cadena de Movimientos")
    opcion = int(input(""))
    
    os.system("cls")
    
    if fichas == 1:
        
        if opcion == 1:
            
            print("Una Ficha Modo Manual")
            
            ejemplo_tablero()
            
            print("Introduzca la cadena de movimientos para una ficha")
            cadena = input("")
            
        elif opcion == 2:
            
            print("Una Ficha Modo Manual-Aleatorio")
            cadena = generar_cadena(False)
            
        proceso(cadena, '0')
            
    else:
        
        if opcion == 1:
            
            print("Dos Fichas Modo Manual")
            
            ejemplo_tablero()
            
            print("Introduzca la cadena de movimientos para la primera ficha ficha (Empezando por 1 y Terminando en 16)")
            cadena1 = input("")
            
            print("Introduzca la cadena de movimientos para la segunda ficha ficha ficha (Empezando por 4 y terminando en 13)")
            cadena2 = input("")
            
        elif opcion == 2:
            
            print("Dos Fichas Modo Manual-Aleatorio")
            
            cadena1 = generar_cadena(False)
            
            cadena2 = generar_cadena(True)
            
        proceso(cadena1, cadena2)
    

def menu(fichas):
        
    os.system("cls")
    if fichas == 1:
        print ("Una Ficha")
        
    else:
        print ("Dos Fichas")
        
    print ("Seleccione una opcion")
    print ("1. Modo Automatico")
    print ("2. Modo Manual")
    modo = int(input(""))

    if modo == 1:
        automatico(fichas)
        
    elif modo == 2:
        manual(fichas)
        
    else:
        print ("Opcion invalida, por favor ingrese un opcion valida")
        time.sleep (4)
        
        
ciclo = True

while ciclo ==True:

    print ("Seleccione una opcion")
    print ("1. Una Ficha")
    print ("2. Dos Fichas")
    fichas = int(input(""))

    if fichas == 1 or fichas == 2:
        menu(fichas)
        
    else:
        print ("Opcion invalidad, por favor ingrese un opcion valida")
        time.sleep (4)
        
    os.system("cls")
    
    print("Desea reiniciar el programa")
    print("Presione (y) si desea reinicar, de lo contrario presione (n)")
    fin = input("")
    
    if fin != 'y' and fin != 'Y':
        ciclo = False