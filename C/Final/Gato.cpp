/*	1CV8
	Perrusquia Islas Milton 
	Tejeda Moyao Leon*/


#include "IA.h"

bool checkw(char gato[], char d, bool w)
{
	if(w==false)
	{
		if(gato[0]==d && gato[1]==d && gato[2]==d)
		{
			w=true;
		}
		
		else if(gato[3]==d && gato[4]==d && gato[5]==d)
		{
			w=true;
		}
		
		else if(gato[6]==d && gato[7]==d && gato[8]==d)
		{
			w=true;
		}
		
		else if(gato[0]==d && gato[3]==d && gato[6]==d)
		{
			w=true;
		}
		
		else if(gato[1]==d && gato[4]==d && gato[7]==d)
		{
			w=true;
		}
		
		else if(gato[2]==d && gato[5]==d && gato[8]==d)
		{
			w=true;
		}
		
		else if(gato[0]==d && gato[4]==d && gato[8]==d)
		{
			w=true;
		}
		
		else if(gato[2]==d && gato[4]==d && gato[6]==d)
		{
			w=true;
		}
		else
		{
			w=false;
		}	
	}
	
	else
	{
		w=true;
	}
return w;
}

bool Primer(char gato[], char d)
{
	bool t=true;
	int i;
	
	for(i=0; i<9; i++)
	{
		if(gato[i]==d)
		{
			t=false;
		}
	}
return t;
}

IA MAX(char gato[], char m)
{
	int i;
	bool j=false;
	IA move;
	
	while(j==false)
	{
		for(i=0; i<9; i++)
		{
			if(gato[i]!='X' && gato[i]!= 'O')
			{
				gato[i]='X';
				j=checkw(gato, 'X', j);
				if(j==true)
				{
					gato[i]=i+1+'0';
					move.x=i;
					move.puntos=10;
					return move;
				}
				else
				{
					move=MAX(gato, m);
					gato[i]=i+1+'0';
				}
				gato[i]=i+1+'0';
			}
		}
	}
}

IA MIN(char gato[], char m)
{
	int i;
	bool j=false;
	IA move;
	
	while(j==false)
	{
		for(i=0; i<9; i++)
		{
			if(gato[i]!='O' && gato[i]!= 'X')
			{
				gato[i]='X';
				j=checkw(gato, 'X', j);
				if(j==true)
				{
					gato[i]=i+1+'0';
					move.x=i;
					move.puntos=-10;
					return move;
				}
				else
				{
					move=MIN(gato, m);
					gato[i]=i+1+'0';
				}
				gato[i]=i+1+'0';
			}	
		}
	}	
}

void movidahum(int pos, char gato[],char d)
{
	printf("TURNO HUMANO \n");
	while(gato[pos-1]=='X' || gato[pos-1]=='O')
	{	
		printf("Casilla ocupada, ingrese otra otra \n");
		scanf("%d",&pos);
	}
	gato[pos-1]=d;	
}

void movidamaq(char gato[], char m, char h)
{
	int i;
	bool p;
	IA move, ma, mi;
	
	printf("TURNO MAQUINA \n");
	p=Primer(gato, m);
	if(p==false)
	{
		if(m=='X')
		{	
			for(i=0; i<9; i++)
			{
				if(gato[i]!=m && gato[i]!= h)
				{
					gato[i]=m;
					move=MAX(gato, m);
					gato[move.x]=m;
					gato[i]=i+1+'0';
					break;
				}
			}		
		}
		else
		{	
			for(i=0; i<9; i++)
			{
				if(gato[i]!=m && gato[i]!= h)
				{
					gato[i]=h;
					move=MIN(gato, m);
					gato[move.x]=m;
					gato[i]=i+1+'0';
					break;
				}
			}
		}
	}
	else
	{
		srand(time(NULL));
		move.x=rand()%9;
		while(gato[move.x]==m || gato[move.x]==h)
		{
			move.x=rand()%9;
		}
		gato[move.x]=m;
	}
}

