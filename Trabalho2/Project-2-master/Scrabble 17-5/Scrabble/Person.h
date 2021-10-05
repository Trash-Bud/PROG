#include <iostream>
#include <string>
#include <vector>


#ifndef PERSON_H
#define PERSON_H

class Person {
public:
	//The constructer of the Class: Requires the player order (ex: 2 -> player 2)
	Person(int order);

	//-----------------------------------------------------
	//It is used to change the Name atribute of the object
	void defineName(std::string name);

	//-----------------------------------------------------
	//It's is used to print the player's hand
	void printhand(); 

	//-----------------------------------------------------
	//It's used to return the player's points
	int showpoints();

	//-----------------------------------------------------
	//It's used to return the hand vector
	std::vector<char> showhand();

	//-----------------------------------------------------
	// It's used return the order atribute of the object
	int showorder();

	//-----------------------------------------------------
	// It is used to return the name atribute of the object
	std::string showname();

	//-----------------------------------------------------
	// It is used to check if the piece the player chose is in his hand (in the piece refill)
	bool isInHand(char input);

	//-----------------------------------------------------
	// It is used to check if the piece the player choose is in his hand  (at choosing the letter and position to play the piece)
	bool findLetter(std::string input);

	//-----------------------------------------------------
	// It is used to remove from the player's hand the piece that was played (at choosing the letter and position to play the piece)
	void removePlayed(std::string input);

	//-----------------------------------------------------
	// It is used to add a piece from the pool to the player's hand
	void includeinHand(char input);

	//-----------------------------------------------------
	// It is used to remove from the player's hand the piece that was played (in the piece refill)
	void removeFromHand(char letter);

	//-----------------------------------------------------
	//It adds the points the player gathered in that round
	void addPoints(int i);

	//-----------------------------------------------------
	//It return the Hand vector size 
	int showHandSize();

private:

	std::string name; //name of the player
	unsigned int order; //order of the player (1-> player 1)
	unsigned int points; //points won
	std::vector<char> hand; //vector with the letters that the player has to play
	
};


#endif

