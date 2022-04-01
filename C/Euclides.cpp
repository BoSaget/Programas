//Tejeda Moyao Leon Francisco 1CV8
#include "pila.h"

void euclides (int a, int b)
{
	int q,r;
	
	q=a/b;
	r=a%b;
	if (r==0)
	{
		printf("El minimo MCD es: %d",b);
		exit(-1);
	}
	a=b;
	b=r;
	euclides(a,b);
}

int main(void)
{
	int a, b;
	
	printf ("Ingrese un numero \n");
	scanf("%d",&a);
	printf ("Ingrese otro numero mayor al anterior \n");
	scanf("%d",&b);
	
	euclides(a,b);
	
}
