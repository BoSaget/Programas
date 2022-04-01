#include <iostream>
#include <string>

using namespace std;

void Correct_Sum(string &sum)
{
	int one,two, three, i; 
	one=0;
	two=0;
	three=0;
	
	for(i=0; i<sum.size(); i=i+2)
	{
		if(sum[i] == '1')
		{
			++one;
		}
		
		else if(sum[i] == '2')
		{
			++two;
		}
		
		else
		{
			++three;
		}
	}
	
	i=0;
	
	while(one != 0 || two != 0 || three != 0)
	{
		if(one != 0)
		{
			sum[i]='1';
			--one;
		}
		
		else if(two != 0)
		{
			sum[i]='2';
			--two;
		}
		
		else if(three != 0)
		{
			sum[i]='3';
			--three;
		}
	
		i=i+2;	
	}
	
	cout << sum;
}

int main (void)
{
	string sum;
	
	cin >> sum;
	
	Correct_Sum(sum);

return 0;
}
