#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * fibo (void * dato);

void main(int argc, char **argv)
{
    pthread_t * hilos;
    void * retorno;
    int * arreglo;
    int *serie;
    int tam;
    int aux;
    

    //Solicita por lo minimo 1 hilo
    if(argc < 2)
    {
        printf("Por favor ingrese los numeros que necesite \n");
        return;
    }

    tam = argc -1;

    //Se asigna el espacio a los hilos requeridos
    hilos = (pthread_t *) malloc(tam * sizeof (pthread_t));

    //Se asigna el tamaño del arreglo de manera dinamica
    arreglo = (int *) malloc(tam * sizeof (int));


    //Se pasan los valores al arreglo
    for(int i = 0; i < tam; i ++)
    {
        arreglo[i] = atoi(argv[i+1]);
    }

    //Se analiza dato por dato
    for(int i = 0; i<tam; i++)
    {
        //Se crea el hilo
        pthread_create(&hilos[i], NULL, fibo, &arreglo[i]);
    }

    for(int i = 0; i < tam; i++)
    {
        //Termina el hilo y recibe la serie
        pthread_join(hilos[i], &retorno);
        serie = (int *) retorno;

        aux = sizeof(serie) / sizeof(int);


        //Imprime la serie
        printf("Serie Recibida: \n");

        for(int i = 0; i < aux; i++)
        {
            printf("%d ", serie[i]);
        }
        printf("\n");
    
    }
    
    //Se debe liberar memoria
    free(hilos);

    printf("Fin \n");

}

void * fibo(void * datoVoid)
{
    int numActual = 0;
    int * serie;
    int tam;
    int dato = *((int *) datoVoid);


    if(dato < 8)
    {
        //Se cre el espaico necesari, puesot que para los digitos menores a 7 el arreglo es mas grande  que los datos
        serie = (int *) malloc (7 * sizeof (int));
        tam = 7;
    }

    else
    {
        //Se crea el espaico necesario para los datos
        serie = (int *) malloc (dato * sizeof (int));
        tam = dato;
    }

    //Se gebneran los primeros 2 valores
    serie[0] = 0;
    serie[1] = 1;

    if(dato <= 1 && dato > -1)
    {
        tam = 2;
        
        //Se reduce el tamaño del arreglo a los valores justos
        serie = (int * ) realloc (serie, 2 * sizeof (int));
    }

    else
    {
        for(int i = 2; i < tam; i++)
        {
        
        if(numActual >= dato)
        {
            //Se reduce el tamaño del arreglo a los valores justos
            serie = (int * ) realloc (serie, i * sizeof (int));

            //Se guarda el tamaño del arreglo
            tam = i;
        }

        
        numActual = serie[i-2] + serie[i-1];

        //Se guarda el valor de la serie en el arreglo
        serie[i] = numActual;        
        }
    }

    /*
    Se comprueba que la serie este correcta
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", serie[i]);
    }
    printf("\n");
    */

    pthread_exit((void *) serie);
    free(serie);
}
