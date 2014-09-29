#include <string>
#include <iostream>
using namespace std;

/*
 * bool function returns true/false
 */

bool checkWord(string word, string letters)
{
	int counter = 0;
	for(int i = 0; i < int(word.size()); ++i)
	{
		for(int j = 0; j < int(letters.size()); ++j)
		{
			if(word[i] == letters[j])
				counter++;
		}
	}
	if(counter == int(word.size()))
	{
		return true;
	}
	return false;
}

/*
* Test function in main
*/

int main()
{
	if(checkWord("abcd", "abc"))
	{
		cout << "YAAY";
	}
	else
	{
		cout << "OLOLO";
	}
	return 0;
}