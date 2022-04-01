#include <iostream>
#include <vector>

using namespace std;

void FindK (int candies)
{
	int k=2;
	int x;
	
	while(candies % k != 0)
	{
		++k;
	}
	x=candies/k;
	
	cout << x << endl;
}

int main (void)
{
	int test;
	cin >> test;
	vector <int> candies;
	int n;
	
	for(int i=0; i< test; ++i)
	{
		cin >> n;
		candies.push_back(n);	
	}
	
	for(int i=0; i< test; ++i)
	{
		FindK(candies[i]);
	}
	
return 0;
}
