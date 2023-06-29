def wrap (cadena, ancho):  
    parrafo = "0"
    new_line = 0

    for i in range (0, len(cadena)):
        
        if new_line == ancho:
            new_line = 0
            print(parrafo)
            parrafo = "0"

        if parrafo == "0":
            parrafo = cadena [i]
        
        else:
            parrafo = parrafo + cadena[i]

        new_line = new_line + 1
    return parrafo