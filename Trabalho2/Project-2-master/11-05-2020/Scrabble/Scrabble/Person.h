#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#include "Pool.h"


#ifndef PERSON_H
#define PERSON_H
class Person {
public:
	Person(int order);

	void defineName(string name);
	void printhand(); 
	int showpoints();

	vector<char> showhand();

	int showorder();

	string showname();

	bool findLetter(string input);
	void removePlayed(string input);
	void includeinHand(char input);
	void removeFromHand(char letter);

	void addPoints(int i);

	int showHandSize();

private:

	string name;
	unsigned int order;
	unsigned int points;
	vector<char> hand;
	
};


#endif

