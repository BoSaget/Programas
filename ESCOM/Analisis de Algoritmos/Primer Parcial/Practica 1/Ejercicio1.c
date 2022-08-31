#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generar_arreglo(int pasos);
void analizar_arreglo(int * arreglo, int tam, int *pasos);
void graficar(int pasos, int tam);


int main (void)
{
    int pasos;

    pasos = generar_arreglo(0);

    printf("Número de pasos: %d \n", pasos);
}

int generar_arreglo(int pasos)
{
    int * arreglo;
    int tam;
    int numero;
    int limite;
    pasos++;


    srand(time(NULL));
    pasos++;

    printf("Ingrese el tamaño del arreglo \n");
    scanf("%d", &tam);
    pasos += 2;

    //Se genera arreglo del tamaño indicado
    arreglo = (int *) malloc(tam * sizeof (int));
    pasos++;

    limite = (3*tam) + 1;
    pasos++;

    pasos++;
    for(int i = 0; i < tam; i++)
    {
        pasos++;

        numero = rand() % limite;
        pasos++;

        //printf("Numero: %d generado \n", numero);
        arreglo[i] = numero;
        pasos++;
        printf("--Número: %d ingresado --\n", arreglo[i]);
        pasos++;
    }

    analizar_arreglo(arreglo, tam, &pasos);

    //Se libera memoria
    free(arreglo);
    pasos++;
    pasos++;

    graficar(pasos, tam);

    return pasos;
}

void analizar_arreglo(int * arreglo, int tam, int * pasos)
{
    pasos++;
    //Se analiza la primera mitad del arreglo
    for(int x = 0; x < tam/2; x++)
    {
        pasos+=2;
        //Se analiza la segunda mitad del arreglo
        for(int y = tam/2; y < tam; y++)
        {
            pasos++;

            if(arreglo[x] == arreglo[y])
            {
                pasos++;

                printf("\nDato: %d encontrado en posiciones: %d y %d \n", arreglo[x], x, y );
                pasos+=2;
                return;
            }    
        }
    }
    pasos++;
    printf("\nNo se encontró ningun dato repetido \n");
}

void graficar(int pasos, int tam)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1.csv", "w+");

    fprintf("%d, %d\n", pasos, tam);

    fclose(archivo);
}