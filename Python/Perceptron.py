import pandas as pd
import random

#Extrayendo datos
data = pd.read_csv("Perceptron_DataSet.csv", header=None)
#print(data)

#Definiendo variables 
#----------Pesos----------
#Pesos iniciales del problema
pesos = [0.65, 0.38, 0.33]
#Pesos aletarorios
x = [0, 0, 0]

for i in range (0, 3):
    aux = random.random()
    x[i] = format(aux, '.2f')
#print(x)

#----------Tasa deaprendizaje----------
n = 0.4

#----------Filtrando datos----------
#Extrayendo DataSet
x0 = pd.read_csv("Perceptron_DataSet.csv")
print(x0.tail())
