#include "cola.h"
#include <time.h>
#include "proceso.h"


void insertarproceso(proceso *n, char l, int t, int r)
{
	
	n->tiempo=t;
	n->nm=l;
	n->requer=r;
}


//Procesos
void crearcolap(cp *c)
{
	c->frentep=0;
	c->finalp=0;
}

int colapvacia(cp c)
{
	return(c.frentep==(c.finalp? 1:0));
}

int colapllena(cp c)
{
	return (c.frentep==(c.finalp+1)%TAM? 1:0);
}

void insertarcolap(cp *c, proceso x)
{
	if (colapllena(*c))
	{
		printf ("Error \n");
		exit(-1);
	}
	c->finalp=(c->finalp+1)%TAM;
	c->colap[c->finalp]=x;
} 

proceso quitarcolap(cp *c)
{
	if (colapvacia(*c))
	{
		printf ("Error \n");
		exit (-1);
	}
	c->frentep=(c->frentep+1)%TAM;
	return c->colap[c->frentep];
}

proceso frentecolap(cp c)
{
	if (colapvacia(c))
	{
		printf ("Error \n");
		exit (-1);
	}
	return c.colap[(c.frentep)%TAM];
}

void elmiminarcolap(cp *c)
{
	c->frentep=c->finalp=0;
}

void mostrarproceso(proceso p)
{
	printf("%c \t\t %d \t\t\t %d \n",(p.nm), (p.tiempo), (p.requer));
}


void simulacion(int q, cp a, cp b)
{
	proceso n;
	if(colapllena(a))
	{
		n=quitarcolap(&a);
	}
		
	if(colapllena(b))
	{
		n=quitarcolap(&b);
	}
	n.requer=n.requer-q;
	n.tiempo=n.tiempo;
	n.nm=n.nm;
			
	if (n.requer==0)
	{
		printf ("Proceso %c terminado \n",n.nm);
		n.requer=0;
		n.tiempo=0;
		n.nm=0;
		if(colapvacia(a)&& colapvacia(b))
		{
			printf ("Todos los Procesos terminaron \n");
		}
	}
	else 
	{
		mostrarproceso(n);
		if (colapvacia(a))
		{
			insertarcolap(&a,n);
		}
		
		if (colapvacia(b))
		{
			insertarcolap(&b,n);
		}
	}
	mostrarproceso(	n);
	simulacion (q, a, b);
}


//Round Robin
void robin()
{
	fflush(stdin);
	int o=1;
	int p=0;
	int i=0;
	srand(time(NULL));
	int quantum=rand() % 3+3;
	int req=0;
	char proc[TAM];
	proc[0]='A';
	int aux;
	int time=0;
	int t=0;
	char ent='\n';
	proceso n;
	colap a;
	colap b;
	crearcolap(&a);
	crearcolap(&b);
	
	printf ("1- Cantidad de Procesos \n");
	printf ("2- Cargar Datos y Mostrar Tabla de Procesos \n");
	printf ("3- Emulacion paso a paso \n");
	printf ("4- Emulacion de Procesos \n");
	printf ("5- Salir \n");
	printf ("\n");
	
	while(o<=5 || o>=1)
	{
		printf ("Ingrese una opcion \n");
		scanf("%d",&o);		
		if (o==1)
		{
			printf("¿Cual es la Cantidad de Procesos? \n");
			scanf("%d",&p);
		}
		
		if (o==2)
		{
			printf("Tabla de Procesos \n");
			if(p==0)
			{
				printf ("No ha seleccionado la cantidad de procesos \n");
			}
			else
			{
				printf ("Proceso \t Tiempo de llegada \t Requerimiento CPU (ms) \n");
				for (i=0; i<p; i++)
				{
					aux=proc[i]-'0';
					aux++;
					proc[i+1]=aux+'0';
					req=rand() % 21;
					if (req==0)
					{
						req++;
					}
					insertarproceso(&n,proc[i],time,req);
					insertarcolap(&a,n);
					time++;
					mostrarproceso(n);
				}
			}
		}
		
		if (o==3)
		{
			printf("Emulacion paso a paso \n");
			printf ("Proceso \t Tiempo de llegada \t Requerimiento CPU (ms) \n");
			while(ent=='\n');
			{
				simulacion(quantum, a, b);
				scanf("%c",&ent);
			}
		}
		
		if (o==4)
		{
			printf("Emulacion de Proceso \n");
			printf ("Proceso \t Tiempo de llegada \t Requerimiento CPU (ms) \n");
			simulacion(quantum, a, b);
		}	
		
		if (o==5)
		{
			printf("Saliendo... \n");
			exit (-1);
		}
		
		printf ("\n\n");
	}
}

int main (void)
{
	
	fflush(stdin);
	robin();
	return 0;
}
