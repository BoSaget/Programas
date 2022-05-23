#Modulo HCSR04 es el sensor sonico exdi
# Complete project details at https://RandomNerdTutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/
from hcsr04 import HCSR04
from time import sleep
import machine

#Led de salida
led_der = machine.Pin(2, machine.Pin.OUT)
led_izq = machine.Pin(12, machine.Pin.OUT)

# ESP32
sensor_der = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)
sensor_izq = HCSR04(trigger_pin=25, echo_pin=33, echo_timeout_us=10000)

# ESP8266
#sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)

while True:
    distance_der = sensor_der.distance_cm()
    distance_izq = sensor_izq.distance_cm()
    if(distance_der < 5 or distance_izq < 5 ):
        if (distance_der < 5):
            led_der.on()

        else:
            led_der.off()

        if (distance_izq < 5):
            led_izq.on()

        else:
            led_izq.off()

    else:
        led_der.off()
        led_izq.off()
    #print('Distance:', distance, 'cm')
    #sleep(1)
