#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	string Borze;
	
	int Number=0;
	
	cin >> Borze;
	
	for (int i=0;i<Borze.size();++i)
	{
		if (Borze[i] == '-' && Borze[i+1] == '-')
		{
			Number=2;
			++i;
		}
		
		else if(Borze[i] == '-' && Borze [i+1]=='.')
		{
			Number=1;
			++i;
		}
		
		else if(Borze[i]=='.')
		{
			Number=0;
		}
		cout << "" << Number;
	}
	
return 0;
}
