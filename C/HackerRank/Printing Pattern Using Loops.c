#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int i, j, k;
	int n;
	int arreglo[(1000*2)-1];
	
	int inicio;
	int fin;
	
    scanf("%d", &n);
  	

	for(i = 0; i<(n*2)-1; i++)
	{
		arreglo[i]= n;
	}

	inicio=0;
	fin=(n*2)-1;

	for(i = 0; i<(n*2)-1; i++)
	{

		for(j = 0; j<(n*2)-1; j++)
		{
			printf("%d ", arreglo[j]);
		}
		
		
		if(i<n-1)
		{
			inicio ++;
			fin--;
			
			for(k=inicio; k<fin; k ++)
			{
				arreglo[k]--;
			}
		}
		
		
		
		else
		{
			for(k=inicio; k<fin; k ++)
			{
				arreglo[k]++;
			}
			
			inicio--;
			fin++;
		}
		
		
		
		printf("\n");
	}
	
    return 0;
}
