#include <iostream>
#include <string>

using namespace std;

void Letters(string &word)
{
	int upper=0,lower=0;
	for(int i=0; i<word.size(); ++i)
	{
		if(word[i]-'0' > 43)
		{
			++lower;
		}
		else
		{
			++upper;
		}

	}
	if(upper > lower)
	{
		for(int i=0; i<word.size() ; ++i)
		{
			if(word[i]-'0' > 43)
			{
				upper=word[i] - '0';
				upper = upper - 32;
				word[i]=upper +'0';
			}
		}
	}
	else if(upper <= lower)
	{
		for(int i=0; i<word.size() ; ++i)
		{
			if(word[i]-'0' < 43)
			{
				lower=word[i] - '0';
				lower = lower + 32;
				word[i]=lower +'0';
			}
		}
	}
	cout << word;
	
}

int main (void)
{
	string word;
	cin >> word;
	
	Letters(word);
	
return 0;
}
