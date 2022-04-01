#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Order (vector <int> &value)
{
	for(int i=0; i<value.size(); ++i)
	{
		for(int j=0; j<value.size(); ++j)
		{
			if(value[i] < value[j])
			{
				swap(value[i], value[j]);
			}
		}
	}
}

void Boy_Girl(string name)
{
	vector <int> value;
	int different=0;
	
	for(int i=0; i<name.size(); ++i)
	{
		value.push_back(name[i]-'0');
	}
	
	Order(value);
	
	for(int i=0; i<value.size()-1; ++i)
	{
		if(value[i] != value[i+1])
		{
			++different;
		}
	}
	
	if(different % 2 != 0)
	{
		cout << "CHAT WITH HER!";
	}
	
	else
	{
		cout << "IGNORE HIM!";
	}
}

int main(void)
{
	string name;
	cin >> name;
	
	Boy_Girl(name);
	
return 0;
}
