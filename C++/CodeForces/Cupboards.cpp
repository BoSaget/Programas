#include <iostream>
#include <vector>

using namespace std;

void Seconds(vector <int> &Left, vector <int> &Right)
{
	int seconds=0, zero=0, one=0;
	
	for(int i=0; i<Left.size(); ++i)
	{
		if(Left[i] == 0)
		{
			++zero;
		}
		else
		{
			++one;
		}
	}
	
	if(zero >= one)
	{
		seconds=one;
	}
	
	else
	{
		seconds=zero;
	}
	
	one=0;
	zero=0;
	
	for(int i=0; i<Right.size(); ++i)
	{
		if(Right[i] == 0)
		{
			++zero;
		}
		else
		{
			++one;
		}
	}
	
	if(zero >= one)
	{
		seconds=seconds+one;
	}
	
	else
	{
		seconds=seconds+zero;
	}
	
	cout << seconds;
}


int main (void)
{
	vector <int> Jar_Left;
	vector<int> Jar_Right;
	int value;
	int Number_Jars;
	cin >> Number_Jars;
	
	for(int i=0; i<Number_Jars; ++i)
	{
		cin >> value;
		Jar_Left.push_back(value);
		cin >> value;
		Jar_Right.push_back(value);
	}
	
	Seconds(Jar_Left, Jar_Right);
	
return 0;
}
