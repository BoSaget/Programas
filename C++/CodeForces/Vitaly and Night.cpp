#include <iostream>

using namespace std;

void Flats(int lights [], int &on ,int flat)
{
	for(int i=0; i<flat*2; i+=2)
	{
		if(lights[i] == 1)
		{
			on++;
		}
		else if(lights[i+1] == 0)
		{
			on++;
		}
	}
}

int main (void)
{
	int flat, floor, on, value;
	on=0;
	
	int lights[flat];
	
	cin >> floor >> flat; 
	
	for(int i=0; i<floor; i++)
	{
		for(int j=0; j<flat*2; j++)
		{
			cin >> value;
			lights[j]=value;
		}
		Flats(lights, on, flat);
	}
	
	cout << on;
	
return 0;
}
