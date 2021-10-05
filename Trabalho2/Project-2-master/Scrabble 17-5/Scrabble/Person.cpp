#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
using namespace std;

//----------------------------
int Person::showpoints()
{
	return this-> points;
}
//----------------------------

//----------------------------
int Person::showorder()	
{
	return this->order;
}
//----------------------------

//----------------------------
string Person::showname()
{
	return this->name;
}
//----------------------------

//----------------------------
void Person::addPoints(int i) 
{
	this->points += i;
}
//----------------------------

//----------------------------
int Person::showHandSize()
{
	return this-> hand.size();
}
//----------------------------

//----------------------------
Person::Person(int order)
{
	this->name = "default";
	this->hand = {};
	this->order = order;
	this->points = 0;
}
//----------------------------

//----------------------------
void Person::defineName(string name)
{
	this->name = name;
}
//----------------------------

//----------------------------
void Person::printhand()
{

	cout << this->name << " :" << endl;
	cout << "Points:" << this->points << endl;
	for (int i = 0; i < this->hand.size(); i++)
	{
		cout << hand[i] << " ";
	}
	cout << endl;
}
//----------------------------

//----------------------------
bool Person::findLetter(string input)
{
	for (int i = 0; i < this->hand.size(); i++)
	{
		if (input[3] == hand[i])
		{
			return true;
		}
	}
	return false;
}
//----------------------------

//----------------------------
void Person::removePlayed(string input)
{
	for (int i = 0; i < this->hand.size(); i++)
	{
		if (input[3] == hand[i])
		{
			hand.erase(hand.begin() + i);
			break;
		}
	}
}
//----------------------------

//----------------------------
void Person::includeinHand(char input)
{
	this->hand.push_back(input);
}
//----------------------------

//----------------------------
vector<char> Person::showhand()
{
	return this->hand;
}
//----------------------------

//----------------------------
void Person::removeFromHand(char letter)
{
	for(int i = 0; i < this->hand.size(); i++)
	{
		if (letter == hand[i])
		{
			hand.erase(hand.begin() + i);
			break;
		}	
	}
}
//----------------------------

//----------------------------
bool Person::isInHand(char input)
{

	for (int i = 0; i < this->hand.size(); i++)
	{
		if (input == hand[i])
			return true;
	}

	return false;
}
//----------------------------
