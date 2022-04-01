#include "pila.h"

struct Pila * Insertar(struct Pila * Mi_Pila, char dato)
{	
	struct Pila * Aux;
	Aux=Mi_Pila;
	struct Pila * Nuevo;
	Nuevo=malloc(sizeof(struct Pila));
	Nuevo->dato=dato;
	Nuevo->Siguiente=Mi_Pila;
	Mi_Pila=Nuevo;
	
	if(Aux == NULL)
	{
		Mi_Pila->Fin=Nuevo;
	}
	
	Mi_Pila->Tope=Nuevo;
	
return Mi_Pila;
}

void Mostrar_Tope(struct Pila * Mi_Pila)
{
	if(Mi_Pila == NULL)
	{
		printf("La Pila esta Vacia");
	}
	else
	{
		printf("%d",Mi_Pila->Tope->dato);
	}
}

struct Pila * Eliminar_Tope(struct  Pila * Mi_Pila)
{
	struct Pila * Aux;
	Aux=Mi_Pila;
	
	if(Mi_Pila == NULL)
	{
		printf("La Pila esta Vacia, No se pueden eliminar datos");
	}
	
	else
	{
		Mi_Pila->Tope=Aux->Siguiente;
		Mi_Pila=Mi_Pila->Siguiente;
		Aux->Siguiente=NULL;
	}
	
return Mi_Pila;
}

struct Pila * cambio_de_notacion(char * infija, int largo)
{
	struct Pila * simbolo;
	simbolo=NULL;
	
	struct Pila * operador;
	operador=NULL;
	
	struct Pila * aux;
	aux=NULL;
	
	int i;
	
	for (i=0; i<largo; i++)
	{
		if(infija[i] == '(') 
		{
			operador=Insertar(operador, infija[i]);
		}
		
		else if (infija[i] == ')')
		{
			while(operador->Tope->dato != '(')
			{
				simbolo=Insertar(simbolo, operador->Tope->dato);
				operador=Eliminar_Tope(operador);
			}
			operador=Eliminar_Tope(operador);
		}
		
		else if (infija[i] == '+' || infija[i] == '-')
		{
			//Saca todos los¡ operadores de mayor o ogual prescdencia
			while(operador != NULL)
			{
				//Misma Prescedencia
				if (operador->Tope->dato != '(')
				{
					simbolo=Insertar(simbolo, operador->Tope->dato);
					operador=Eliminar_Tope(operador);
				}
				
				//Se quedan los simbolos de menor prescedencia
				else
				{
					aux=Insertar(aux, operador->Tope->dato);
					operador=Eliminar_Tope(operador);
				}
			}
			
			//Se regresa al orden de prescedencia
			while (aux != NULL)
			{
				operador=Insertar(operador, aux->Tope->dato);
				aux=Eliminar_Tope(aux);
			}
			
			operador=Insertar(operador, infija[i]);
		}
		
		else if (infija[i] == '*' || infija[i] == '/')
		{
			while(operador != NULL)
			{
				//Misma Prescedencia
				if (operador->Tope->dato == '*' || operador->Tope->dato == '/')
				{
					simbolo=Insertar(simbolo, operador->Tope->dato);
					operador=Eliminar_Tope(operador);
				}
				
				//Se quedan los simbolos de menor prescedencia
				else
				{
					aux=Insertar(aux, operador->Tope->dato);
					operador=Eliminar_Tope(operador);
				}
			}
			
			//Se regresa al orden de prescedencia
			while (aux != NULL)
			{
				operador=Insertar(operador, aux->Tope->dato);
				aux=Eliminar_Tope(aux);
			}
			
			operador=Insertar(operador, infija[i]);
		}
		
		else
		{
			simbolo=Insertar(simbolo, infija[i]);
		}
	}
	
	while (operador != NULL)
	{
		simbolo=Insertar(simbolo, operador->Tope->dato);
		operador=Eliminar_Tope(operador);
	}
	
	//Se revierte la pila para tener la notacion
	while (simbolo != NULL)
	{
		aux=Insertar(aux, simbolo->Tope->dato);
		simbolo=Eliminar_Tope(simbolo);
	}
	
	return aux;
}

int main (void)
{
	char * infija;
	char caracter;
	
	int largo;
	largo=1;
	
	struct Pila * postfija;
	postfija=NULL;
	
	printf ("Practica de Cambio de Notacion Infija-Postfija \n");
	printf ("Ingrese una cadena con notacion infija \n");
	
	//Lee la cadena
	while (caracter != '\n')
	{
		scanf("%c", &caracter);
		
		//No guarda el salto de linea en la cadena
		if(caracter != '\n')
		{
			//Primer dato
			if (largo == 1)
			{
				infija = (char*) malloc (largo * sizeof(char));
				infija[largo-1] = caracter;
			}
			
			//Resto de la cadena
			else
			{
				infija = (char*) realloc (infija,1);
				infija[largo-1] = caracter;
			}
			largo++;
		}
	}
	
	postfija = cambio_de_notacion(infija, largo);
	
	printf("La notacion postfija es la siguiente: \n");

	while(postfija != NULL)
	{
		printf("%c", postfija->Tope->dato);
		postfija=Eliminar_Tope(postfija);
	}
	
return 0;
}
