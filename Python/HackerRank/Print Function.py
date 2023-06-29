number = int(input(""))
lista = 0

for x in range(1, number+1):
    if lista == 0:
       lista = "1" 

    else:
        lista = lista + str(x)

print(lista)