#include <iostream>
#include <string>

using namespace std;

void BeautifulYear(string year)
{
	int Mil,Cen,Dec,Uni;
	Mil=year[0]-'0';
	Cen=year[1]-'0';
	Dec=year[2]-'0';
	Uni=year[3]-'0';
	
	bool Beauti=false;
	
	while(Beauti == false)
	{
		if(Uni < 9)
		{
			++Uni;
		}
		
		else if(Dec < 9)
		{
			Uni=0;
			++Dec;
		}
		
		else if(Cen < 9)
		{
			Uni=0;
			Dec=0;
			++Cen;
		}
		
		else if(Mil < 9)
		{
			Uni=0;
			Dec=0;
			Cen=0;
			++Mil;
		}
		
		if(Mil != Cen && Mil != Dec && Mil != Uni)
		{
			if(Cen != Dec && Cen != Uni)
			{
				if(Dec != Uni)
				{
					Beauti = true;
				}
			}
		}
	}
	
	cout << Mil << Cen << Dec << Uni;
}

int main (void)
{
	string year;
	
	cin >> year;
	
	BeautifulYear(year);
	
return 0;
}
