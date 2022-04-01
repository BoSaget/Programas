#include <stdio.h>

int main (void)
{
	int a[2][2];
		a[0][0]=1;
		a[0][1]=3;
		a[1][0]=5;
		a[1][1]=7;
	
	int b[2][2];
		b[0][0]=2;
		b[0][1]=4;
		b[1][0]=6;
		b[1][1]=8;
		
	int c[2][2];
	int x;
	int y;
	
	
	printf ("La Matriz A: \n");
	
	for (x=0; x<2; x++)
	{
		for (y=0; y<2; y++)
		{
			printf ("%d \t",a[x][y]);
		}
		printf ("\n");
	}
	
	printf ("La Matriz B: \n");
	
	for (x=0; x<2; x++)
	{
		for (y=0; y<2; y++)
		{
			printf ("%d \t",b[x][y]);
		}
		printf ("\n");
	}
	
	printf ("EL producto de las dos matrices es: \n");
	for (x=0; x<2; x++)
	{
		for (y=0; y<2; y++)
		{
			c[x][y]=a[x][y]*b[y][x];
			printf ("%d \t",c[x][y]);
		}
		printf ("\n");
	}
	
		
return 0;		
}
