cases  = int(input(""))
results = []

for i in range (0, cases):
    a, b = input().split()

    if b =="0" :
        results.append("Error Code: integer division or modulo by zero")
    elif b.isdigit() == False or a.isdigit() == False:
        if b.isdigit() == False:
            results.append("Error Code: invalid literal for int() with base 10: '" + b + "'")
        else:
            results.append("Error Code: invalid literal for int() with base 10: '" + a + "'")
    else:
        c = int(a) / int(b) 

        if int(a) % int(b) == 0:
            results.append(int(c))
        else:
            results.append(c)

for i in range (0, cases):
    print(results[i])