#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Long_Word(vector <string> &words)
{
	string word;
	int length;
	
	for(int i=0; i<words.size(); ++i)
	{
		word=words[i];
		
		if(word.size() > 10)
		{
			length= word.size()-2;
			cout << word[0] << length << word[word.size()-1] << endl;
		}
		else
		{
			cout << word << endl;
		}
	}
}

int main (void)
{
	int test;
	cin >> test;
	string Word;
	vector <string> words;
	
	for(int i=0; i<test; ++i)
	{
		cin >> Word;
		words.push_back(Word);
	}
	
	Long_Word(words);
	
return 0;
}
