#!/usr/bin/python2.7
#Autor: Ismael Lopez Larumbe
#Sistemas Operativos
import numpy as np
import matplotlib.pyplot as plt
import skimage.io as io
import os
from os import getcwd
from scandir import scandir
from copy import deepcopy

def separar(str_imagen):

    imagen = io.imread("origen/"+str_imagen)
    canal_rojo = deepcopy(imagen)
    canal_verde = deepcopy(imagen)
    canal_azul = deepcopy(imagen)

    canal_rojo[:,:,1]=0
    canal_rojo[:,:,2]=0

    canal_verde[:,:,0]=0
    canal_verde[:,:,2]=0

    canal_azul[:,:,0]=0
    canal_azul[:,:,1]=0

    nombre=str_imagen.split('.')[0]
    io.imsave("resultados/"+nombre+"_rojo.png",canal_rojo)
    io.imsave("resultados/"+nombre+"_verde.png",canal_verde)
    io.imsave("resultados/"+nombre+"_azul.png",canal_azul)


def ls(ruta = getcwd()):
    return [arch.name for arch in scandir(ruta) if arch.is_file()]


nombres = ls("/home/raderly/SO/imagenes_py/origen")
print(nombres)
print("Imagenes disponibles: "+str(len(nombres)))

while(True):
    nproc=int(raw_input("Numero de procesos: "))
    if(nproc > len(nombres)):
        print("----Imagenes insuficientes----")
    else:
        break

for i in range(nproc):
    hijo=os.fork()
    if hijo == 0:
        separar(nombres[i]);
        break
    elif hijo > 0:
        print("iteracion "+str(i))
    else:
        print("Error")

if hijo>0:
    for i in range(nproc):
        print("Esperando")
        os.wait()