
from hcsr04 import HCSR04
from time import sleep
import machine

def recto(m1der, m2der, m1izq, m2izq, led):
    led.value(1)
    m1der.value(1)
    m2der.value(0)

    m1izq.value(1)
    m2izq.value(0)

def stop(m1der, m2der, m1izq, m2izq, led):
    led.value(0)
    
    m1der.value(0)
    m2der.value(0)

    m1izq.value(0)
    m2izq.value(0)
    
    #sleep(0.5)
  
def giraDerecha(m1der, m2der, m1izq, m2izq, led):
    led.value(1)
    
    m1der.value(0)
    m2der.value(1)

    m1izq.value(1)
    m2izq.value(0)
    
    sleep(0.4)
    stop(m1der, m2der, m1izq, m2izq, led)

def giraIzquierda(m1der, m2der, m1izq, m2izq, led):
    led.value(1)
    
    m1der.value(1)
    m2der.value(0)

    m1izq.value(0)
    m2izq.value(1)
    
    sleep(0.4)
    stop(m1der, m2der, m1izq, m2izq, led)

#Led de salida
led_der = machine.Pin(15, machine.Pin.OUT)
led_cen = machine.Pin(21, machine.Pin.OUT)
led_izq = machine.Pin(13, machine.Pin.OUT)

#Motores 1 es adelante, 2 es atras
motor_der1 = machine.Pin(4, machine.Pin.OUT)
motor_der2 = machine.Pin(19, machine.Pin.OUT)

motor_izq1 = machine.Pin(12, machine.Pin.OUT)
motor_izq2 = machine.Pin(14, machine.Pin.OUT)

# ESP32
sensor_der = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)
sensor_cen = HCSR04(trigger_pin=22, echo_pin=23, echo_timeout_us=10000)
sensor_izq = HCSR04(trigger_pin=25, echo_pin=26, echo_timeout_us=10000)

while True:
  
  distance_der = sensor_der.distance_cm()
  distance_cen = sensor_cen.distance_cm()
  distance_izq = sensor_izq.distance_cm()
  
  while (distance_der > 9):
    sleep(0.4)
    stop(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    giraDerecha(motor_der1, motor_der2, motor_izq1, motor_izq2, led_der)
    
    recto(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    sleep(0.4)
    stop(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    sleep(1)
    
    distance_der = sensor_der.distance_cm()
   
  while (distance_cen < 9 and distance_der < 9):
    sleep(0.4)
    stop(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    giraIzquierda(motor_der1, motor_der2, motor_izq1, motor_izq2, led_izq)
    
    recto(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    sleep(0.4)
    stop(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
    sleep(1)
    
    distance_der = sensor_der.distance_cm()
    distance_cen = sensor_cen.distance_cm()
  
  recto(motor_der1, motor_der2, motor_izq1, motor_izq2, led_cen)
