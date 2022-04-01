// autor: Tejeda Moyao Leon
# include <stdio.h>
# include <stdlib.h>

int main (void)
{
	int n;
	int *arr, x;
	int i;
	int m;
	int N=1;
	
	printf ("¿Que tabla de multiplicar quieres? \n");
	scanf ("%d",&m);
	
	printf ("¿Cuantas veces lo quieres multiplicar? \n");
	scanf ("%d",&n);
	arr = (int *) malloc (n* sizeof (int));
	if (arr != NULL)
	{
		for (i=0; i<n; i++)
		{
			arr [i]=m*N;
			printf ("%d \n", arr[i]);
			N=N+1;
		}
	}

	free (arr);
return 0;
}

