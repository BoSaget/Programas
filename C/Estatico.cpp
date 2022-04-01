// autor: Tejeda Moyao Leon
#include <stdio.h>

int main (void)
{
	int arr [10];
	int i;
	int m=1;
	int n;
	
	printf ("¿Que tabla de multiplicar quires?");
	scanf ("%d",&n);
	
	for (i=0; i<10; i++)
	{
		arr [i]= n*m;
		printf ("%d \n", arr[i]);
		m=m+1;
	}
	
		
return 0;		
}
