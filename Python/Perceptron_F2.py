import pandas
import random

def obtener_y(x0, x1, x2, pesos):
    y = (float(x0)*float(pesos[0])) + (float(x1)*float(pesos[1])) + (float(x2)*float(pesos[2]))

    #Funcion de activacion
    if (y >= 0):
        print("De esta iteracion se obtuvievo: " + str(y) + " por lo tanto se le asignara el valor de 1")
        return 1
    else:
        print("De esta iteracion se obtuvievo: " + str(y) + " por lo tanto se le asignara el valor de -1")
        return -1

def reasignacion_pesos(bandera, x0, x1, x2, error, n, pesos):
    pesos[0] = format(float(pesos[0]) + (float(x0[bandera])*error * n), '2f')
    pesos[1] = format(float(pesos[1]) + (float(x1[bandera])*error * n), '2f')
    pesos[2] = format(float(pesos[2]) + (float(x2[bandera])*error * n), '2f')

    return pesos
    

#Extrayendo datos
data = pandas.read_csv("Perceptron_DataSet.csv", names=['x0', 'x1', 'x2', 'y'])
#print(data)

#Definiendo variables 
#----------Pesos----------
#Pesos iniciales del problema
pesos = [0.65, 0.38, 0.33]
#Pesos aletarorios
x = [0.65, 0.38, 0.33]

#for i in range (0, 3):
#    aux = random.random()
#    x[i] = format(aux, '.2f')
#print(x)

#----------Tasa deaprendizaje----------
n = 0.4

#----------Filtrando datos----------
#Extrayendo DataSet

x0 = data['x0']
x1 = data['x1']
x2 = data['x2']
y_des = data['y']

#Bandera para saber en donde estamos
bandera = 1

while bandera < 4:

    print("-----Iteracion numero: " + str(bandera) + "-----")

    y_obt = obtener_y(x0[bandera], x1[bandera], x2[bandera], pesos)

    error = int(y_des[bandera]) - y_obt
    
    if(error == 0):
        print("El error da un valor de: " + str(error) + " por lo tanto es valido")
    else:
        print("El error da un valor de: " + str(error) + " por lo tanto no es valido, se recalcularan los pesos")
        pesos = reasignacion_pesos(bandera, x0, x1, x2, error, n, pesos)
        print("Los nuevos pesos seran: " + str(pesos))
        bandera = 0

    enter = input()

    bandera = bandera + 1


