#include <stdio.h>

int Left_Rotation(int a[], int n, int d)
{
	int j;
	for(j=d; j<n; j++)
	{
		if(j==n-1)
		{
			printf("%d ",a[j]);
			j=-1;
		}
		
		else if(j==d-1)
		{
			printf("%d ",a[j]);
			return j;
		}
		
		else
		{
			printf("%d ",a[j]);
		}
	}
return j;
}


int main(void)
{
	int n,d,i,dat;
	scanf("%d %d",&n, &d);
	
	int a[n];
	i=0;
	while(i<n)
	{
		scanf("%d",&dat);
		a[i]=dat;
		i++;	
	}
	
	i=Left_Rotation(a, n, d);
	
return 0;
}
