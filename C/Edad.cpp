//autor Tejeda Moyao Leon
#include <stdio.h>
#include <math.h>
int main (void)
{
	int e;
	printf ("Hola, por favor ingresa tu edad \n");
	scanf ("%d",&e);
		if (e>60)
	printf ("Estas en la vejez \n");
	{ 	
		if (e>10 && e<18)
		printf ("Estas en la adolcencia \n");
		else
			if (e>18 && e<60)
			printf ("Estas en la adultes \n");
		
		{
			if (e<=5)
			printf("Eres un bebe \n");
			else
				if (e>5 && e<=10)
				printf ("Estas en la ninez \n");			
		}
	}
	
return 0;	
}
