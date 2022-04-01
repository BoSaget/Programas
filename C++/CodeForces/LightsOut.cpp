#include <iostream>

using namespace std;

void LightsOut(int Lights[][3])
{
	int status=0;
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{	
			status=Lights[i][j];
			if(i+1 <3)
			{
				status=status + Lights[i+1][j];
			}
			if(i-1 > -1)
			{
				status=status + Lights[i-1][j];
			}
			if(j+1 < 3)
			{
				status=status + Lights[i][j+1];
			}
			if(j-1 > -1)
			{
				status=status + Lights[i][j-1];
			}
			
			status=status % 2;
			
			if(status == 1)
			{
				cout << "0";
			}
			else
			{
				cout << "1";
			}
		}
		cout << endl;
	}
}

int main (void)
{	
	int press;
	int Lights[3][3];
	
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{
			cin >> press;
			Lights[i][j]=press;
		}
	}
	
	LightsOut(Lights);
	
return 0;
}
