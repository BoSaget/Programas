#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (void)
{
	int Seconds,Size_Queue;
	string Queue;
	
	cin >> Size_Queue >> Seconds >> Queue;
	
	
	while(Seconds != 0)
	{
		for(int i=0;i<Size_Queue-1;++i)
		{
			if(Queue[i] == 'B' && Queue[i+1] == 'G')
			{
				swap(Queue[i],Queue[i+1]);
				i+=1;	
			}	
		}
		Seconds--;
	}
	
	cout << "" << Queue;
	
return 0;
}
