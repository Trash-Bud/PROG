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

#ifndef BOARD_H
#define BOARD_H

class Board {
public:

	//Constructor: creates the board from the file: filename.txt
	Board(std::string filename);
	//----------------------

	// Prints the board with the player hands and points 
	void show(std::string Alphabet, int counter, int numPlayers, int pP1, int pP2, int pP3, int pP4, std::vector<char> hP1, std::vector<char> hP2, std::vector<char> hP3, std::vector<char> hP4, std::string nameP1, std::string nameP2, std::string nameP3, std::string nameP4, int npool);
	//----------------------

	//Makes the move inputed by the player
	bool played(std::string input, int& points, bool playedonce);
	//----------------------

	//Checks how many moves the player can make
	int hasMoves(std::vector<char> hand);
	//----------------------

	//Returns the letter coordinates list (to create the pool)
	std::vector<char> exportList();
	//----------------------


	//FOR DEBUG! -------------------------------------------
	//to see the vector letterCoordinats
	int showlpx(int i) {
		return this->letterPositions[i].x;
	};
	int showlpy(int i) {
		return this->letterPositions[i].y;
	};
	char showlplt(int i) {
		return this->letterPositions[i].letter;
	};
	int showlpsize() {
		return this->letterPositions.size();

	};
	int showsize1() {
		return this->size1;
	};
	int showsize2() {
		return this -> size2;
	};
	// Show vector next move (for debug)
	void showNM() { 

		std::cout << std::endl << "Vector Next Move:" << std::endl;
		for (int i = 0; i < this->nextMove.size(); i++)
		{
			std::cout << i << "- x = " << this->nextMove[i].x << "; y = " << this->nextMove[i].y << "; word = " << this->nextMove[i].word << "; next letter = " << this->nextMove[i].playableLetter << std::endl;
		}
	};
	//----------------------------------------------

private:

	int size1; //size horizontal
	int size2; //size vestical

	//struct that saves the letter and its coordinates 
	struct letterCoordinats { 

		char letter;
		int x, y;
	};
	//------------------------------------------------

	//struct that saves what's left of the word (hasn't been played yet), playable letter (1st letter of the word to not have been played) and its coordinates and the orientation of the word 
	struct wordV {

		std::string word;
		char playableLetter, orient;
		int x, y;
	};
	//------------------------------------------------

	//letter coordinars of the letters which form the board
	std::vector<letterCoordinats> letterPositions;
	//------------------------------------------------

	//Words, orientations and starting coordinates of the words in the board (format: "Yx H/V word)
	std::vector<std::string> words;   
	//------------------------------------------------

	//Words, orientations, starting coordinates and playable letters to know what letters the player is capable of playing
	std::vector<wordV> nextMove;
	//------------------------------------------------

	//Since the player is forced to play twice if they are capable of playing twice this vector has the playable letters and their coordinates that allow the players to make two moves
	std::vector<letterCoordinats> forces2Moves;
	//------------------------------------------------

	//Contains all the pieces that have already been played and their coordinates
	std::vector<letterCoordinats> piecesPlayed;
	//------------------------------------------------

	//Creates the nextMove (NM) vector from the words vector
	void createNM();
	//------------------------------------------------

	//Makes the already played letters red
	void setPlayedColor(letterCoordinats let);
	//------------------------------------------------

	//Sets colors
	void setColor(unsigned int color);
	//------------------------------------------------

	//Checks if there is a letter in those coordinats or if there is nothing
	letterCoordinats indexLetter(int x, int y);
	//------------------------------------------------

	//Turns the words in the vector words in letters and their respective coordinats and then fills the vector letterPositions with them
	void convertToIndexes();
	//------------------------------------------------


	std::map<char, int> index = {
	{'a', 0},
	{'b', 1},
	{'c', 2},
	{'d', 3},
	{'e', 4},
	{'f', 5},
	{'g', 6},
	{'h', 7},
	{'i', 8},
	{'j', 9},
	{'k', 10},
	{'l', 11},
	{'m', 12},
	{'n', 13},
	{'o', 14},
	{'p', 15},
	{'q', 16},
	{'r', 17},
	{'s', 18},
	{'t', 19}
	};
};

#endif 
