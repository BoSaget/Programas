//autor Tejeda Moyao Leon
#include <stdio.h>
#include <math.h>
int main (void)
{ 	float a;
	float b;
	float c;
	float raiz;
	float x;
	float x1;
	float x2;
	printf ("Formula General \n");
	printf ("Ingrese el valor de a\n");
		scanf ("%f",&a);
	printf ("Ingrese el valor de b\n");
		scanf ("%f",&b);
	printf ("Ingrese el valor de c\n");
		scanf ("%f",&c);
			raiz =( b * b-4*a*c);
				x=pow(raiz,0.5);
					x1=(-b+x)/2*a;
					x2=(-b-x)/2*a;
	printf ("El valor de x1 es igual a %f \n",x1);
	printf ("El valor de x2 es igual a %f \n",x2);
	return 0;
}
