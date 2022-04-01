#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &num)
{	
	for(int i=0;i<num.size();++i)
	{
		for(int j=0;j<num.size();++j)
		{
			if(num[j]>num[i])
			{
				swap(num[j],num[i]);
			}
		}
	}
}

void QuickSort(vector<int> &num)
{
	
}

void MergeSort(vector<int> &num)
{
	
}

void BucketSort(vector<int> &num, int MAX)
{
	
}


int main (void)
{
	vector <int> num;
	num.push_back(5);
	num.push_back(1);
	num.push_back(4);
	num.push_back(6);
	num.push_back(3);
	num.push_back(2);
	
	int MAX=0;
	for(int i=0;i<num.size();++i)
	{
		if(num[i]>MAX)
		{
			MAX=num[i];
		}
	}
	
	BubbleSort(num);
//	QuickSort(num);
//	MergeSort(num);
//	BucketSort(num, MAX);
	
	for(int i=0;i<num.size();++i)
	{
		cout << " " << num[i];
	}
return 0;
}
