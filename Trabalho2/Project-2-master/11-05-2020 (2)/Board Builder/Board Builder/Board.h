#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <cctype>

using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
	Board();
	void setSize(int size1, int size2);
	void show(string AlphabeT);
	bool isValid(string input);
	bool remove(string input);
	void print();


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
	}


private:
	int size1;
	int size2;

	struct letterCoordinats {

		char letter;
		int x, y;
	};

	vector<letterCoordinats> letterPositions;
	vector<string> words;

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
	map<int, string> letters = {
		{0, "a"},
		{1, "b"},
		{2, "c"},
		{3, "d"},
		{4, "e"},
		{5, "f"},
		{6, "g"},
		{7, "h"},
		{8, "i"},
		{9, "j"},
		{10, "k"},
		{11, "l"},
		{12, "m"},
		{13, "n"},
		{14, "o"},
		{15, "p"},
		{16, "q"},
		{17, "r"},
		{18, "s"},
		{19 ,"t"}
	};
	map<int, string> lettersup = {
		{0, "A"},
		{1, "B"},
		{2, "C"},
		{3, "D"},
		{4, "E"},
		{5, "F"},
		{6, "G"},
		{7, "G"},
		{8, "I"},
		{9, "J"},
		{10, "K"},
		{11, "L"},
		{12, "M"},
		{13, "N"},
		{14, "O"},
		{15, "P"},
		{16, "Q"},
		{17, "R"},
		{18, "S"},
		{19 ,"T"}
	};

	char indexLetter(int x, int y);
	void convertToIndexes();
	//idea: to make the process faster make the function recognize if we are making an edit
	//(removing or changing a position) or if an item is being added, if the former then the vector should
	//be cleared otherwise do a pushback of the element on vector<string>

	bool positionIsValid(int x, int y, char direction, string word);
	// Do we need need to replace words formed by other words to the final list? -----> monitor 2ª

	void composeFinal();

	string composeWordXp(int x, int y, vector<letterCoordinats>& letterPos);
	string composeWordXm(int x, int y, vector<letterCoordinats>& letterPos);
	string composeWordYp(int x, int y, vector<letterCoordinats>& letterPos);
	string composeWordYm(int x, int y, vector<letterCoordinats>& letterPos);
};


#endif 
