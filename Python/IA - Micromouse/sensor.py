#Modulo HCSR04 es el sensor sonico exdi
# Complete project details at https://RandomNerdTutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/
from hcsr04 import HCSR04
from time import sleep
import machine

#Led de salida
led_verde = machine.Pin(21, machine.Pin.OUT)
led_rojo = machine.Pin(2, machine.Pin.OUT)

# ESP32
sensor = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)

# ESP8266
#sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)

while True:
    distance = sensor.distance_cm()
    if (distance > 5):
        led_verde.on()
        led_rojo.off()
    else:
        led_verde.off()
        led_rojo.on()
    #print('Distance:', distance, 'cm')
    #sleep(1)
