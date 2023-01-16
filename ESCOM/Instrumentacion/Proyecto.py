from machine import Pin
import time

#Las GPIO son del 36 al 26

while True:
    ## 1110 0001 Temperatura ambiente
    uno = Pin(36, machine.Pin.IN)
    dos = Pin(39, machine.Pin.IN)
    cuatro = Pin(34, machine.Pin.IN)
    ocho = Pin(35, machine.Pin.IN)
    
    diezSeis = Pin(32, machine.Pin.IN)
    treintaDos = Pin(23, machine.Pin.IN)
    sesentaCuatro = Pin(25, machine.Pin.IN)
    cientoVeinteOcho = Pin(26, machine.Pin.IN)
    
    if (uno.value() == 1 and dos.value() == 0 and cuatro.value() == 0 and ocho.value() == 0 and diezSeis.value() == 0 and treintaDos.value() == 1 and cientoVeinteOcho.value() == 1):
        print("No hay humedad, humedad ambiente")
        
    elif (uno.value() == 1 and ocho.value() == 1):
        print("Humedo")
        
    time.sleep(2)
    
    
    




