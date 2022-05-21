# Escribe tu código aquí :-)
import machine
import time

# Definimos Funciones
def contador(numero, led):
    for i in range(0, numero):
        led.on()
        time.sleep(1)
        led.off()
        time.sleep(1)
        print(str(i) + "\n")

# Entrada y salida digital
# pines de salida
led_verde = machine.Pin(32, machine.Pin.OUT)

numero = 0
while True:
    if numero == 5:
        print("Entrando en funcion... \n")
        contador(numero, led_verde)
        numero = numero +1

    else:
        led_verde.off()
        numero = numero + 1
    print(str(numero) + "\n")
