//autor: Tejeda Moyao Leon
#include <stdio.h>
#include <math.h>

int main (void)
{
	int n;
	int x;
	int y;
	int p;
	int s;
	int ra;
	float prom=0;
	int A[100][100];
		A[0][0]=1; A[0][1]=1; A[0][2]=2; A[0][3]=3; A[0][4]=4; A[0][5]=5; A[0][6]=1; A[0][7]=2; A[0][8]=3; A[0][9]=4; A[0][10]=5;
		A[1][0]=2; A[1][1]=1; A[1][2]=3; A[1][3]=5; A[1][4]=4; A[1][5]=3; A[1][6]=1; A[1][7]=1; A[1][8]=1; A[1][9]=4; A[1][10]=5;
		A[2][0]=3; A[2][1]=2; A[2][2]=2; A[2][3]=2; A[2][4]=2; A[2][5]=2; A[2][6]=2; A[2][7]=2; A[2][8]=2; A[2][9]=2; A[2][10]=2;
		

	printf ("Cuantas dimesiones quieres? \n");
	scanf ("%d",&n);
	
	printf ("\n");
	 
	for (x=0; x<3; x++)
	{
		for (y=0; y<11; y++)
		{
			printf ("%d ", A[x][y]);
		}
		printf ("\n");
	}

	for (x=0; x<3; x++)
	{
		for (y=0; y<10; y++)
		{
			s=A[x][y]-A[x+1][y+1];
			p=s*s;
			ra=p*.5;
			prom=ra+prom;
		}
	}
	
	printf ("\n");
	printf ("El promedio es: %f \n",prom);
	

	
return 0;
}
