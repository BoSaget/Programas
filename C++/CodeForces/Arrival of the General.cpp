#include <iostream>
#include <vector>

using namespace std;

bool Check (vector <int> soldiers, int max, int min)
{
	if(max == soldiers[0] && min == soldiers[soldiers.size()-1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Order (vector <int> soldiers)
{
	bool checker;
	int max, min, maxpos, minpos, seconds;
	seconds=0;
	max=0;
	min=101;
	
	for(int i=0; i<soldiers.size(); ++i)
	{
		if(soldiers[i] > max)
		{
			max=soldiers[i];
			maxpos=i;
		}
		
		if(soldiers[i] <= min)
		{
			min=soldiers[i];
			minpos=i;
		}
	}
	
	checker=Check(soldiers, max, min);
	
	while(checker == false)	
	{	
		if(minpos != soldiers.size()-1)
		{
			if(minpos == maxpos-1)
			{
				swap(soldiers[minpos], soldiers[minpos+1]);
				++minpos;
				--maxpos;
				++seconds;
			}
			
			else
			{
				swap(soldiers[minpos], soldiers[minpos+1]);
				++minpos;
				++seconds;
			}
		}
			
		else if(maxpos != 0 )
		{
			swap(soldiers[maxpos], soldiers[maxpos-1]);
			--maxpos;
			++seconds;
		}
		checker=Check(soldiers, max, min);
	}
	
	cout << seconds;
}

int main (void)
{
	int Size;
	cin >> Size;
	
	int height;
	vector <int> Soldiers;
	
	for(int i=0; i<Size; ++i)
	{
		cin >> height;
		Soldiers.push_back(height);
	}
	
	Order(Soldiers);
	
return 0;
}
