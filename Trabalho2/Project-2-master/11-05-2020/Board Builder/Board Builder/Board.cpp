#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <cctype>

#include "Board.h"

string Board::composeWordXp(int x, int y, vector<letterCoordinats>& letterPos)
{
	char l;

	for (int j = 0; j < letterPos.size(); j++)
	{
		if (letterPos[j].x == x + 1 && letterPos[j].y == y)
		{
			l = letterPos[j].letter;
			letterPos.erase(letterPos.begin() + j);
			return l + composeWordXp(x + 1, y, letterPos);
		}
	}
	return "";
}

string Board::composeWordXm(int x, int y, vector<letterCoordinats>& letterPos)
{
	char l;

	for (int j = 0; j < letterPos.size(); j++)
	{
		if (letterPos[j].x == x - 1 && letterPos[j].y == y)
		{
			l = letterPos[j].letter;
			letterPos.erase(letterPos.begin() + j);
			return l + composeWordXm(x - 1, y, letterPos);
		}
	}
	return "";
}

string Board::composeWordYp(int x, int y, vector<letterCoordinats>& letterPos)
{
	char l;

	for (int j = 0; j < letterPos.size(); j++)
	{
		if (letterPos[j].x == x && letterPos[j].y == y + 1)
		{
			l = letterPos[j].letter;
			letterPos.erase(letterPos.begin() + j);
			return l + composeWordYp(x, y + 1, letterPos);
		}
	}
	return "";
}

string Board::composeWordYm(int x, int y, vector<letterCoordinats>& letterPos)
{
	char l;

	for (int j = 0; j < letterPos.size(); j++)
	{
		//cout << j;
		if (letterPos[j].x == x && letterPos[j].y == y - 1)
		{
			l = letterPos[j].letter;
			letterPos.erase(letterPos.begin() + j);

			return l + composeWordYm(x, y - 1, letterPos);
		}
	}
	return "";
}

Board::Board() //default board
{
	this->size1 = 15;
	this->size2 = 15;
}


void Board::setSize(int size1, int size2)
{
	this->size1 = size1;
	this->size2 = size2;
}

void Board::show(string AlphabeT)
{
	//size1 - horizontal, size2 - vertical

//  a b ... <--- x - size1
//A
//B
//...
//|
//v  y - size2

	system("cls");

	cout << " ";
	for (int y = 0; y <= this->size2; y++)
	{
		for (int x = 0; x <= this->size1; x++)
		{

			if (y == 0 && x != size1)
				cout << "| " << (char)tolower(AlphabeT[x]);
			else if (x == 0)
				cout << AlphabeT[y - 1] << "| ";
			else
			{
				cout << indexLetter(x, y) << "  ";
			}

			if (x == size1)
				cout << endl;

		}
	}
}

char Board::indexLetter(int x, int y)
{
	// e, g, g
	// letter_coordinates -> x = x, y = y , letter = e
	// letter_coordinates[0].x, ...

	for (int i = 0; i < this->letterPositions.size(); i++)
	{
		if (this->letterPositions[i].x + 1 == x && this->letterPositions[i].y + 1 == y)
		{
			return this->letterPositions[i].letter;
		}
	}
	return ' ';
}

