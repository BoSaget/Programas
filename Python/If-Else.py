n=int(input(""))

if n%2 > 0:
    print("Weird")

else:
    if n>2 and n<5:
        print("Not Weird")
    elif n>5 and n<21:
        print("Weird")
    else:
        print("Not Weird")