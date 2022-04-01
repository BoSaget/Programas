#include <iostream>

using namespace std;

void Damage_Dragons(int pan, int tail, int sharp, int mom, int dragons)
{
	int Damaged=0;
	int cont=0;
	
	for(int i=1; i<=dragons; ++i)
	{
		if(i % pan == 0 && cont==0)
		{
			++Damaged;
			++cont;
		}
		if(i % tail == 0 && cont==0)
		{
			++Damaged;
			++cont;
		}
		if(i % sharp == 0 && cont==0)
		{
			++Damaged;
			++cont;
		}
		if(i % mom == 0 && cont==0)
		{
			++Damaged;
			++cont;
		}
		cont=0;
	}
	cout << Damaged;
}

int main (void)
{
	int Pan,Mom,Tail,Sharp,Dragons;
	cin >> Pan >> Tail >> Sharp >> Mom >> Dragons;
	
	Damage_Dragons(Pan, Tail, Sharp, Mom, Dragons);
	
return 0;
}
