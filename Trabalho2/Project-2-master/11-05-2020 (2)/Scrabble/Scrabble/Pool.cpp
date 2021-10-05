#include <stdlib.h> 
#include <time.h>

#include "Pool.h"

int Pool::showNumber() {
	return chars.size();
}

Pool::Pool(vector <char> vec)
{
	this->chars = vec;
}

char Pool::givePiece()
{
	int i;
	char a;
	srand(time(NULL));
	i = rand() % this->chars.size();
	a = chars[i];
	chars.erase(chars.begin() + i);
	return a;

}

void Pool::addToPool(char letter)
{
	this->chars.push_back(letter);
}


//w a t e r                 A W A W I T
//
//a w a i t