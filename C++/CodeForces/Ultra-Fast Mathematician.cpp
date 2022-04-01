#include <iostream>
#include <string>

using namespace std;

void New_Number(string Line1, string Line2)
{
	for(int i=0; i<Line1.size(); ++i)
	{
		if(Line1[i] == Line2[i])
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	}
}

int main (void)
{
	string Line1, Line2;
	
	cin >> Line1 >> Line2;
	
	New_Number(Line1, Line2);

return 0;
}
