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

using namespace std;

//Colors-------------
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
//--------------------

// Checks how many moves the player can make in a row (returns 0 for 0, 1 for 1 and 2 for 2 or more)
int Board::hasMoves(vector<char> hand)
{
	forces2Moves.clear(); //the vector is cleared each time the function is called since it changes every single round

	int count = -1;                                           //iniciates the flag and if it keeps being -1 for the rest means, the program never entered the if ain the for loops
	vector <wordV> testNextMove;									  //test and handtest are vectors which will represent the hand and nextmove vectorsto simulate if the player can play two times 
	vector <char> handtest {};
	letterCoordinats lettertest;							  //To simulate a move wihtout changing letterCoordinats vectoe
	vector <letterCoordinats> testPiecesPlayed{};             //To simulate the piecesPlayed vector

	testNextMove = nextMove;
	testPiecesPlayed = piecesPlayed;

	for (int i = 0; i < hand.size(); i++) 
	{
		for (int e = 0; e < nextMove.size(); e++)  
		{
			if (hand[i] == nextMove[e].playableLetter)     //se encontrar o que possa jogar: cria 2 vetores teste para ver se pode jogar a prox letra
			{
				count = 0; //if count = 0 by the end it means that there was only one available move

				//created to add to the vector forces2Move if the player can make 2 moves
				lettertest.x = nextMove[e].x; 
				lettertest.y = nextMove[e].y;
				lettertest.letter = nextMove[e].playableLetter;

				testPiecesPlayed.push_back(lettertest); //adds to the test letterplayed vector the currnent letter and coordinats

				//updating test vector for the vector nextMove
				testNextMove[e].playableLetter = testNextMove[e].word[1];
				testNextMove[e].word = testNextMove[e].word.substr(1);

				if (testNextMove[e].orient == 'V')
					testNextMove[e].y += 1;
				else
					testNextMove[e].x += 1;

				//Checking if there are any playable letters that have already been played but were previosly in the middle of words and removing them if so

				if (testNextMove.size() == 0) //if after playing once the vector test (copy of next move) becomes empty then there is only one possible move
				{
					return 1;
				}
				else
				{
					for (int k = 0; k < testNextMove.size(); k++)
					{
						for (int f = 0; f < testPiecesPlayed.size(); f++)
						{
							if (testNextMove[k].playableLetter == testPiecesPlayed[f].letter && testNextMove[k].x == testPiecesPlayed[f].x && testNextMove[k].y == testPiecesPlayed[f].y)
							{
								if (testNextMove[k].word.size() == 1)
								{
									testNextMove.erase(testNextMove.begin() + k);
									if (k > 0)
									{
										k--; //to make sure the vsctor does not go out of range when an element is removed
									}

									if (testNextMove.size() == 0) //if after playing once the vector test (copy of next move) becomes empty then there is only one possible move
									{
										return 1;
									}
								}
								else
								{
									testNextMove[k].playableLetter = testNextMove[k].word[1];
									testNextMove[k].word = (testNextMove[k].word).substr(1);

									if (testNextMove[k].orient == 'V')
										testNextMove[k].y += 1;
									else
										testNextMove[k].x += 1;
								}
								f = 0;
							}
						}
					}
				}


				//Updates the handtest
				for (int d = 0; d < hand.size(); d++)
				{
					if (d != i)
						handtest.push_back(hand[d]);
				}
				
				//Tries to make a second move
				for (int j = 0; j < handtest.size(); j++)   //does the exact same thing bur fot the simulations vectors'
				{
					for (int k = 0; k < testNextMove.size(); k++)
					{
						if (handtest[j] == testNextMove[k].playableLetter) //if there is a letter in the players hand that can be played:
						{
							for (int l = 0; l< forces2Moves.size();l++)
							{
								if (forces2Moves[l].x == lettertest.x && forces2Moves[l].y == lettertest.y && forces2Moves[l].letter == lettertest.letter) //if the letter that allows to play twice is already in the vector it breaks the for
									break; 
								else if (l == forces2Moves.size() - 1)
								{
									forces2Moves.push_back(lettertest); //else it adds to the vector forces2Move
								}
							}
							if (forces2Moves.size() == 0)   //if it's empty, it will automaticly add to the vector'
								forces2Moves.push_back(lettertest);
						}								              
					}
				}
				testNextMove = nextMove;  //reset the simulation vectors
				testPiecesPlayed = piecesPlayed; //resets the vector for the next try
				handtest.clear(); 
			}
		}
	}

	/*cout << endl;

	for(int p= 0;p<forces2Moves.size();p++)
		cout<<forces2Moves[p].x<<" "<<forces2Moves[p].y<<" "<<forces2Moves[p].letter<<endl;                  debugging purposes

	cout << endl;*/

	if (forces2Moves.size() > 0) //if the vector has elements then there are moves that allow you to play twice
		return 2;
	else if (count == 0)  //never entered the second simulation if so player can only play once
		return 1;
	else				 //cannot play this round
		return 0;
}

