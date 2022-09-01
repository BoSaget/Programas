#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void  fibo(int dato);

void main(int argc, char **argv)
{
    int * arreglo;
    int tam;

    if(argc != 2)
    {
        printf("Por favor ingrese los numeros que necesite \n");
    }

    tam = argc -1;
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
        fibo(arreglo[i]);
    }

}

void fibo(int dato)
{
    int numActual = 0;
    int * serie;

    serie = (int *) malloc (dato * sizeof (int));
    serie[0] = 0;
    serie[1] = 1;


    for(int i = 2; i < dato; i++)
    {
        if(numActual < dato)
        {
            numActual = serie[i-2] + serie[i-1];

            printf("%d ", numActual);
            serie[i] = numActual;
        }
        printf("\n");
        exit;
    }
}
