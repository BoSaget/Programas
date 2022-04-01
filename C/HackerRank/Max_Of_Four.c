#include <stdio.h>

void Max_Of_Four(int a, int b, int c, int d)
{
	
	if(a>b && a>c && a>d)
	{
		printf("%d",a);
	}
	
	if(b>c && b>a && b>d)
	{
		printf("%d",b);
	}
	
	if(c>a && c>b && c>d)
	{
		printf("%d",c);
	}
	
	if(d>a && d>b && d>c)
	{
		printf("%d",d);
	}
		

}

int main(void)
{
	int a,b,c,d;

	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	Max_Of_Four(a, b, c, d);
	
return 0;
}
