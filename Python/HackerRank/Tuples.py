n = int(input(""))
space = list(map(int, input("").split()))

tupla = tuple(space)

print(hash(tupla))
