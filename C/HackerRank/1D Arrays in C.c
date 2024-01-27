#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i;
	int n;
	int suma;
    int arreglo[1000];
    
    scanf("%d", &n);
    suma=0;
    
	for(i=0; i<n; i++)
	{
		scanf("%d", &arreglo[i]);
		suma = arreglo[i] + suma;
	}
	
	printf("%d \n", arreglo[4]);
	
	printf("%d", suma);
	 
    return 0;
}
