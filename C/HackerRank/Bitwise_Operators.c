#include <stdio.h>

void Operators(int a[], int n, int k)
{
	int an=0,o=0,xo=0,i=0,j=1;

	//AND
	while(i<n)
	{
		if(j==n)
		{
			i++;
			j=i+1;
		}
		
		
		else if(j<n)
		{
			if((a[i]&a[j])>an && (a[i]&a[j])<k)
			{
				an=a[i]&a[j];
			}
			j++;
		}
		
	}
	//OR
	i=0;
	j=1;
	while(i<n)
	{
		if(j==n)
		{
			i++;
			j=i+1;
		}
		
		
		else if(j<n)
		{
			if((a[i]|a[j])>o && (a[i]|a[j])<k)
			{
				o=a[i]|a[j];
			}
			j++;
		}
		
	}
	//XOR
	i=0;
	j=1;
	while(i<n)
	{
		if(j==n)
		{
			i++;
			j=i+1;
		}
		
		
		else if(j<n)
		{
			if((a[i]^a[j])>xo && (a[i]^a[j])<k)
			{
				xo=a[i]^a[j];
			}
			j++;
		}
		
	}

	printf("%d\n%d\n%d\n",an, o, xo);
}

int main (void)
{
	int n,k,i=0;
	
	scanf("%d %d",&n,&k);
	
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	Operators(a,n,k);
	
return 0;
}
