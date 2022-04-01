#include <iostream>

using namespace std;

void Sum(int two, int three, int five, int six)
{
	int sum;
	sum=0;
	
	while(two != 0 && five != 0 && six!= 0)
	{
		sum+=256;
		--two;
		--five;
		--six;	
	}
	
	while(three != 0 && two !=0)
	{
		sum+=32;
		--two;
		--three;
	}
	
	cout << sum;
	
}

int main (void)
{
	int two, three, five, six;
	
	cin >> two >> three >> five >> six;
	
	Sum(two, three, five, six);
	
return 0;
}
