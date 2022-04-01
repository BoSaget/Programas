#include <iostream>
#include <vector>

using namespace std;

void Order(vector <int> &shoes)
{
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			if(shoes[i] > shoes[j])
			{
				swap(shoes[i],shoes[j]);
			}
		}
	}
}

void Buy(vector <int> shoes)
{
	int min;
	min=0;
	
	Order(shoes);
	
	for(int i=0; i<4; ++i)
	{
		if(shoes[i] == shoes[i+1])
		{
			++min;
		}
	}
	
	cout << min;
}

int main (void)
{
	vector <int> shoes;
	int number;
	
	for(int i=0; i<4; ++i)
	{
		cin >> number;
		shoes.push_back(number);
	}
	
	Buy(shoes);
	
return 0;
}