void Board::convertToIndexes()
{
	//Format of input: words = ["yx H palavra",...] -->  letter_Position = [letter_coordinets1(x,y,letter),...]
	//                    index: 012345->...


	this->letterPositions.clear();

	char x, y, direction;
	string word;
	letterCoordinats coordinat;

	for (int i = 0; i < words.size(); i++)
	{
		// "Aa H palavra"
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
				//cout << "a";
				//letter_cordinate = [ 'letra', x, y]
				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				x++;
				for (int k = 0; k < this->letterPositions.size(); k++)
				{
					//cout << "b";
					if (this->letterPositions[k].x == coordinat.x && this->letterPositions[k].y == coordinat.y)
					{
						break;
					}
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
		else
		{
			for (int j = 0; j < word.size(); j++)
			{
				//letter_cordinate = [ 'letra', x, y]
				coordinat.x = x;
				coordinat.y = y;
				coordinat.letter = word[j];
				y++;
				for (int k = 0; k < this->letterPositions.size(); k++)
				{
					//cout << "a";
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

bool Board::isValid(string input)
{
	ifstream dictionary;
	string word, content;
	int y, x, ix, iy;
	char direction;

	dictionary.open("WORDS.TXT");

	y = input[0];
	x = input[1];
	direction = input[3];
	word = input.substr(5);
	y = index[tolower(y)];
	x = index[x];

	iy = y;	//initial x and y
	ix = x;

	while (dictionary >> content)
	{
		if (word == content)
		{
			if (direction == 'H')
			{
				if (x + word.size() > this->size1)  //checks if word fits in the orientation chosen
				{
					cout << "There isn't enough space to write the word here" << endl;
					Sleep(1000);
					dictionary.close();
					return false;
				}
				else
				{
					for (int i = 0; i < word.size(); i++) //goes through the letter of each word
					{
						for (int j = 0; j < this->letterPositions.size(); j++) //checks each member of the vector with the words currently on the board
						{
							if (this->letterPositions[j].x == x && this->letterPositions[j].y == y) //checks if position is the same
							{
								if (this->letterPositions[j].letter == word[i]) // if letter is the same it continues
								{
									continue;
								}
								else //otherwise word can't be put in the chosen location
								{
									cout << "At least one letter would overlap with another chosen word" << endl;
									Sleep(1000);
									dictionary.close();
									return false;
								}
							}
						}
						x++; //increments the position of x to move vertically
					}
					dictionary.close();
					if (positionIsValid(ix, iy, direction, word))
					{
						words.push_back(input); //appends word to vector
						convertToIndexes();
						return true;
					}
					else
					{
						cout << "Invalid position for the word due to adjacent words." << endl;
						Sleep(1000);
						return false;
					}
				}
			}
			else
			{
				if (y + word.size() > this->size2)
				{
					cout << "There isn't enough space to write the word here" << endl;
					Sleep(1000);
					dictionary.close();
					return false;
				}
				else
				{
					for (int i = 0; i < word.size(); i++)
					{
						for (int j = 0; j < this->letterPositions.size(); j++)
						{
							if (this->letterPositions[j].x == x && this->letterPositions[j].y == y)
							{
								if (this->letterPositions[j].letter == word[i])
								{
									continue;
								}
								else
								{
									cout << "At least one letter would overlap with another chosen word" << endl;
									Sleep(1000);
									dictionary.close();
									return false;
								}
							}
						}
						y++;
					}
					dictionary.close();
					if (positionIsValid(ix, iy, direction, word))
					{
						words.push_back(input); //appends word to vector
						convertToIndexes();
						return true;
					}
					else
					{
						cout << "Invalid position for the word due to adjacent words." << endl;
						Sleep(1000);
						return false;
					}
				}
			}
		}
		else //while word not found continue
			continue;
	}
	cout << "The word chosen is not in the dictionary" << endl;
	Sleep(1000);
	dictionary.close();
	return false; //if cicle finishes without finding the word it returns false
}

bool Board::positionIsValid(int x, int y, char direction, string word)
{


	string word1, wordf1, wordf2, wordf3, wordf4, c;
	ifstream dictionary;
	vector<letterCoordinats> letterPos;
	bool check{ false };

	if (direction == 'H')
	{
		for (int i = 0; i < word.size(); i++)
		{
			for (int j = 0; j < this->letterPositions.size(); j++)
			{
				if (this->letterPositions[j].x == x + 1 && this->letterPositions[j].y == y && i == word.size() - 1) //x+1 -> H
				{
					//cout << "check 1 H" << endl;

					letterPos = this->letterPositions;
					word1 = composeWordXp(x, y, letterPos);

					wordf1 = word1;
					//cout << wordf1 <<endl;

				}
				if (this->letterPositions[j].x == x - 1 && this->letterPositions[j].y == y && i == 0) //x-1 -> H
				{
					letterPos = this->letterPositions;
					word1 = composeWordXm(x, y, letterPos);
					//cout << "check 2 H" << endl;
					reverse(word1.begin(), word1.end());

					wordf2 = word1 + word;

					//cout << wordf2 <<endl;

				}
				if (this->letterPositions[j].y == y + 1 && this->letterPositions[j].x == x) //y + 1 -> H 
				{
					//cout << "check 3 H" << endl;

					letterPos = this->letterPositions;
					word1 = composeWordYp(x, y, letterPos);

					wordf3 = word1;

					//cout << wordf3 << endl;

				}
				if (this->letterPositions[j].y == y - 1 && this->letterPositions[j].x == x) //y - 1 -> H 
				{
					//cout << "check 4 H" << endl;
					letterPos = this->letterPositions;
					word1 = composeWordYm(x, y, letterPos);
					reverse(word1.begin(), word1.end());

					wordf4 = word1 + word[i];
					//cout << wordf4<< endl;

				}
			}
			x++;
		}
		wordf2 = wordf2 + wordf1;
		wordf4 = wordf4 + wordf3;

		//cout << wordf2 << endl;
		//cout << wordf4 << endl;

		dictionary.open("WORDS.TXT");
		if (wordf2.empty())
		{
			check = true;
		}
		else
		{
			while (dictionary >> c)
			{
				if (c == wordf2)
				{
					check = true;
					break;
				}
			}
		}
		if (check == false)
		{
			dictionary.close();
			return false;
		}

		if (wordf4.empty())
		{
			return true;
		}
		{
			while (dictionary >> c)
			{
				if (c == wordf4)
				{
					dictionary.close();
					return true;
				}
			}
		}
		dictionary.close();
		return false;

	}
	else
	{
		for (int i = 0; i < word.size(); i++)
		{
			for (int j = 0; j < this->letterPositions.size(); j++)
			{
				if (this->letterPositions[j].x == x + 1 && this->letterPositions[j].y == y) //x+1 -> H
				{
					//cout << "check 5 V" << endl;
					letterPos = this->letterPositions;
					word1 = composeWordXp(x, y, letterPos);

					wordf1 = word1;
					//cout << wordf1 << endl;

				}
				if (this->letterPositions[j].x == x - 1 && this->letterPositions[j].y == y) //x-1 -> H
				{
					//cout << "check 6 V" << endl;
					letterPos = this->letterPositions;
					word1 = composeWordXm(x, y, letterPos);
					reverse(word1.begin(), word1.end());

					wordf2 = word1 + word[i];
					//cout << wordf2 << endl;

				}
				if (this->letterPositions[j].y == y + 1 && this->letterPositions[j].x == x && i == word.size() - 1) //y + 1 -> H 
				{

					//cout << "check 7 V" << endl;
					letterPos = this->letterPositions;
					word1 = composeWordYp(x, y, letterPos);

					wordf3 = word1;
					//cout << wordf3 << endl;


				}
				if (this->letterPositions[j].y == y - 1 && this->letterPositions[j].x == x && i == 0) //y - 1 -> H 
				{
					//cout << "check 8 V" << endl;
					letterPos = this->letterPositions;
					word1 = composeWordYm(x, y, letterPos);

					reverse(word1.begin(), word1.end());
					wordf4 = word1 + word;
					//cout<< wordf4 << endl;

				}
			}
			y++;
		}
		wordf2 = wordf2 + wordf1;
		wordf4 = wordf4 + wordf3;

		//cout << wordf2 << "--------" << endl;
		//cout << wordf4  << endl;

		dictionary.open("WORDS.TXT");

		if (wordf2.empty())
		{
			check = true;
		}
		else
		{
			while (dictionary >> c)
			{
				if (c == wordf2)
				{
					check = true;
					break;
				}
			}
		}

		if (check == false)
		{
			dictionary.close();
			return false;
		}

		if (wordf4.empty())
		{
			return true;
		}
		{
			while (dictionary >> c)
			{
				if (c == wordf4)
				{
					dictionary.close();
					return true;
				}
			}
		}
		dictionary.close();
		return false;
	}
}

bool  Board::remove(string input)
{
	for (int i = 0; i < this->words.size(); i++)
	{
		if (words[i] == input)
		{
			words.erase(words.begin() + i);
			convertToIndexes();
			return true;
		}
	}
	return false;
}

void Board::print()
{

	string AlphabeT = "ABCDEFGHIJKLMNOPQRST", fileName, option;

	show(AlphabeT);

	while (true)
	{
		cout << "\n\n Please name your board (Do NOT choose the name 'WORDS' since it will replace the main folder of the dictionary): " << endl;;
		cin >> fileName;

		if (fileName == "WORDS")
		{
			cout << "Do NOT choose the name WORDS!";
			Sleep(1000);
			continue;
		}
		else if (fileName == "BOARD")
		{
			cout << "This action will overwrite the default board. Do you wish to continue? " << endl;
			while (option != "no" && option != "yes")
			{
				cin >> option;

				if (option == "no")
				{
					continue;
				}
				if (option == "yes")
				{
					break;
				}
			}
		}
		else
			break;
	}

	ofstream boardf;
	boardf.open(fileName + ".txt");

	boardf << size1 << " x " << size2 << endl;

	composeFinal();

	for (int i = 0; i < this->words.size(); i++)
	{
		boardf << words[i] << endl;
		//cout << words[i];
	}

	boardf << endl << endl << "BOARD_PREVIEW:" << endl << " ";


	for (int y = 0; y <= this->size2; y++)
	{
		for (int x = 0; x <= this->size1; x++)
		{

			if (y == 0 && x != size1)
				boardf << "| " << (char)tolower(AlphabeT[x]);
			else if (x == 0)
				boardf << AlphabeT[y - 1] << "| ";
			else
				boardf << indexLetter(x, y) << "  ";
			if (x == size1)
				boardf << endl;

		}
	}

}

void Board::composeFinal()
{
	char let;
	string temp = "", f = "";
	int xi, yi;
	char ycha;
	this->words.clear();

	//cout << temp;
	for (int x = 0; x < this->size1; x++)    //verticais
	{
		temp = "";
		//cout << x << "Vx" << endl;
		for (int y = 0; y < this->size2; y++)
		{
			//cout << y << "Vy" << endl;
			for (int i = 0; i < this->letterPositions.size(); i++)
			{
				//cout << letterPositions[i].x << " " << letterPositions[i].y << " " << letterPositions[i].letter <<endl;
				if (this->letterPositions[i].x == x && this->letterPositions[i].y == y)
				{
					if (temp == "")
					{
						xi = x;
						yi = y;
					}
					temp += letterPositions[i].letter;
					break;
				}
				else if (i == this->letterPositions.size() - 1)
				{
					if (temp == "" || temp.size() == 1)
					{
						temp = "";
						break;
					}
					else
					{
						f = lettersup[yi] + letters[xi] + " V " + temp;
						//cout << temp << "1" << endl;
						words.push_back(f);
						//cout << f;
						temp = "";
						break;
					}
				}
			}
		}
	}



	for (int y = 0; y < this->size2; y++)    //horizontals
	{
		temp = "";
		//cout << y << "Hy" << endl;
		for (int x = 0; x < this->size1; x++)
		{
			//cout << x << "Hx" << endl;
			for (int i = 0; i < this->letterPositions.size(); i++)
			{
				//cout << letterPositions[i].x << " " << letterPositions[i].y << " " << letterPositions[i].letter << endl;
				if (this->letterPositions[i].x == x && this->letterPositions[i].y == y)
				{
					if (temp == "")
					{
						xi = x;
						yi = y;
					}
					temp += letterPositions[i].letter;
					break;
				}
				else if (i == this->letterPositions.size() - 1)
				{
					if (temp == "" || temp.size() == 1)
					{
						temp = "";
						break;
					}
					else
					{
						//cout << letters[yi] << " " << letters[xi] << " H " << temp << endl;
						f = lettersup[yi] + letters[xi] + " H " + temp;
						//cout << f << endl;
						words.push_back(f);
						temp = "";
						break;
					}
				}
			}

		}
	}
}