#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euclides(int a, int b);
void graficar(int pasos, int tam);


int main (void)
{
    int pasos;
    int a;
    int b;

    srand(time(NULL));

    for(int i = 1; i <= 10 ; i++)
    {
        a = rand() % 9999;
        b = rand() % 9999;
        printf("Numeros asignados %d y %d \n", a, b);
        pasos = euclides(a, b);
        printf("Número de pasos: %d \n", pasos);
    }
}

int euclides(int a, int b)
{
    int pasos;

    pasos++;
    int mcd;

    pasos++;
    while(b != 0)
    {
        mcd = a % b;
        a = b;
        b = mcd;
        pasos+=3;
    }

    pasos++;
    printf("El mcd fue: %d\n", a);

    pasos++;
    return pasos;  
}

void graficar(int pasos, int tam)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1.csv", "a+");

    fprintf(archivo, "%d, %d \n",pasos, tam);

    fclose(archivo);
}