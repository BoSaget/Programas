#include <iostream>
#include <string>
using namespace std;

void Neighboor (string stones)
{	
	int OnTable=0; 
	
	if(stones.size() == 1)
	{
		cout << OnTable;
	}
	
	else
	{
		for(int i=0; i<stones.size()-1; ++i)
		{
			if(stones[i] == stones[i+1])
			{
				++OnTable;
			}
		}
		cout << OnTable;
	}
}

int main (void)
{
	int Num;
	string stones;
	
	cin >> Num >> stones;
	
	Neighboor(stones);
	
return 0;
}
