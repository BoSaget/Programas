#include<stdio.h>

void pointers(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b-*b;
	
	if(*b<0)
	{
		*b=*b * -1;	
	}
}

int main(void)
{
	int a,b;
	
	scanf("%d %d",&a,&b);	
	pointers(&a,&b);
	printf("%d \n%d",a,b);
	
return 0;
}

