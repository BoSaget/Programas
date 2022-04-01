#include <iostream>
#include <vector>

using namespace std;

void Performance(vector <int> Points)
{
	int max, min, performance;
	performance=0;
	max=Points[0];
	min=Points[0];
	
	for(int i=1; i<Points.size(); ++i)
	{
		if(max < Points[i])
		{
			max = Points[i];
			++performance;
		}
		else if(min > Points[i])
		{
			min = Points[i];
			++performance;
		}
	}
	
	cout << performance;
}

int main (void)
{
	int contest;
	int Points;
	vector <int> Puntuation;
	
	cin >> contest;
	
	for(int i=0; i<contest; ++i)
	{
		cin >> Points;
		Puntuation.push_back(Points);
	}
	
	Performance(Puntuation);
	
return 0;
}
