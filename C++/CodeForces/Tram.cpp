#include <iostream>

using namespace std;

void Max_Cap(int stations)
{
	int up, down, capacity, max;
	capacity=0;
	max=0;
	
	for(int i=0; i<stations; ++i)
	{
		cin >> down >> up;
		capacity=capacity+up-down;
		
		if(max < capacity)
		{
			max=capacity;
		}
	}
	
	cout << max;
}

int main (void)
{
	int stations;
	cin >> stations;
	
	Max_Cap (stations);
	
return 0;
}