bool lleno(int tir, bool lleno)
{
	if(lleno==false)
	{
		if(tir<=9)
		{
			lleno=false;
			return lleno;
		}
		else
		{
			lleno=true;
			printf("Sin casillas para tirar \n");
			return lleno;
		}
	}
	
	else
	{
		lleno=true;
		printf("Sin casillas para tirar \n");
		return lleno;
	}
}

bool win(char gato[], char d, bool w)
{
	if(w==false)
	{
		if(gato[0]==d && gato[1]==d && gato[2]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[3]==d && gato[4]==d && gato[5]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[6]==d && gato[7]==d && gato[8]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[0]==d && gato[3]==d && gato[6]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[1]==d && gato[4]==d && gato[7]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[2]==d && gato[5]==d && gato[8]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[0]==d && gato[4]==d && gato[8]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		
		else if(gato[2]==d && gato[4]==d && gato[6]==d)
		{
			printf("Gano %c \n",d);
			w=true;
			return w;
		}
		else
		{
			w=false;
			return w;
		}	
	}
	
	else
	{
		w=true;
		return w;
	}	
}

int juego(int op)
{
	system("cls");
	char h,m,f;
	char gato[]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int num,tir=1;
	bool ll=false,w=false;
	
	if(op==1)
	{
		printf("\t MAQUINA VS HUMANO \n");
		h='O';
		m='X';
		
		printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
				
		while(ll==false && w==false)
		{			
			movidamaq(gato, m, h);
			tir++;
			printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
			w=win(gato,m,w);
			ll=lleno(tir,ll);
			
			if(ll==false && w==false)
			{
				printf("Escoga la casilla donde colocar  \n");
				scanf("%d",&num);
				
				movidahum(num, gato, h);
				tir++;
				printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
				w=win(gato,h,w);
				ll=lleno(tir,ll);
			}
		}
	}
	
	if(op==2)
	{
		printf("\t HUMANO VS MAQUINA \n");
		m='O';
		h='X';
		
		printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
		
		while(ll==false && w==false)
		{	
			printf("Escoga la casilla donde colocar  \n");
			scanf("%d",&num);
			
			movidahum(num, gato, h);
			tir++;
			printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
			w=win(gato,h,w);
			ll=lleno(tir,ll);
			
			if(ll==false && w==false)
			{
				movidamaq(gato, m, h);
				tir++;
				printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
				w=win(gato,m,w);
				ll=lleno(tir,ll);
			}
		}				
	}
	
	if(op==3)
	{
		printf("\t MAQUINA VS MAQUINA \n");
		h='O';
		m='X';
		
		printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
		printf("--|--|-- \n");
		printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
		
		while(ll==false && w==false)
		{			
			movidamaq(gato, m, h);
			tir++;
			printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
			printf("--|--|-- \n");
			printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
			w=win(gato,m,w);
			ll=lleno(tir,ll);
			
			if(ll==false && w==false)
			{
				movidamaq(gato, h, m);
				tir++;
				printf("%c |%c |%c  \n",gato[0], gato[1], gato[2]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[3], gato[4], gato[5]);
				printf("--|--|-- \n");
				printf("%c |%c |%c  \n",gato[6], gato[7], gato[8]);
				w=win(gato,h,w);
				ll=lleno(tir,ll);
			}
		}
	}
	
	if(op==4)
	{
		exit(-1);
	}
	
	printf("Si desea volver a jugar oprima Y \n");
	printf("Si no desea volver a jugar oprima N \n");
	scanf("%*c %c",&f);
	if(f=='Y' || f=='y')
	{
		num=1;
		system("cls");
		return num;
	}
	
	else
	{
		num=0;
		return num;
	}
}

int menu(int t)
{
	int o;
	while(t==1)
	{
		printf("Escoga une opcion:\n");
		printf("1-Maquina VS Humano\n");
		printf("2-Humano VS Maquina\n");
		printf("3-Maquina VS MAquina\n");
		printf("4-Salir\n");
		scanf("%d",&o);
		t=juego(o);
	}
	
}

int main(void)
{
	menu(1);
	return 0;
}
