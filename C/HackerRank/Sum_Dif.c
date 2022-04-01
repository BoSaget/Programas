#include <stdio.h>

int main (void)
{
	int i=0;
	float n[2];
	int N[2];
	
	for(i=0;i<2;i++)
	{
		scanf("%d",&N[i]);
	}
	
	for(i=0;i<2;i++)
	{
		scanf("%f",&n[i]);
	}
	
	printf("%d %d\n",N[0]+N[1], N[0]-N[1]);
	printf("%.1f %.1f",n[0]+n[1],n[0]-n[1]);
return 0;
}
