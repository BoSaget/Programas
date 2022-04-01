#include "LSE.h"

NODOF * CrearNODOF(NODOF *pol, int dat, int pot, char sig)
{
	NODOF * nuevo=(NODOF*) malloc (sizeof (NODOF));
	nuevo->dato=dat;
	nuevo->potencia=pot;
	nuevo->siguiente=pol;
	nuevo->signo=sig;
	return nuevo;
}

NODOF * BuscarLSE (NODOF *b, float pot)
{
	NODOF *aux;
	for(aux=b; aux; aux=(aux->siguiente))
	{
		if((aux->potencia)==pot)
		{
			return aux;
		}
	}
return NULL;
}

int derivada (NODOF *pol)
{
	float pot, val;
	char sig;
	while(pol != NULL)
	{
		val=(pol->dato)*(pol->potencia);
		pot=(pol->potencia)-1;
		sig=(pol->signo);
		printf("%c %f x^ %f",sig ,val ,pot);
		pol=pol->siguiente;
	}
return 0;
}

int integral (NODOF *pol)
{
	float pot, val;
	char sig;
	while( pol != NULL)
	{
		if((pol->potencia)==-1)
		{
			printf("%c %f ln[x]",sig, val);
			pol=pol->siguiente;
		}
		
		else
		{
			sig=(pol->signo);
			pot=(pol->potencia)+1;
			val=(pol->dato)/(pol->potencia);
			printf("%c %f x^ %f",sig ,val ,pot);
			pol=pol->siguiente;
		}
	}
return 0;
}

int sumapol (NODOF *a, NODOF *b)
{
	float pot, val;
	NODOF *aux;
	char sig;
	while( a !=NULL || b != NULL)
	{
		if((a->signo)=='+' && (b->signo)== '+')
		{
			sig='+';
			pot=(a->potencia);
			aux=BuscarLSE(b, pot);
			val=(a->dato)+(aux->dato);
			printf("%s %f x^%f",sig, val, pot);
			a=a->siguiente;
			b=b->siguiente;
		}
		
		if((a->signo)=='+' && (b->signo)== '-')
		{
			if((a->dato)>(b->dato))
			{
				sig='+';
			}
			
			else
			{
				sig='-';
			}
			
			pot=(a->potencia);
			aux=BuscarLSE(b, pot);
			val=(a->dato)-(aux->dato);
			printf("%s %f x^%f",sig, val, pot);
			a=a->siguiente;
			b=b->siguiente;
		}
		
		if((a->signo)=='-' && (b->signo)== '+')
		{
			if((a->dato)>(b->dato))
			{
				sig='-';
			}
			
			else
			{
				sig='+';
			}
			pot=(a->potencia);
			aux=BuscarLSE(b, pot);
			val=-(a->dato)+(aux->dato);
			printf("%s %f x^%f",sig, val, pot);
			a=a->siguiente;
			b=b->siguiente;
		}
		
		if((a->signo)=='-' && (b->signo)== '-')
		{
			sig='-';
			pot=(a->potencia);
			aux=BuscarLSE(b, pot);
			val=-(a->dato)-(aux->dato);
			printf("%s %f x^%f",sig, val, pot);
			a=a->siguiente;
			b=b->siguiente;
		}
	}
return 0;	
}

int mulpol (NODOF *a, NODOF *b)
{
	float pot, val;
	char sig;
	NODOF * aux;
	
	while(a != NULL)
	{
		for(aux=b; aux; aux=(aux->siguiente))
		{
			val=(a->dato)*(aux->dato);
			pot=(a->potencia)+(aux->potencia);
			if((a->signo)==(aux->signo))
			{
				sig=(a->signo);
			}
			else
			{
				sig='-';
			}
			printf("%c %f x ^ %f",sig, val, pot);
		}
		a=(a->siguiente);
	}
return 0;	
}

void poli()
{
	int op=0;
	float val, pot;
	NODOF *b= NULL;
	NODOF *a= NULL;
	bool re = false;
	char sig, p;
	
	printf ("\t \t Opciones: \n");
	printf ("1- Ingresar Polinomios \n");
	printf ("2- Derivada de un Polinomio \n");
	printf ("3- Integral de un Polinomio \n");
	printf ("4- Suma de dos Polinomios \n");
	printf ("5- Prodcuto de Dos Polinomios \n");
	printf ("6- Salir \n");
	
	while(op>=0 || op<=5)
	{
		printf ("\nElija una Opcion: \n");
		scanf("%d",&op);
		
		if (op==1)
		{
			printf ("\n Ingrese un polino \n");
			while(re==false)
			{
				printf("Ingrese signo \n");
				scanf ("%*c %c", &sig);
				
				printf("Ingrese un numero \n");
				scanf ("%f", &val);
				
				printf("Ingrese la potencia de X \n");
				scanf ("%f", &pot);
				
				a= CrearNODOF(a,val,pot,sig);
				printf ("Si termino de ingresar variables presione (y) de lo contrario presione ENTER\n");
				scanf("%*c %c",&p);
				
				if(p=='y')
				{
					re=true;
				}
			}
			
			re=false;
			printf ("\n Ingrese otro polino \n");
			while(re==false)
			{
				printf("Ingrese signo \n");
				scanf ("%*c %c", &sig);
				
				printf("Ingrese un numero \n");
				scanf ("%f", &val);
				
				printf("Ingrese la potencia de X \n");
				scanf ("%f", &pot);

				b= CrearNODOF(a,val,pot,sig);
				printf ("Si termino de ingresar variables presione (y) de lo contrario presione ENTER\n");
				scanf("%*c %c",&p);
				if(p=='y')
				{
					re=true;
				}
			}
		}
		
		if (op==2)
		{
			printf("\n La derivada del polinomio A es : \n");
			derivada(a);
			printf("\n La derivada del polinomio B es : \n");
			derivada (b);
			
		}
		
		if (op==3)
		{
			printf("\n La integral del polinomio A es : \n");
			integral(a);
			printf("\n La integral del polinomio B es : \n");
			integral(b);
		}
		
		if (op==4)
		{
			printf("\n La suma de los polinomio es: \n");
			sumapol(a,b);
		}
		
		if (op==5)
		{
			printf("\n El producto de los polinomios es: \n");
			mulpol(a,b);
		}
		
		if (op==6)
		{
			exit(-1);
		}
	}
}

int main(void)
{
	poli();
return 0;
}
