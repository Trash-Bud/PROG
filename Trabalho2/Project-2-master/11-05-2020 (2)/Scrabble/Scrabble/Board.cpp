#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <Windows.h>
#include <sstream>
#include <algorithm>

#include "Board.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

int Board::hasMoves(vector<char> hand)
{
	forces2Moves.clear();
	int count = -1;
	vector <wordV> test (nextMove);
	vector <char> handtest {};
	letterCoordinats lettertest;
	vector<char>::iterator it;
	it = handtest.begin();

	for (int i = 0; i < hand.size(); i++)
	{
		for (int e = 0; e < nextMove.size(); e++)
		{
			
			if (hand[i] == nextMove[e].playableLetter)     //se encontrar o que possa jogar: cria 2 vetores teste para ver se pode jogar a prox letra tb
			{
				count = 0;

				lettertest.x = nextMove[e].x;
				lettertest.y = nextMove[e].y;
				lettertest.letter = nextMove[e].playableLetter;

				test[e].playableLetter = test[e].word[1];
				test[e].word = test[e].word.substr(1);

				if (test[e].orient == 'V')
					test[e].y += 1;
				else
					test[e].x += 1;
				
				for (int d = 0; d < hand.size(); d++)
				{
					if (d != i)
						handtest.push_back(hand[d]);
				}
				

				for (int j = 0; j < handtest.size(); j++)
				{
					for (int k = 0; k < test.size(); k++)
					{
						if (handtest[j] == test[k].playableLetter)
						{
							for (int l = 0; l< forces2Moves.size();l++)
							{
								if (forces2Moves[l].x == lettertest.x && forces2Moves[l].y == lettertest.y && forces2Moves[l].letter == lettertest.letter)
									break;
								else if (l == forces2Moves.size() - 1)
								{
									forces2Moves.push_back(lettertest);
								}
							}
							if (forces2Moves.size() == 0)
								forces2Moves.push_back(lettertest);
						}								              
					}
				}
				test = nextMove;
				handtest.clear();
			}
		}
	}
	cout << endl;
	//for(int p= 0;p<forces2Moves.size();p++)
		//cout<<forces2Moves[p].x<<" "<<forces2Moves[p].y<<" "<<forces2Moves[p].letter<<endl;
	cout << endl;

	if (forces2Moves.size() > 0)

		return 2;
	else if (count == 0)
		return 1;
	else
		return 0;
}

void Board::createNM()
{
	wordV w1;
	for (int i = 0; i < this->words.size(); i++)
	{
		w1.y = index[tolower(words[i][0])];
		w1.x = index[words[i][1]];
		w1.orient = words[i][3];
		w1.word = words[i].substr(5);
		w1.playableLetter = words[i][5];
		this->nextMove.push_back(w1);
	}
}
vector<char> Board::exportList()
{
	vector<char> ret;
	for (int i = 0; i < this->letterPositions.size(); i++)
	{
		ret.push_back(letterPositions[i].letter);
	}
	return ret;
}


bool Board::played(string input, int &points, bool playedonce)
{
	letterCoordinats lplayed;
	int x, y;
	char xc, yc;
	char letter;

	yc = input[0];
	xc = input[1];
	letter = input[3];

	x = this->index[xc];
	y = this->index[tolower(yc)];
	//cout << x << " " << y << " " << letter;
	
	if (this->forces2Moves.size() > 0 && !playedonce)
	{
		
		for (int i = 0; i < forces2Moves.size(); i++)
		{
			
			if (forces2Moves[i].x == x && forces2Moves[i].y == y && forces2Moves[i].letter == letter)
			{
				for (int k = 0; k < nextMove.size(); k++)
				{
					if (nextMove[k].playableLetter == letter && nextMove[k].y == y && nextMove[k].x == x)
					{
						if (nextMove[k].word.size() == 1)
						{
							points++;
							nextMove.erase(nextMove.begin() + k);
							forces2Moves.clear();
							break;
						}
						else
						{
							nextMove[k].playableLetter = nextMove[k].word[1];
							nextMove[k].word = (nextMove[k].word).substr(1);

							if (nextMove[k].orient == 'V')
								nextMove[k].y += 1;
							else
								nextMove[k].x += 1;
							forces2Moves.clear();
							break;
						}
					}
				}
				break;
				
			}
			else if (i == forces2Moves.size() - 1)
			{
				return false;
			}
		}
	}
	else {
		for (int i = 0; i < this->nextMove.size(); i++)
		{
			//cout << nextMove[i].playableLetter << " " << nextMove[i].x << " " << nextMove[i].y << endl;
			if (nextMove[i].playableLetter == letter && nextMove[i].y == y && nextMove[i].x == x)
			{
				if (nextMove[i].word.size() == 1)
				{
					points++;
					nextMove.erase(nextMove.begin() + i);
					break;
				}
				else
				{
					nextMove[i].playableLetter = nextMove[i].word[1];
					nextMove[i].word = (nextMove[i].word).substr(1);

					if (nextMove[i].orient == 'V')
						nextMove[i].y += 1;
					else
						nextMove[i].x += 1;
					break;
				}
			}
			if (i == nextMove.size() - 1)
			{
				return false;
			}
		}

	}
	lplayed.letter = letter;
	lplayed.x = x;
	lplayed.y = y;
	this->piecesPlayed.push_back(lplayed);

	for (int i = 0; i < this->nextMove.size(); i++)
	{
		for (int e = 0; e < this->piecesPlayed.size(); e++)
		{

			if (nextMove[i].playableLetter == piecesPlayed[e].letter && nextMove[i].x == piecesPlayed[e].x && nextMove[i].y == piecesPlayed[e].y)
			{
				if (nextMove[i].word.size() == 1)
				{
					points++;
					nextMove.erase(nextMove.begin() + i);
				}
				else
				{
					nextMove[i].playableLetter = nextMove[i].word[1];
					nextMove[i].word = (nextMove[i].word).substr(1);

					if (nextMove[i].orient == 'V')
						nextMove[i].y += 1;
					else
						nextMove[i].x += 1;
				}		
			}
		}
	}

	
	return true;
}

