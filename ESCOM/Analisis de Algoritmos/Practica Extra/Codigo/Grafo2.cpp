
#include<iostream>
#include<conio.h>

using namespace std;

char opc;
char volver;
int valor;

struct nodo{
	int numero;
	int max_nodos;
	struct nodo*sig;
	struct arista*ady;
};

typedef struct nodo*Tnodo;
Tnodo puntero;



struct arista{
	struct nodo*destino;
	struct arista*sig;
};

typedef struct arista*Tarista;


void insertar_nodos(){
	Tnodo t, nuevo = new struct nodo;
	cout<<"\n\t\t\t\tIngrese Un Numero: ";
	cin>>nuevo->numero;
	nuevo->sig = NULL;
	nuevo->ady = NULL;
	
	if(puntero==NULL){
		puntero = nuevo;
		cout<<"\n\t\t\t\tNodo Ingresado!"<<endl;
	}
	else{
		t=puntero;
		while(t->sig!=NULL){
			t=t->sig;
		}
		t->sig = nuevo;
		cout<<"\n\t\t\t\tNodo Ingresado!"<<endl;
	}
}


void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
	Tarista q;
		if(aux->ady==NULL){
			aux->ady=nuevo;
			nuevo->destino= aux2;
			cout<<"\n\t\t\t\tArista Ingresada!"<<endl;
		}
		else{
			q=aux->ady;
			while(q->sig!=NULL){
				q=q->sig=nuevo;
			}
			nuevo->destino=aux2;
			q->sig=nuevo;
			cout<<"\n\t\t\t\tArista Ingresada!"<<endl;
		}
}

void insertar_aristas(){
	int inicio,fin;
	Tarista nuevo = new struct arista;
	Tnodo aux, aux2;
	
		if(puntero==NULL){
			cout<<"\n\t\t\t\tNo Hay Grafo"<<endl;
			return;
		}
		nuevo->sig=NULL;
		cout<<"\n\t\t\t\tIngrese El Nodo De Inicio:";
		cin>>inicio;
		cout<<"\n\t\t\t\tIngrese El Nodo Final:";
		cin>>fin;
		aux=puntero;
		aux2=puntero;
			while(aux2!=NULL){
				if(aux2->numero==fin){
					break;
				}
				aux2=aux2->sig;
			}
			while(aux!=NULL){
				if(aux->numero==inicio){
					agrega_arista(aux,aux2,nuevo);
					return;
				}
				aux=aux->sig;
			}
}


void mostrar_grafo(){
	Tnodo ptr;
	Tarista ar;
	ptr = puntero;
	cout<<"\n\t\t\t\tNodo: Adyacencia"<<endl;
	
		while(ptr!=NULL){
			cout<<"\t\t\t\t   "<<ptr->numero<<":";
			if(ptr->ady!=NULL){
				ar=ptr->ady;
				while(ar!=NULL){
					cout<<"  "<<ar->destino->numero;
					ar=ar->sig;
				}
			}
			ptr=ptr->sig;
			cout<<endl;		
		}
}


void mostrar_aristas(){
	Tnodo aux;
	Tarista ar;
	int var;
	
	cout<<"\n\t\t\t\tMostrar Arista Del Nodo"<<endl;
	cout<<"\n\t\t\t\tIngrese El Nodo: ";
	cin>>var;
	aux=puntero;
	
		while(aux!=NULL){
			if(aux->numero==var){
				if(aux->ady==NULL){
					cout<<"\n\t\t\t\tEl Nodo No Tiene Arista"<<endl;
					return;
				}
				else{
					cout<<"\n\t\t\t\tNodos: Adyacencia"<<endl;
					cout<<"\n\t\t\t\t  "<<aux->numero<<":";
					ar=aux->ady;
					
					while(ar!=NULL){
						cout<<ar->destino->numero<<" ";
						ar=ar->sig;
					}
					cout<<endl;
					return;
				}
			}
			else{
				aux=aux->sig;
			}
		}
}

void ciclo()
{
	Tnodo nodo_aux;
	Tarista arrista_aux;
	
	for(int i = 0; i < puntero->max_nodos; i++)
	{
		cout << "hey" << endl;
	}
	
}

int crear_menu(){

	cout<<"\t\t\t==Gestion De Grafos=="<<endl;
	cout<<"\t\t\t1.-Insertar Nodo"<<endl;
	cout<<"\t\t\t2.-Insertar Arista"<<endl;
	cout<<"\t\t\t3.-Mostrar Grafo"<<endl;
	cout<<"\t\t\t4.-Mostrar Arista"<<endl;
	cout<<"\t\t\t5.-Salir"<<endl;
	cout<<"\t\t\tIngrese Una Opcion:";
}


int main(){
	puntero = NULL;
	int num_nodos;
	num_nodos = 0;

	volver='s';
	while(volver=='s'){
		
		crear_menu();
		cin>>opc;
		system("pause");
		system("cls");	
		switch(opc){
			case '1':
				insertar_nodos();
				num_nodos++;
				break;
			case '2':
				insertar_aristas();
				break;
			case '3':
				mostrar_grafo();
				break;
			case '4':
				mostrar_aristas();
				break;
				
			case '5':
				puntero->max_nodos = num_nodos;
				ciclo();
				break;
			case '9':
				cout<<"Salir, máxima cantidad de nodos:" << puntero->max_nodos <<endl;
				return 0;
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
		
		cout<<"\n\t\t\t\tDesea Volver al Menu Principal s-si/n-no";
		cout<<"\n\t\t\t\t";cin>>volver;
		system("pause");
		system("cls");
	}	
	return 0;
}




