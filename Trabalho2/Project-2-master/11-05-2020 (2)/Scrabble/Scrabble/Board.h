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
using namespace std;

#ifndef BOARD_H
#define BOARD_H


class Board {
public:
	Board(string filename);
	void show(string AlphabeT);

	void show(string Alphabet, int conter, int pP1, int pP2, int pP3, int pP4, vector<char> hP1, vector<char> hP2, vector<char> hP3, vector<char> hP4);

	//to see the vector letterCoordinats (for debug)
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
	//

	// Show vector next move (for debug)
	void showNM() {

		cout << endl << "Vector Next Move:" << endl;
		for (int i = 0; i < this->nextMove.size(); i++)
		{
			cout << i << "- x = " << this->nextMove[i].x << "; y = " << this->nextMove[i].y << "; word = " << this->nextMove[i].word << "; next letter = " << this->nextMove[i].playableLetter << endl;
		}
	};
	//

	bool played(string input, int& points, bool playedonce);
	int hasMoves(vector<char> hand);
	vector<char> exportList();

private:

	int size1;
	int size2;

	struct letterCoordinats {

		char letter;
		int x, y;
	};

	struct wordV {

		string word;
		char playableLetter, orient;
		int x, y;
	};

	vector<letterCoordinats> letterPositions;
	vector<string> words;   
	vector<wordV> nextMove;
	vector<letterCoordinats> forces2Moves;

	vector<letterCoordinats> piecesPlayed;
	void createNM();
	void setPlayedColor(letterCoordinats let);
	void setColor(unsigned int color);

	letterCoordinats indexLetter(int x, int y);
	void convertToIndexes();

	map<char, int> index = {
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
