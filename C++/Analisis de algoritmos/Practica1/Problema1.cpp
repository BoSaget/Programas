/*
Escuela Supeior de Computo
Materia: Analisis de Algoritmos
Grupo: 3CV11
Practica 1
Alumno: Tejeda Moyao Leon Francisco
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//Genera el arreglo
void arreglo(int n, int &x, int &y, int &t);

//Busca algun valor repetido
int repetido(int arr[], int n, int &x, int &y, int &t);

int main ()
{
	int i, x, y, t;
	ofstream datos;
	datos.open("datos.csv", ios::trunc);
	
	for(i=10;i<1001; i+=10)
	{
		x =0;
		y=0;
		t=0;
		arreglo(i, x, y, t);
		cout << endl << "Tiempo: " << t << "\t Datos: " << i<< endl << endl;
	
		datos << t << ","  << i << endl;
	}
	
	datos.close();
	
	
return 0;
}

void arreglo(int n, int &x, int &y, int &t)
{
	int i, dato, datorepe;
	t=t+3;
	int arr[n];
	t++;
	
	srand(time(NULL));
	t++;
	
	t++;
	for (i=0; i<n ; i++)
	{
		t++;
		
		dato = rand() % (3*n);
		t++;
		
		arr[i] = dato;
		t++;
		
		cout << dato << " ";
		t++;
	}
	t++;
	
	cout << endl;
	t++;
	
	datorepe = repetido(arr, n, x, y, t);
	t++;
	
	if (datorepe == -1)
	{
		t++;
		
		cout << "No hay dato repetido \n\n";
		t++;
	}
	
	else
	{
		t++;
		
		cout << "\t Dato repetido: " << datorepe << " Posiciones: " << x << "," << y << endl << endl;
		t++;
	}
}

int repetido(int arr[], int n, int &x, int &y, int &t)
{
	int valor, i, j;
	t=t+3;
	
	int a [n/2],b [n/2];
	t=t+2;
	
	t++;
	for(i=0; i<n; i++)
	{
		t++;
		if(i < n/2)
		{
			t++;
			
			t++;
			a[i] = arr[i];
			//cout << "A: " << a[i] << "\t";
		}
		else
		{
			t++;
			
			t++;
			b[i-(n/2)] = arr[i];
			//cout << "B: " << b[i-(n/2)] << "\t";
		}
	}
	t++;
	
	t++;
	for(i=0; i<n/2; i++)
	{
		t++;
		
		t++;
		valor = a[i];
		
		t++;
		for(j=0; j<n/2; j++)
		{
			if (valor == b[j])
			{
				t++;
				
				t++;
				x=i;
				
				t++;
				y=j+(n/2);
				
				t++;
				return valor;	
			}	
		}
		t++;
	}
	t++;
	
	t++;
	return -1;
}
