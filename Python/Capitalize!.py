def solve(cadena):
    cadena_nueva = list(cadena)
    for i in range(0, len(cadena)):
        if(i == 0):
            if(cadena_nueva[i].isalpha() == True and cadena_nueva[i].isupper() == False):
                letra = cadena_nueva[i]
                cadena_nueva[i] = letra.upper()
                
        elif(cadena_nueva[i-1] == " "):
            if(cadena_nueva[i].isalpha() == True and cadena_nueva[i].isupper() == False):
                letra = cadena_nueva[i]
                cadena_nueva[i] = letra.upper()
                
    cadena = "".join(cadena_nueva)
    return cadena      

cadena = input("")
solve(cadena)
