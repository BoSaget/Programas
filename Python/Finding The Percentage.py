estudiantes = []
promedio = []

registros = int(input(""))

for i in range(registros):
    nombre,cal1,cal2,cal3 = input("").split()
    estudiantes.append(nombre)
    
    calificacion = float(cal1) + float(cal2) + float(cal3)
    calificacion = calificacion / 3
    promedio.append(calificacion)

query = input("")

for i in range (0, registros):
    if (query == estudiantes[i]):
        print("{0:.2f}".format(promedio[i]))