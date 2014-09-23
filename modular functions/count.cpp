#include <string>
#include <iostream>
using namespace std;

/*
*	int function returns score
* @word - argument (string)
*/

int count(string& word)
{
	int counter = 0;
	for(int i = 0; i < int(word.size()); ++i)
	{
		switch(word[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'l':
			case 'n':
			case 'o':
			case 'r':
			case 's':
			case 't':
			case 'u':
				counter++;
				break;
			case 'b':
			case 'c':
			case 'm':
			case 'p':
				counter += 3;
				break;
			case 'd':
			case 'g':
				counter += 2;
				break;
			case 'f':
			case 'h':
			case 'v':
			case 'w':
				counter += 4;
				break;
			case 'k':
				counter += 5;
				break;
			case 'j':
			case 'x':
				counter += 8;
				break;
			case 'q':
			case 'z':
				counter += 10;
				break;
			default:
				break;
		}
	}
	return counter;
}

/*
* Test function in main
*/

int main()
{

	string a = "aaabcd";
	cout << count(a);

	return 0;
}