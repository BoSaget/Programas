#include <iostream>
#include <string>

using namespace std;

void Lucky (string number)
{
	int Lucky = 0;
	
	for (int i=0; i<number.size(); ++i)
	{
		if(number[i] == '4' || number[i] == '7')
		{
			++Lucky;
		}
	}
	
	if(Lucky == 4 || Lucky == 7 && Lucky != 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
}

int main (void)
{
	string number;
	cin >> number;
	
	Lucky(number);
	
return 0;
}
