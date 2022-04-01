#include <iostream>
#include <string>

using namespace std;

void Travel (string city)
{
	int cont;
	cont=0;
	
	for(int i=0; i<city.size()-1; i++)
	{
		if(city[i] == 'S' && city[i+1] == 'F')
		{
			cont++;
		}
		
		else if(city[i] == 'F' && city[i+1] =='S')
		{
			cont--;
		}
	}
	
	if(cont > 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}

int main (void)
{
	int flights;
	string city;
	
	cin >> flights;
	cin >> city;
	
	Travel(city);
	
return 0;
}
