from matplotlib import pyplot
# Función cuadrática.
def f1(x):
    return 2*(x**2) + 5*x - 2
# Función lineal.
def f2(x):
    return 4*x + 1
# Valores del eje X que toma el gráfico.
x = range(-10, 15)
y = range(1, -10)
# Graficar ambas funciones.
pyplot.plot(x, x)
pyplot.plot(y, y)
# Establecer el color de los ejes.
pyplot.axhline(0, color="black")
pyplot.axvline(0, color="black")
# Limitar los valores de los ejes.
pyplot.xlim(-10, 10)
pyplot.ylim(-10, 10)
# Guardar gráfico como imágen PNG.
pyplot.savefig("output.png")
# Mostrarlo.
pyplot.show()
