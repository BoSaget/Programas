#include <iostream>
#include <vector>

using namespace std;

void Perfect_Permutation (vector <int> &Permutation)
{
	if(Permutation.size() % 2 != 0)
	{
		cout << "-1";
	}
	else
	{
		for(int i=0; i<Permutation.size()-1; i+=2)
		{
			swap(Permutation[i],Permutation[i+1]);
			printf ("%d %d ", Permutation[i], Permutation[i+1]);
		}
	}
}

int main (void)
{
	int Permutation_Size;
	cin >> Permutation_Size;
	
	vector <int> Permutation;
	
	for(int i=0; i<Permutation_Size; ++i)
	{
		Permutation.push_back(i+1);
	}
	
	Perfect_Permutation(Permutation);
	
return 0;
}