//-----------------------------------------------------------------------------


void Board::createNM()               
{
	wordV w1;
	//                                         012 3 4...
	//string from vector words has the format "Yx H/V word"
	for (int i = 0; i < this->words.size(); i++)
	{
		w1.y = index[tolower(words[i][0])]; //turns the 'Y' into a number coordinate
		w1.x = index[words[i][1]]; //turns the 'X' into a number coordinate
		w1.orient = words[i][3];   //gets the orientation
		w1.word = words[i].substr(5); //gets the word
		w1.playableLetter = words[i][5]; //gets the first letter of the word
		this->nextMove.push_back(w1);
	}
}

//-----------------------------------------------------------------------------

vector<char> Board::exportList()
{
	vector<char> ret;     
	for (int i = 0; i < this->letterPositions.size(); i++)
	{
		ret.push_back(letterPositions[i].letter);   //creating a vector to be able to create the pool
	}
	return ret;
}

//-----------------------------------------------------------------------------

bool Board::played(string input, int &points, bool playedonce)
{
	letterCoordinats lplayed;    //transforming the info from the string the player wrote ("Yx H/V word") into the components of the struct "letterCoordinats"
	int x, y;
	char xc, yc;
	char letter;

	yc = input[0];
	xc = input[1];
	letter = input[3];

	x = this->index[xc];
	y = this->index[tolower(yc)];

	//cout << x << " " << y << " " << letter;    debug...
	
	if (this->forces2Moves.size() > 0 && !playedonce)         //this piece of code is about the first move of the player if he can play twice.
		                                                      //If the flag is off (the player hasn't played already) and the forces2Moves is not empty, this allows the player to make the first move of two the player can make
	{
		for (int i = 0; i < forces2Moves.size(); i++)
		{
			
			if (forces2Moves[i].x == x && forces2Moves[i].y == y && forces2Moves[i].letter == letter) //if the letter played is found in the forces2Move then it allows the move
			{
				for (int k = 0; k < nextMove.size(); k++)
				{
					if (nextMove[k].playableLetter == letter && nextMove[k].y == y && nextMove[k].x == x)   //this updates the vector "NewMoves" if the player chooses a valid move
					{
						if (nextMove[k].word.size() == 1)     //it is here where we add the points to the player and remove from the vector "NewMove" the empty words. --> represents the fact that the player ended a word
						{
							points++;
							nextMove.erase(nextMove.begin() + k);
							forces2Moves.clear();     //reseting the forces2Moves vector
							break;
						}
						else
						{
							nextMove[k].playableLetter = nextMove[k].word[1];       //updating the NewMoves vector
							nextMove[k].word = (nextMove[k].word).substr(1);

							if (nextMove[k].orient == 'V')
								nextMove[k].y += 1;
							else
								nextMove[k].x += 1;

							forces2Moves.clear();     //reseting the forces2Moves vector
							break;
						}
					}
				}
				break;
				
			}
			else if (i == forces2Moves.size() - 1) //if it reaches the end of the vector withtout finding anything then move wasn't valid and the function returns false
			{
				cout << " This move is either invalid or there is a diferent move which allows you to play twice! Whenever possible you must make a move that enables you to play twice!" << endl;

				return false;
			}
		}
	}
	else {                                                           //the move either is the second move or the first move if there are none more avaible moves
		for (int i = 0; i < this->nextMove.size(); i++)
		{

			//cout << nextMove[i].playableLetter << " " << nextMove[i].x << " " << nextMove[i].y << endl;    debug...

			if (nextMove[i].playableLetter == letter && nextMove[i].y == y && nextMove[i].x == x) //the same as the other if without checking the vector forces2Move
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

	lplayed.letter = letter;       //Creating a new variable with the played piece to enter the piecesPlayed vector to further check 
	lplayed.x = x;
	lplayed.y = y;
	this->piecesPlayed.push_back(lplayed);

	if (this->nextMove.size() == 0)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < this->nextMove.size(); i++)    //check if a piece that was previously on the middle of a word but is now marked as the playable letter has already been played 
		{
			for (int e = 0; e < this->piecesPlayed.size(); e++)
			{
				if (nextMove[i].playableLetter == piecesPlayed[e].letter && nextMove[i].x == piecesPlayed[e].x && nextMove[i].y == piecesPlayed[e].y) //the same process as the other two
				{
					if (nextMove[i].word.size() == 1)
					{
						points++;
						nextMove.erase(nextMove.begin() + i);
						if (i > 0)
						{
							i--; //to make sure that the vector doesn't go out of range when an element is removed
						}
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
					e = 0; //resets the e so it checks the new playable letter with every letter from the vector piecesPlayed again
				}
			}
		}
	}

	
	return true;
}

//-----------------------------------------------------------------------------

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
			if (this->piecesPlayed[i].letter == let.letter && this->piecesPlayed[i].x == let.x && this->piecesPlayed[i].y == let.y)      //check if it is a pieced that was played or not :
			{																																//-> if it was, it will turn red on (1)
				count++;			//(1)																										//-> else, it stays white on the board::show (2)
				setColor(4);			
				cout << let.letter;
				setColor(15);
				break;
			}
			if (i == piecesPlayed.size() - 1)    //(2)
			{
				cout << let.letter;
			}
		}
	}

}

