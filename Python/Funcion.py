from datetime import datetime

def print_time(tarea):
    print(tarea)
    print(datetime.now())
    print()

name=input("")
print_time("Variable guardada")

print ("Hola, " + name)
print_time("Mensaje enviado")