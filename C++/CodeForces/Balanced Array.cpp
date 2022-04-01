#include <iostream>
#include <vector>

using namespace std;

void Numbers(int cases)
{
	int pair;
	pair=0;
	int PAIR;
	PAIR=0;
	int odd;
	odd=0;
	int ODD;
	ODD=1;
	
	for(int i=0; i<cases; ++i)
	{
		if(i < cases/2)
		{
			pair+=2;
			cout << pair << " ";
			PAIR=PAIR+pair;
		}
		
		else
		{
			if(i == cases-1)
			{
				odd=PAIR-ODD-2;
			}
			if(odd == 0)
			{
				odd+=1;
			}
			else
			{
				odd+=2;
				ODD=ODD+odd;
			}
			cout << odd << " ";
		}
	}
	cout << endl;
}

int main (void)
{
	int t;
	cin >> t;
	vector <int> cases;
	int aux;
	
	for(int i=0; i<t; ++i)
	{
		cin >> aux;
		cases.push_back(aux); 
	}
	
	for(int i=0; i<t; ++i)
	{
		if(cases[i] % 4 == 0)
		{
			cout << "YES" << endl;
			Numbers(cases[i]);
		}
		
		else
		{
			cout << "NO" << endl;	
		}
	}
	
return 0;
}
