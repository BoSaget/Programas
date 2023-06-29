def mutate_string(string, position, character):
    nueva_string = list(string)
    nueva_string[position] = character

    nueva_string = "".join(nueva_string)
    return nueva_string

string = input("")
position, character = input("").split()
nueva_string = mutate_string(string, int(position), character)
print(str(nueva_string))

