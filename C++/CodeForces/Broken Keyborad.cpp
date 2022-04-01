#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sort(vector <char> &letters)
{
	for(int i=0; i<letters.size(); ++i)
	{
		for(int j=0; j<letters.size(); ++j)
		{			
			if(letters[j] == '0')
			{
				++j;
				i=j;
			}
			
			
			else if(letters[j] < letters[i])
			{
				swap(letters[i], letters[j]);
				cout << "Cambio";
			}
		}
	}
}

void Correct_Buttoms (int test)
{
	string buttoms;
	int cont;
	cont=0;
	
	vector <char> correct;
	
	while(cont < test)
	{
		cin >> buttoms;
		
		for(int i=0; i<buttoms.size(); ++i)
		{
			if(buttoms[i] != buttoms[i+1])
			{
				
				correct.push_back(buttoms[i]);	
			}
			else
			{
				++i;
			}
	 	}
		correct.push_back('0');
		++cont;	
	}
	
	sort(correct);
	
	for(int i=0; i<correct.size(); ++i)
	{
		if(correct[i] == '0')
		{
			cout << endl;
		}
		
		else
		{
			cout << correct[i];
		}
	}
}

int main(void)
{
	int test;
	cin >> test;
	
	Correct_Buttoms(test);
		
return 0;
}
