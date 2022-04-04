from ast import Sub


def count_substring(string, sub_string):
    contador = 0
    repeticiones = 0
    
    for i in range(0, len(string)):
        #print("Letra: " + string[i] + "\n")
        
        if(string[i] == sub_string[0]):
            for j in range (0, len(sub_string)):
                if(i+j < len(string)):
                    if(string[i+j] == sub_string[j]):
                        #print("String: "  + string[i+j] + " Sub: " + sub_string[j] + "\n")
                        contador = contador + 1
                        if (contador == len(sub_string)):
                            contador = 0
                            repeticiones = repeticiones + 1
                    
                    else:
                        #print("No se cumplio")
                        contador = 0
    return repeticiones
                    

string = input("")
sub_string = input("")
repe = count_substring(string, sub_string)
print(repe)