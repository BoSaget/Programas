#include <iostream>
#include <iomanip>

using namespace std;

void Fraction(float Bottles, float Volume)
{
	float Fraction;
	
	Bottles=Bottles;
	Fraction=Volume / Bottles;
	
	cout << Fraction;
}

int main (void)
{
	float Bottles;
	cin >> Bottles;
	
	float Percent; 
	float Volume=0;
	
	for(int i=1; i<=Bottles; ++i)
	{
		cin >> Percent;
		Volume=Volume+Percent;
	}

	Fraction(Bottles, Volume);
		 
return 0;
}
