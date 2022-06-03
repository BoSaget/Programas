import random

def obtener_y(x0, x1, x2, pesos):
    y = (x0*pesos[0]) + (x1*pesos[1]) + (x2*pesos[2])
    #Funcion de activacion
    if (y >= 0):
        print("De esta iteracion se obtuvievo: " + str(y) + " por lo tanto se le asignara el valor de 1")
        return 1
    else:
        print("De esta iteracion se obtuvievo: " + str(y) + " por lo tanto se le asignara el valor de -1")
        return -1

def reasignacion_pesos(x0, x1, x2, error, n, pesos):
    
    pesos[0] = float(format(pesos[0] + (x0 * error * n), '.2f'))
    pesos[1] = float(format(pesos[1] + (x1 * error * n), '.2f'))
    pesos[2] = float(format(pesos[2] + (x2 * error * n), '.2f'))

    return pesos
    
#Definiendo variables 
#----------Pesos----------
#Pesos iniciales del problema
w = [0.65, 0.38, 0.33]
#Pesos aletarorios
#for i in range (0, 3):
#    aux = random.random()
#    x[i] = format(aux, '.2f')
#print(x)

#----------Tasa deaprendizaje----------
n = 0.4

#----------Definiendo DataSet----------
x0 = [1, 1, 1, 1]
x1 = [1, 1, -1, -1]
x2 = [1, -1, 1, -1]
y_des = [1, -1, -1, -1]

#Bandera para saber en donde estamos
bandera = 0

while bandera < 4:

    print("-----Iteracion numero: " + str(bandera + 1) + "-----")
    y_obt = obtener_y(float(x0[bandera]), float(x1[bandera]), float(x2[bandera]), w)

    error = int(y_des[bandera]) - y_obt
    
    if(error == 0):
        print("El error da un valor de: " + str(error) + " por lo tanto es valido")
        bandera = bandera + 1
    else:
        print("El error da un valor de: " + str(error) + " por lo tanto no es valido, se recalcularan los pesos")
        w = reasignacion_pesos(float(x0[bandera]), float(x1[bandera]), float(x2[bandera]), error, n, w)
        print("Los nuevos pesos seran: " + str(w))
        bandera = 0

    enter = input("\nPresione enter para continuar")


