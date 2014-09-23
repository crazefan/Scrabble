#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


/*
super igra by Zufar Ismanov.
Imboviy project manager: Timur Dolgopolov.
Chutok pomog: Koreec*/

int count(string& word);
void game();
void generate();
void next_step(int a);

struct Letter
{
	char ltr;
	int used;
	Letter(char altr, int aused)
		:ltr(altr), used(aused)
	{

	}
	Letter()
	{

	}
};

vector<Letter> hand(7);
int res = 0;

void rules(int a)
{	
	cout << "               RULES:               " << endl;
	cout << "------------------------------------" << endl;
	cout << "   In this game you are given a hand" << endl;
	cout << "consisting of 7 letters. Due to earn" << endl;
	cout << "points you have to make a valid word" << endl;
	cout << "out of the given letters! Points for" << endl;
	cout << "each valid word you made are counted" << endl;
	cout << "in the same way as in SCRABBLE game " << endl;
	cout << "(sum of points for each letter      " << endl;
	cout << "multiplied by the length of a word)." << endl;
	cout << "If you make a word using ALL seven  " << endl;
	cout << "letters in your hand - you will     " << endl;
	cout << "get 50 bonus points!                " << endl;
    cout << "             Good luck!             " << endl;
	cout << "------------------------------------" << endl;
	if(a == 1)
		next_step(1);
}

void generate()
{ 
	srand(time(NULL)); 
	for(int i = 0; i < 7; ++i)
	{		
		int rnd = rand() % 26 + 1;
		char a = char(96 + rnd);
		hand[i] = Letter(a, 0);
	}
}

string input()
{	
	string str;
	cin >> str;
	return str;
}

bool check(string word)
{
	ifstream fin ("words.txt");
	string tmp;
	while(fin >> tmp)
	{
		if(word == tmp)
		{
			return true;
		}
	}
	return false;
}

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
			case 'y':
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

void hand_handler(string word)
{
	for(int i = 0; i < int(word.size()); ++i)
	{
		for(int j = 0; j < 7; ++j)
		{
			if(word[i] == hand[j].ltr && hand[j].used != 1)
			{
				hand[j].used = 1;
				break;
			}
		}
	}
}


void next_step(int a)
{
	cout << ">>> To continiue press 1" << endl;
	cout << ">>> To start with new hand press 2" << endl;
	cout << ">>> To exit press 3" << endl;
	if(a != 1)
		cout << ">>> To read the rules press 4" << endl;
	

	cout << endl;

	cout << "Your input: ";

	int inp; cin >> inp;
	if(inp == 1)
	{
		game();
	}
	else if(inp == 2)
	{
		generate();
		res = 0;
		game();
	}
	else if(inp == 3)
	{
		exit(0);
	}
	else
	{
		rules(1);
	}
}

void game()
{
	cout << endl;
	cout << "You hand is: ";
	bool isempty = true;
	for(int i = 0; i < 7; ++i)
	{
		if(hand[i].used == 0)
		{
			cout << hand[i].ltr << ' ';
			isempty = false;
		}			
	}
	if(isempty)
	{
		cout << "No more letters! :(" << endl;
		cout << "Your result is: " << res << endl;
		cout << "Choose <Start with new hand>, <Exit> or <Read Rules> option" << endl;
		next_step(123);

	}
	cout << endl;
	cout << "Now input your word or 1 to exit: ";
	string word; word = input();
	if(word == "1")
	{
		exit(0);
	}
	cout << endl;
	cout << "*******************" << endl;
	cout << endl;
	if(check(word))
	{
		cout << "Krasavchik, brat! Ty ugadal slovo!" << endl;
		hand_handler(word);
		res += count(word);

		cout << "------------------------" << endl;
		cout << "Your result is: " << res << endl;
		cout << "------------------------" << endl;
		cout << endl;
	
		next_step(2);
	}
	else
	{	
		cout << "Sorry, brat! Net takogo slova :(((" << endl;
		hand_handler(word);

		cout << "------------------------" << endl;
		cout << "Your result is: " << res << endl;
		cout << "------------------------" << endl;
		cout << endl;
	
		next_step(2);
	}
}

int main()
{
	cout << "************************************" << endl;
	cout << "*    Welcome to Scrablle Game!     *" << endl;
	cout << "************************************" << endl;
	cout << endl;
	rules(123);
	cout << endl;
	cout << ">>> To start the game press 1;" << endl;
	cout << ">>> To exit press 2;" << endl;
	cout << "Your input: ";
	int inp; cin >> inp;
	if(inp == 1)
	{
		generate();
		game();
	}
	return 0;
}