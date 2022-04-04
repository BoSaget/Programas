altura, base = input("").split()

base = int(base)
altura = int(altura)

multiplicador = 1
multiplicador_pos = (base//2) - 1
i = 0
j = 0

while(i < altura):
    j = 0
    while (j < base):
        
        #Rombo Arriba
        if(i < altura // 2 and j == (multiplicador_pos)):
            
            for aux in range (0, multiplicador):
                print(".|.", end="")
                j = j + 3
            
            multiplicador = multiplicador + 2
            multiplicador_pos = multiplicador_pos - 3
            
        #Rombo Arriba
        if(i > altura // 2 and j == (multiplicador_pos)):
            
            for aux in range (0, multiplicador):
                print(".|.", end="")
                j = j + 3
            
            multiplicador = multiplicador - 2
            multiplicador_pos = multiplicador_pos + 3
            j = j - 1
        
        #Centro
        elif(i == altura // 2 and j == (base // 2) - 3):
            print("WELCOME", end="")
            j = j + 6
            multiplicador = multiplicador - 2
            multiplicador_pos = multiplicador_pos + 3
          
        #Relleno  
        else:
            print("-", end="")
        
        j += 1
    print("")
    i += 1