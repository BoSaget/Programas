#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
	int car,x,y;
	bool perfect=false;
	vector<int> matrix [5][5];
	
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			cin >> car;
			matrix[i][j].push_back(car);
			if(car==1)
			{
				x=i;
				y=j;	
			}
		}
	}
		
	car=0;
	
	while(perfect==false)
	{
		if(x==2 && y==2)
		{
			perfect=true;
		}
		
		else if(x==2)
		{
			if(y>2)
			{
				swap(matrix[x][y],matrix[x][y-1]);
				--y;
				++car;
			}
			else
			{
				swap(matrix[x][y],matrix[x][y+1]);
				++y;
				++car;
			}
		}
		
		else if(y==2)
		{
			if(x>2)
			{
				swap(matrix[x][y],matrix[x-1][y]);
				--x;
				++car;
			}
			else
			{
				swap(matrix[x][y],matrix[x+1][y]);
				++x;
				++car;
			}
		}
		
		else
		{
			if(x>2 && y>2)
			{
				swap(matrix[x][y],matrix[x][y-1]);
				--y;
			}
			
			else if(y+1>4 || y>2)
			{
				swap(matrix[x][y],matrix[x][y-1]);
				--y;
			}
			
			else
			{
				swap(matrix[x][y],matrix[x][y+1]);
				++y;
			}
			
			
			++car;
		}
	}
	
	cout << "" << car;
	
return 0;
}
