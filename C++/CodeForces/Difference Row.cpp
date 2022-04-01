#include <iostream>
#include <vector>

using namespace std;

void sort (vector <int> & order)
{
	for(int i=0; i< order.size()-1; ++i)
	{
		for(int j=0; j< order.size()-1; ++j)
		{
			if(order[i] < order[j])
				swap(order[i], order[j]);
			cout << "todo good";
		}
	}
}

vector <int> pos (vector <int> original)
{
	vector <int> aux;
	
	if(original.size() != 0)
	{
		for(int i=0; i<original.size(); ++i)
		{
			if(original[i] <= 0)
				aux.push_back(original[i]);
		}
		sort(aux);
	}
return aux;
}

vector <int> neg (vector <int> original)
{
	vector <int> aux;
	
	if(original.size() != 0)
	{
		for(int i=0; i<original.size(); ++i)
		{
			if(original[i] < 0)
				aux.push_back(original[i]);
		}
		sort(aux);
	}
return aux;
}

int main (void)
{
	int values;
	cin >> values;
	
	int value;
	vector <int> data;
	vector <int> positive;
	vector <int> negative;
	
	for(int i=0; i<values; ++i)
	{
		cin >> value;
		data.push_back(value);
	}	
	
	positive=pos(data);
	negative=neg(data);
	
	if(negative.size() == 0)
	{
		for(int i=0; i<positive.size(); ++i)
		{
			cout << positive[i] << " ";
		}
	}
	
	else if(positive.size() == 0)
	{
		for(int i=0; i<negative.size();++i)
		{
			cout << negative[i] << " ";
		}
	}
	
return 0;
}

