/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO
	ALUMNO: TEJEDA MOYAO LEON FRANCISCO
	GRUPO:3CV12
	MATERIA:ANALISIS DE ALGORITMOS
	PROFESOR: BENJAMIN LUNA BENOSO
	FECHA:20/DIC/2022
	PRACTICA 5:ALGORITMOS GREEDY
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int * ordenarArreglo(int* C, int tamArreglo)
{
    int aux;
    for(int i=0; i< tamArreglo; i++)
    {
        for(int j=0; j<tamArreglo; j++)
        {
            if(C[j] > C[i])
            {
                aux = C[j];
                C[j] = C[i];
                C[i] = aux;
            }
        }
    }
return C;
}

int *  greedy(int* C, int r, int tamArreglo)
{
    int * S;
    int f, pos, bandera, act, ant, tamS, aux;
    f = r;
    bandera=0;
    pos = 0;
    act = 0;
    ant = 0;
    tamS = 0;
    aux = 0;
    
    //La variable auxiliar indica que ya se recorrió todo el arrelo C
    while(aux < tamArreglo)
    {
        if(C[pos] <= f)
        {
            pos++;
        }
        
        else
        {
            if(tamS == 0)
            {
                S = (int *) malloc(1 * sizeof (int));
                S[tamS] = C[pos-1];
                tamS++;    
            }
            else
            {
                S = (int *) realloc (S, (tamS+1) * sizeof (int));
                S[tamS] = C[pos-1];
                tamS++;
            }
            f = f + C[pos-1];
        }
        
        aux++;
        
    }
return S;
}

int main()
{
    /*
    Crea la r, que es el número de días en el que va a resurtir de fertlizante.
    El rango de este, se encontrará entre 1 y 100
    */
    int r, tamArreglo, d, tamArregloS;
    int *C, *S;
    //El tamaño del arreglo será de 30
    tamArreglo = 30;
    C = (int *) malloc(tamArreglo * sizeof (int));
    
    int Caux [] = {0,29,36,50,52,66,71,85,100,117,127,131};
    
    srand(time(NULL));
    
    for(int i=0; i<1;i++)
    {
        /*
        r = rand() % 100;
        //cout << numero << endl;
        for(int j = 0; j<30 ;j++)
        {
            //Se generan número aleatorios para llenar el arreglo C
            d = rand()%500;
            C[j]=d;
        }
        
        cout << "Arreglo C" << endl;
        for(int j = 0; j <  tamArreglo; j++)
        {
            cout << C[j] << endl;
        }
        
        //Se manda a ordenar el arreglo
        C=ordenarArreglo(C, tamArreglo);
        */
        r=30;
        
        tamArreglo = 12;
        
        S=greedy(Caux, r, tamArreglo);
        
        tamArregloS = sizeof(S)/sizeof(S[0]);
        
        cout << "Arreglo solución" << endl;
        for(int j = 0; j <  tamArregloS; j++)
        {
            cout << S[j] << endl;
        }
    }

    return 0;
}