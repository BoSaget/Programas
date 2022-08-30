#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * fibo(void * dato);

void main(int argc, char **argv)
{
    //Se Declara Hilo
    pthread_t * hilos;
    void * retorno;
    int * datos;

    int * serie;

    int dato;

    //Se solicita cantidad de hilos
    if(argc != 2)
    {
        printf("No ha introducido el número de hilos a crear \n");
        exit(0);
    }

    //printf("Iniciando hilos de manera dinamica \n");
    //Se obtiene cantidad de hilos a usar
    
    int numero_hilos = atoi(argv[1]);

    //Se guarda el espacio de manera dinamicaa
    hilos = (pthread_t *) malloc(numero_hilos * sizeof(pthread_t));
    //Se genera arreglo con el numero de datos a ingresar
    datos = (int * ) malloc (numero_hilos * sizeof (int));

    for(int i = 0; i <numero_hilos; i++)
    {
        printf("Ingrese el valor a buscar \n");
        //Se solicita los valores
        scanf("%d", &dato);
        datos[i] = dato;
    }

    for(int i = 0; i<numero_hilos; i++)
    {
        //Se crea el hilo
        pthread_create(&hilos[i], NULL, fibo, &datos[i]);
    }

    for(int j = 0; j < numero_hilos; j++)
    {
        //Regresa del hilo terminado y obtiene el valor de retorno
        pthread_join(hilos[j], &retorno);
        //Mensaje de confirmación de regreso
        printf("Dato Recibido %s\n", (char * ) retorno);
    }
    
    //Se debe liberar memoria
    free(hilos);

    printf("Fin \n");
}

void * fibo (void * dato)
{
    
    int * valor = (int * ) dato;

    int actual = 0;
    int * arreglo;

    arreglo = (int *) malloc (2 * sizeof(int));
    arreglo[0] = 0;
    arreglo[1] = 1;

    for(int i = 2; i <= *valor;  i++)
    {
        if(actual < *valor)
        {
            actual = arreglo[i-1] + arreglo[i-2];
            arreglo = (int *) malloc (1 * sizeof(int));
            arreglo[i] = actual;
        }
        
    }
    //Termina el hilo y manda el valor de retorno
    pthread_exit((void *) arreglo);
}
