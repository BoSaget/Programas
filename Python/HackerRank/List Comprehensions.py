x = int(input(""))
y = int(input(""))
z = int(input(""))
n = int(input(""))
lista = []
lista2 = []

for i in range(0, x+1):
    for j in range (0, y+1):
        for k in range (0, z+1):
            if (i + j + k != n):
                lista.append(i)
                lista.append(j)
                lista.append(k)
                lista2.append(lista)
                lista = []
print(lista2)