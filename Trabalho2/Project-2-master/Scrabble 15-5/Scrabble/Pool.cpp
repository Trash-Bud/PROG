#include <stdlib.h> 
#include <time.h>

#include "Pool.h"

using namespace std;

//-------------------------------
int Pool::showNumber() {

	return chars.size();
}
//-------------------------------

//-------------------------------
Pool::Pool(vector <char> vec)
{
	this->chars = vec;
}
//-------------------------------

//-------------------------------
char Pool::givePiece()
{
	int i;
	char a;

	srand(time(NULL)); //generates a random seed for the random numbers

	i = rand() % this->chars.size();
	a = chars[i];

	chars.erase(chars.begin() + i); //removes the number

	return a;
}
//-------------------------------

void Pool::addToPool(char letter)
{
	this->chars.push_back(letter);
}

//-------------------------------