#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <char> Change(string pile)
{
	stack <char> letters;
	
	for(int i=pile.size()-1;i>-1; --i)
	{
		letters.push(pile[i]);
	}
return letters;
}

void Names(string guest, string residence, stack <char> &letters)
{
	int rescont;
	rescont=0;
	int guestcont;
	guestcont=0;
	
	while(!letters.empty())
	{
		if(rescont < residence.size()-1 && guestcont < guest.size()-1)
		{
			if(letters.top() == guest[guestcont])
			{
				++guestcont;
				letters.pop();
			}
			
			else if(letters.top() == residence[rescont])
			{
				++rescont;
				letters.pop();
			}
			
			else
			{
				cout << "NO";
				return;
			}
		}
		else
		{
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main(void)
{
	string guest;
	cin >> guest;
	string residence;
	cin >> residence;
	string pile;
	cin >> pile;  
	stack <char> letters;
	
	letters=Change(pile);
	Names(guest, residence, letters);
	
return 0;
}
