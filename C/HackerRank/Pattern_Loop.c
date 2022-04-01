#include <stdio.h>

int main(void)
{
    int n,i,j,a,aux=1,AUX,N;
    scanf("%d",&n);
    AUX=(n*2)-1;
    N=n;
    for(i=1;i<n*2;i++)
    {
		for(j=1;j<n*2;j++)
    	{
			//Cruz
			if(i==n)
			{
				if(n-j+1>0)
				{
					printf("%d ",n-j+1);
				}
				
				else
				{
					printf("%d ",j-i+1);
				}
				a=1;
			}
			
			else if(j==n)
			{
				if(n-i+1<=0)
				{
					printf("%d ",i-j+1);
				}
				
				else
				{
					printf("%d ",n-i+1);
				}
			}
			
			//Diagonales
			else if(j==aux || i==aux*2)
			{
				if(i>n)
				{
					printf("%d ",a);
				}
				
				else
				{
					printf("%d ",n-i+1);
				}
			}

			else if(j==AUX || i==AUX*2)
			{
				if(i>n)
				{
					printf("%d ",a);
				}
				
				else
				{
					printf("%d ",n-i+1);
				}
			}
			
			//Lo demas exdi
			else
			{
				printf("- ");
			}
		}
		a++;
		aux++;
		AUX--;
		printf("\n");
	}
    
return 0;
}