void Board::setPlayedColor(letterCoordinats let)
{
	int count = 0;
	if (this->piecesPlayed.size() == 0 or this->piecesPlayed.size() == count)
	{
		cout << let.letter;
	}
	else
	{
		for (int i = 0; i < this->piecesPlayed.size(); i++)
		{
			if (this->piecesPlayed[i].letter == let.letter && this->piecesPlayed[i].x == let.x && this->piecesPlayed[i].y == let.y)
			{
				count++;
				setColor(4);
				cout << let.letter;
				setColor(15);
				break;
			}
			if (i == piecesPlayed.size() - 1)
			{
				cout << let.letter;
			}
		}
	}

}

Board::Board(string filename) //unpacking board
{
	ifstream board;
	string c;
	stringstream m;
	int counter{ 0 };
	string loc, ori, let;

	this->piecesPlayed = {};

	board.open(filename + ".txt");

	while (board >> c)
	{
		if (c == "Board_Preview:")
		{
			break;
		}
		if (counter == 0) // size1 x size2
		{
			m << c;
			m >> size1;
			m.clear();
			counter++;
			continue;
		}
		if (counter == 1)
		{
			counter++;
			continue;
		}
		if (counter == 2)
		{
			m << c;
			m >> size2;
			counter++;
			continue;
		}
		else
		{
			if (counter % 3 == 0)
			{
				loc = c;
				counter++;
				continue;
			}
			if (counter % 3 == 1)
			{
				ori = c;
				counter++;
				continue;
			}
			if (counter % 3 == 2)
			{
				let = c;
				counter++;
				this->words.push_back(loc + " " + ori + " " + let);
			}
		}
	}
	createNM();

	convertToIndexes();
}



void Board::show(string AlphabeT)
{
	system("cls");

	cout << " ";
	for (int y = 0; y <= this->size2; y++)
	{
		for (int x = 0; x <= this->size1; x++)
		{

			if (y == 0 && x != size1)
				cout << "| " << (char)tolower(AlphabeT[x]);
			else if (x == 0)
				cout << AlphabeT[y - 1] << "| ";
			else
			{
				setPlayedColor(indexLetter(x, y));
				cout << "  ";
			}

			if (x == size1)
				cout << endl;

		}
	}
}

Board::letterCoordinats Board::indexLetter(int x, int y)
{
	letterCoordinats a;
	// e, g, g
	// letter_coordinates -> x = x, y = y , letter = e
	// letter_coordinates[0].x, ...

	for (int i = 0; i < this->letterPositions.size(); i++)
	{
		if (this->letterPositions[i].x + 1 == x && this->letterPositions[i].y + 1 == y)
		{
			return this->letterPositions[i];
		}
	}

	a.letter = ' ';
	a.x = x;
	a.y = y;
	return a;
}

void Board::setColor(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void Board::convertToIndexes()
{
	char x, y, direction;
	string word;
	letterCoordinats coordinat;

	for (int i = 0; i < words.size(); i++)
	{
		// "Aa H palavra"
		y = words[i][0];
		x = words[i][1];
		direction = words[i][3];
		word = words[i].substr(5);

		y = index[tolower(y)];
		x = index[x];


		if (direction == 'H')
		{
			for (int j = 0; j < word.size(); j++)
			{
				//cout << "a";
				//letter_cordinate = [ 'letra', x, y]
				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				x++;
				for (int k = 0; k < this->letterPositions.size(); k++)
				{
					//cout << "b";
					if (this->letterPositions[k].x == coordinat.x && this->letterPositions[k].y == coordinat.y)
					{
						break;
					}
					if (k == this->letterPositions.size() - 1)
					{
						this->letterPositions.push_back(coordinat);
					}
				}
				if (this->letterPositions.size() == 0)
				{
					this->letterPositions.push_back(coordinat);
				}
			}
		}
		else
		{
			for (int j = 0; j < word.size(); j++)
			{
				//letter_cordinate = [ 'letra', x, y]
				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				y++;
				for (int k = 0; k < this->letterPositions.size(); k++)
				{
					//cout << "a";
					if (this->letterPositions[k].x == coordinat.x && this->letterPositions[k].y == coordinat.y)
						break;
					if (k == this->letterPositions.size() - 1)
					{
						this->letterPositions.push_back(coordinat);
					}

				}
				if (this->letterPositions.size() == 0)
				{
					this->letterPositions.push_back(coordinat);
				}

			}
		}
	}
}
