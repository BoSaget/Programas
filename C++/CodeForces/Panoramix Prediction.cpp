#include <iostream>

using namespace std;

bool Prime(int m)
{	
	int cont =0;
	
	for(int i=1; i<=m; ++i)
	{
		if(m%i == 0)
		{
			if(i==1 || i==m)
			{
				++cont;
				if(cont == 2)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
	}
}

void NextPrime(int n, int m)
{
	bool Its_Prime=false;
	Its_Prime=Prime(m);
	
	if(Its_Prime == true && n<m)
	{
		for(int i=1; i<=m; ++i)
		{
			Its_Prime=Prime(n+i);
			if(Its_Prime == true)
			{
				if(n+i == m)
				{
					cout << "YES";
					return;
				}
				else
				{
					cout << "NO";
					return;
				}
			}
		}
	}
	else
	{
		cout << "NO";
	}
	
}

int main (void)
{
	int n,m;
	
	cin >> n >> m;
	
	NextPrime(n,m);
	
	
return 0;
}
