#a = 96 en codigo ASCII
def print_rangoli(size):
    letra = 96 + size
    alto = (size*2)-1
    ancho = (size*4)-3
    mitad = ancho // 2
    lista = []
    indice_izq = mitad
    indice_der = mitad
    contador_medio= 0
    contador = 0
    
    for i in range(0, ancho):
        if (i == mitad ):
            lista.append(chr(letra))
        else:
            lista.append("-")
            
    for i in range(0, alto):
        cadena = "".join(lista)
        
        if(i < alto//2):
            contador_medio = contador_medio - 1
            contador = contador + 1
            lista[mitad] = chr(letra + contador_medio)
            
            indice_izq  =  indice_izq - 2
            indice_der  =  indice_der + 2
            for j in range(0, contador):
                lista[indice_der - (2 * j)] = chr(letra - j)
                lista[indice_izq + (2 * j)] = chr(letra - j)
            
                            
        elif(i == alto//2):
            contador_medio = contador_medio + 1
            lista[mitad] = chr(letra + contador_medio)
            
            lista[indice_der] = "-"
            lista[indice_izq] = "-"
            for j in range(0, contador):
                lista[indice_der - (2 * (j + 1 ))] = chr(letra - j) 
                lista[indice_izq + (2 * (j + 1))] = chr(letra - j)
            
        else:
            contador_medio = contador_medio + 1
            contador = contador - 1
            lista[mitad] = chr(letra + contador_medio)
             
            indice_izq  =  indice_izq + 2
            indice_der  =  indice_der - 2
           
            lista[indice_der] = "-"
            lista[indice_izq] = "-"
            
            for j in range(0, contador):
                lista[indice_der - (2 * (j + 1 ))] = chr(letra - j) 
                lista[indice_izq + (2 * (j + 1))] = chr(letra - j)
        print(cadena)

n = int(input())
print_rangoli(n)