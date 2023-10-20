from machine import Pin
import time

while True:
    #Prende el led azul de la ESP
    Pin(2, Pin.OUT).value(1)
    time.sleep(1)
    
    #Apaga el led azul de la ESP
    Pin(2, Pin.OUT).value(0)
    time.sleep(1)
