#include <stdio.h>
#include <stdlib.h>

void imprimir_cadena(char *cadena, int largo, int concatenacion)
{
	int i;
	int j;
	
	printf("Cadena ingresada: ");
	
	for (i=0; i<largo; i++)
	{
		printf("%c", cadena[i]);
	}
	
	printf("\nCadena Invertida: ");
	for (i=largo-1; i>-1; i--)
	{
		printf("%c", cadena[i]);
	}
	
	printf("\nCadena Concatenada: ");
	
	if (concatenacion>0)
	{
		for(j=0; j<concatenacion; j++)
		{
			for (i=0; i<largo; i++)
			{
				printf("%c", cadena[i]);
			}
		}
	}
	
	else if (concatenacion<0)
	{
		for(j=concatenacion; j<0; j++)
		{
			for (i=largo-1; i>-1; i--)
			{
				printf("%c", cadena[i]);
			}
		}
	}
	
	//Cauando la Concatenacion es = 0
	else
	{
		printf("Cadena Vacia");
	}
}

int main (void)
{
	int n;
	int largo;
	largo = 1;
	
	char * cadena;
	char caracter;
	caracter = '0';
	 
	printf ("Practica de Manedjo de Cadenas \n");
	printf ("Ingrese una cadena de entre 1-255 caracteres \n");
	
	//Lee la cadena
	while (caracter != '\n')
	{
		scanf("%c", &caracter);
		
		//No guarda el salto de linea en la cadena
		if(caracter != '\n')
		{
			//Primer dato
			if (largo == 1)
			{
				cadena = (char*) malloc (largo * sizeof(char));
				cadena[largo-1] = caracter;
			}
			
			//Resto de la cadena
			else
			{
				cadena = (char*) realloc (cadena,1);
				cadena[largo-1] = caracter;
			}
			largo++;
		}
	}
	
	printf ("Ingrese el numero de veces que se desea concatenas la cadena \n");
	scanf("%d", &n);
	
	
	imprimir_cadena(cadena, largo-1, n);
	
	free(cadena);
	
return 0;
}