//-----------------------------------------------------------------------------

Board::Board(string filename) //unpacking board
{
	ifstream board;
	string c;
	stringstream m;
	int counter{ 0 };
	string loc, ori, let;

	this->piecesPlayed = {};

	board.open(filename + ".txt");

	while (board >> c)       //this will read the file and give the info to the corresponding board vectors
	{
		if (c == "BOARD_PREVIEW:")
		{
			break;
		}
		if (counter == 0) // it is taking the size1 info
		{
			m << c;
			m >> size1;
			m.clear();
			counter++;
			continue;
		}
		if (counter == 1)  // it should receive the "x" form "size1 x size2" so we dont bother to get
		{
			counter++;
			continue;
		}
		if (counter == 2) // it is taing the size2 info
		{
			m << c;
			m >> size2;
			counter++;
			continue;
		}
		else
		{
			if (counter % 3 == 0)  //from now on, because we now the info will come in "Aa H/V letter":
			{							//-> when "counter % 3 == 0", it will represent the Aa 
				loc = c;				//-> when "counter % 3 == 1", it will represent the H/V
				counter++;				//-> when "counter % 3 == 2", it will represent the letter
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
	createNM();      // creates the NewMoves vector

	convertToIndexes();   //creates the vector LetterCoordinats
}

//-----------------------------------------------------------------------------

void Board::show(string Alphabet, int counter, int numPlayers, int pP1, int pP2, int pP3, int pP4, vector<char> hP1, vector<char> hP2, vector<char> hP3, vector<char> hP4, string nameP1, string nameP2, string nameP3, string nameP4, int npool)
{
	system("cls"); //clears the console

	cout << " ";

	//prints the board table and the words in it 
	for (int y = 0; y <= this->size2; y++)
	{
		for (int x = 0; x <= this->size1; x++)
		{
			if (y == 0 && x != size1)
				cout << "| " << (char)tolower(Alphabet[x]);
			else if (x == 0)
				cout << Alphabet[y - 1] << "| ";
			else
			{
				setPlayedColor(indexLetter(x, y));
				cout << "  ";
			}

			if (x == size1)
				cout << endl;
		}
	}

	cout << endl;

	//prints out the player name, hand and points if it is not their turn
	if (counter % numPlayers != 0)
	{
		cout << nameP1 << ": Hand - ";
		for (int i = 0; i < hP1.size(); i++)
		{
			cout << hP1[i] << "  ";
		}
		cout << "Points - " << pP1 << endl;
	}
	if (counter % numPlayers != 1)
	{
		cout << nameP2 << ": Hand - ";
		for (int i = 0; i < hP2.size(); i++)
		{
			cout << hP2[i] << "  ";
		}
		cout << "Points - " << pP2 << endl;
	}
	if (counter % numPlayers != 2 && numPlayers >= 3)
	{
		cout << nameP3 << ": Hand - ";
		for (int i = 0; i < hP3.size(); i++)
		{
			cout << hP3[i] << "  ";
		}
		cout << "Points - " << pP3 << endl;
	}
	if (counter % numPlayers != 3 && numPlayers == 4)
	{
		cout << nameP4 << ": Hand - ";
		for (int i = 0; i < hP4.size(); i++)
		{
			cout << hP4[i] << "  ";
		}
		cout << "Points - " << pP4 << endl;
	}
	cout << endl;


	//prints the name, hand and points of the current player further down if it is their turn
	if (counter % numPlayers == 0)
	{
		cout <<"Currently playing - " << nameP1 << ": Hand - ";
		for (int i = 0; i < hP1.size(); i++)
		{
			cout << hP1[i] << "  ";
		}
		cout << "Points - " << pP1 << endl;
	}
	else if (counter % numPlayers == 1)
	{
		cout <<"Currently playing - " << nameP2 << ": Hand - ";
		for (int i = 0; i < hP2.size(); i++)
		{
			cout << hP2[i] << "  ";
		}
		cout << "Points - " << pP2 << endl;
	}
	else if (counter % numPlayers == 2)
	{
		cout << "Currently playing - " << nameP3 << ": Hand - ";
		for (int i = 0; i < hP3.size(); i++)
		{
			cout << hP3[i] << "  ";
		}
		cout << "Points - " << pP3 << endl;
	}
	else if (counter % numPlayers == 3)
	{
		cout << "Currently playing - " << nameP4 << ": Hand - ";
		for (int i = 0; i < hP4.size(); i++)
		{
			cout << hP4[i] << "  ";
		}
		cout << "Points - " << pP4 << endl;
	}
	cout << endl;

	//prints out the number of letters in the pool
	cout << "Remaining letters on the pool: " << npool << endl;

}

//-----------------------------------------------------------------------------

Board::letterCoordinats Board::indexLetter(int x, int y)
{
	letterCoordinats a;
	// e, g, g
	// letter_coordinates -> x = x, y = y , letter = e
	// letter_coordinates[0], ...

	for (int i = 0; i < this->letterPositions.size(); i++)
	{
		if (this->letterPositions[i].x + 1 == x && this->letterPositions[i].y + 1 == y)
		{
			return this->letterPositions[i]; //if there is a letter in the vector with the coordinats it returns that letter and its coordinats to later check if it has already been played (color)
		}
	}

	a.letter = ' ';
	a.x = x;
	a.y = y;

	return a; //if not it returns an empty space with  the selected coordinats
}

//-----------------------------------------------------------------------------

void Board::setColor(unsigned int color)    //changes the color of the output
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

//-----------------------------------------------------------------------------

void Board::convertToIndexes()
{
	char x, y, direction;
	string word;
	letterCoordinats coordinat;

	for (int i = 0; i < words.size(); i++)
	{
		//devides de string from the words vector
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
				//cout << "a";      debug...

				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				x++; //increases x if the orientation is horizontal

				for (int k = 0; k < this->letterPositions.size(); k++)
				{
					//cout << "b";      debug...

					if (this->letterPositions[k].x == coordinat.x && this->letterPositions[k].y == coordinat.y) //if the letter is already in it doesn't add it again (some words shre letters)
					{
						break;
					}
					if (k == this->letterPositions.size() - 1) //if the letter isn't in it adds it to the vector 
					{
						this->letterPositions.push_back(coordinat);
					}

				}

				if (this->letterPositions.size() == 0)  //in case the vector is empty since it doesn't enter the for cycle
				{
					this->letterPositions.push_back(coordinat);
				}

			}
		}
		else
		{
			for (int j = 0; j < word.size(); j++)
			{
				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				y++; //increases the y if the orientation is orizontal

				for (int k = 0; k < this->letterPositions.size(); k++) //same as the one above
				{
					//cout << "a";     debug...

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
