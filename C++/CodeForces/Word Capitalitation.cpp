#include <iostream>
#include <string>

using namespace std;

void CapitalLetter(string word)
{
	int capital=0;
	
	if(word[0] - '0' > 43)
	{
		capital=word[0] - '0';
		capital=capital - 32;
		word[0]=capital + '0';
	}
	cout <<"2";
}

int main (void)
{
	string word;
	cin >> word;
	
	CapitalLetter(word);
	
return 0;
}
