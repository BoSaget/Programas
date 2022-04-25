#a = 96 en codigo ASCII

def print_rangoli(size):
    letra = 96 + size
    alto = (size*2)-1
    ancho = (size*4)-3
    mitad = ancho // 2
    cadena = []
    indice = 0
    
    for i in range(0, ancho):
        if(i == mitad):
            cadena.append(chr(letra))
        else:
            cadena.append("-")
    
    for i in range(0, alto):
        for j in range(0, ancho):
            if (indice == 0):
                indice = indice + 1
            else:
                cadena[mitad- (indice * 2)] = chr(letra- indice)
                indice = indice - 1
        
        cadena = "".join(cadena)
        print(cadena)

n = int(input())
print_rangoli(n)