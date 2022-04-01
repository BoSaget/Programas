def get_value(command):
    # E = Empty
    for i in range (0, len(command)):
        if command[i].isdigit() == True:
            if value == "E":
                value = command[i]
            
            else:
                value = value + command[i]

        if command[i] == " ":
            value = "E"

    #print(value)
    return value

def get_position(command):
    # E = Empty
    position = "E"
    for i in range (0, len(command)):
        if command[i].isdigit() == True:
            if position == "E":
                position = command[i]
            
            else:
                position = position + command[i]
        
        elif command[i] == " " and command[i+1].isdigit() == True and position != "E":
            #print(position)
            return position
            



number_of_commands = int(input(""))
lista = []

for x in range (0, number_of_commands):
    command = input("")

    if command[0] == "i" :
        #insert
        value = get_value(command)
        position = get_position(command)    
        lista.insert(int(position), int(value))
    
    if command[0] == "a" :
        #append
        value = get_value(command)
        lista.append(int(value))
    
    if command[0] == "s" :
        #sort
        lista.sort()
    
    if command[0] == "r" :
        #checara si es remove o reverse
        if command[2] == "m":
            #remove
            value = get_value(command)
            lista.remove(int(value))

        
        else:
            #reverse
            lista.reverse()
    
    if command[0] == "p" :
        #checara si es pop o print
        if command[1] == "o":
            #pop
            lista.pop()
        
        else:
            #print
            print(lista)
            