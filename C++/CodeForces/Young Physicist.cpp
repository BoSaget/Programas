#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
	int n,x,y,z;
	int rx=0,ry=0,rz=0;
	cin >> n;

	
	for(int i=0;i<n;++i)
	{
		cin >> x >> y >> z;
		rx=rx+x;
		ry=ry+y;
		rz=rz+z;
	}
	
	
	if (rz==0 && rx==0 && ry==0)
	{
		cout << "YES";
	}
	
	else
	{
		cout << "NO";
	}
	
return 0;
}
