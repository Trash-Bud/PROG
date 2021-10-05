#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <Windows.h>
#include <stdlib.h> 
#include <time.h>


#ifndef POOl_H
#define POOL_H

class Pool
{
public:
	//constructor (builds the pool from the letters in the board)
	Pool(std::vector <char> vec);
	//-----------------

	//returns the size of the pool
	int showNumber();
	//-----------------

	//returns a piece in the pool and removes it from the pool
	char givePiece();
	//-----------------

	//adds a piece (letter) to the pool
	void addToPool(char letter);
	//-----------------


private:

	//vector that has all the letters in the pool
	std::vector<char> chars;
	//-----------------

};
#endif