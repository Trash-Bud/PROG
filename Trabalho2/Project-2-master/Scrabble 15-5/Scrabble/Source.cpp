#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <Windows.h>

#include "Board.h"
#include "Person.h"
#include "Pool.h"

using namespace std;

//CONSTANTS ------------------------------------------------------------------
const int MAXEXCHANGPIECES = 2, MAXRECIEVINGPIECES = 2, MAXHANDNUM = 7;
string Alphabet = "ABCDEFGHIJKLMNOPQRST", AlphabeT = "abcdefghijklmnopqrst";
//CONSTANTS ------------------------------------------------------------------

/*
	Perguntar o numero de jogadores
	(Indique o nome do jogodar 1:...)
	(Indique o nome do jogodar 2:...)
	...

	Perguntar o nome do board
	Criar o board a partir do txt
	Criar a pool de letras
	Distribuir as letras pelos jogadores
	
	-Detertar se há jogadas possíveis
		Se não:
			Pede ao jogador para escolher duas letras para discartar
			Substitui por duas letra aleatórias da pool
			Se não tiver passar
		Se sim:
			Jogador escolha 1.
			-Deteta se é possivel jogar uma segunda
				Se sim:
					obrigrar a jogar uma segunda
					Adicionar 2 da pool
				Se não:
					Adicionar 1 da pool

	-Detetar se foi completa 1 palavra
			(1 ponto por palavra completa)
	-Continuar para o jogador seguinte...

	-Winning Condition: Quando as palavras estiverem todas completas
	
*/


bool descending(int x, int y)
{
	if (x < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------------

void bubbleSort(vector<Person>& v, bool f(int x, int y))                    
																		   
{
	int count = 0;
	for (int e = 0; e < v.size() - 1; e++)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (f(v[i].showpoints(), v[i + 1].showpoints()))
			{
				Person low = v[i + 1];
				Person high = v[i];
				v[i] = low;
				v[i + 1] = high;
				count++;
			}
		}
	}
}

//--------------------------------------------------------------------------

bool verifyInput(string input, Board board1, Person p1)      //Verifies the input string(checks if it does not give the necessary information)
{

	if (Alphabet.substr(0, board1.showsize2()).find(input[0]) == string::npos)
	{
		cout << "Invalid vertical character! Please insert a character that represents a place in the board!" << endl;
		return false;
	}
	if (AlphabeT.substr(0, board1.showsize1()).find(input[1]) == string::npos)
	{
		cout << "Invalid horizontal character! Please insert a character that represents a place in the board!" << endl;
		return false;
	}
	char lette = input[3];
	if (!p1.isInHand(lette))
		{
			cout << "The piece choosen has to be in your hand!" << endl;
			return false;
		}
}

//--------------------------------------------------------------------------

string validateBoard()   //checks if the chosen file exists and if so if it has at least 14 letters
{
	ifstream test; // for testing if the file choosen exists
	string filename; //name of the chosen file

	while (true)
	{
		cin >> filename;
		test.open(filename + ".txt");

		if (!test)
		{
			cout << "There is no file with that name. Please retry!\n\n";
		}
		else
		{
			test.close();

			Board board1(filename); //creates a test board if the file choosen exists
			Pool pool(board1.exportList()); //creates a test pool

			if (pool.showNumber() >= 14) //stops the creation of boards with not enough pieces
			{
				return filename;
			}
		}
	}
}

//--------------------------------------------------------------------------

void verifyPlayerNum(int& numPlayers, Pool pool)   //Checks if it is possible to play with the chosen board with the selected amount of players(ex: 4 players and the pool has 15 pieces -> Impossible )
{
	const int MAXHANDNUM = 7;
	cout << endl << "How many players?" << endl;
	cin >> numPlayers;
	while (true)
	{
		if (pool.showNumber() < 14)
		{
			cout << "The board chosen doesn't have enough pieces to allow 2 players to play, therefore it is invalid!" << endl;
		}
		else if (MAXHANDNUM * numPlayers > pool.showNumber()) //the number of players has to be so that each player can have 7 pieces in hand at the biggining of their turn
		{
			cout << "The board chosen doesn't have enough words to allow " << numPlayers << " players! Please choose a smaller number!" << endl;

		}
		else if (numPlayers < 2 || numPlayers > 4) //num of players has to be between 2 and 4
		{
			cout << "The minimum ammount of players is 2 and the maximum is four. Please retry!" << endl;
		}
		else
			break;
	}
}

//--------------------------------------------------------------------------

void definePlayerNames(Person& p1, Person& p2, Person& p3, Person& p4, Pool& pool, int numPlayers)  //Defines the names of the players and creates their hands
{
	string input; //players names
	const int MAXHANDNUM = 7;

	for (int i = 0; i < numPlayers; i++)  //numPlayers makes sure that we only name the players that will be playing
	{
		cout << "Insert the name of the Player: ";
		cin >> input;

		if (p1.showorder() - 1 == i)
		{
			p1.defineName(input);
			for (int e = 0; e < MAXHANDNUM; e++)
			{
				p1.includeinHand(pool.givePiece());
			}
		}
		if (p2.showorder() - 1 == i)
		{
			p2.defineName(input);
			for (int e = 0; e < MAXHANDNUM; e++)
			{
				p2.includeinHand(pool.givePiece());
			}
		}
		if (p3.showorder() - 1 == i)
		{
			p3.defineName(input);
			for (int e = 0; e < MAXHANDNUM; e++)
			{
				p3.includeinHand(pool.givePiece());
			}
		}
		if (p4.showorder() - 1 == i)
		{
			p4.defineName(input);
			for (int e = 0; e < MAXHANDNUM; e++)
			{
				p4.includeinHand(pool.givePiece());
			}
		}
	}
	cin.ignore();
}

//--------------------------------------------------------------------------

void handIsEmpty(int& counter)     //Detects if the players hand is empty and doesnt allow him to play
{
	cout << "Your hand is empty threfore you were skipped!" << endl;
	Sleep(1000);
	counter++; //increases to go to the next player
}

//--------------------------------------------------------------------------

void playedOnce(int& counter, Person& p1, Pool& pool, Board& board1, bool& playedonce, int points)    //2º move of the player in the same round
{

	string played;
	cout << "Choose a piece to play in the following format 'Yx letter'" << endl;
	getline(cin, played);

	if (!verifyInput(played, board1, p1))
	{
		Sleep(1000);
		return;
	}
	if (board1.played(played, points, playedonce))
	{
		counter++; // increases to the next player
		cout << "You made a valid move!" << endl;
		Sleep(1000);

		p1.addPoints(points);
		p1.removePlayed(played);

		for (int i = 0; i < MAXRECIEVINGPIECES; i++)
		{
			if (pool.showNumber() == 0)
			{
				cout << "The Pool is empty therefore no pieces could be exhanged!" << endl;
				Sleep(1000);
				break;
			}
			else
				p1.includeinHand(pool.givePiece());
		}

		points = 0; //points is a variable that stores the points won in one given round
		playedonce = false;
		return;
	}
	else
	{
		cout << "The move you made is invalid! Please retry!" << endl;
		Sleep(1000);
		return;
	}
}

//--------------------------------------------------------------------------

void hasNoMoves(int& counter, Person& p1, Pool& pool, bool& playedonce)   //The player has no possible moves so he refills from the pool
{
	char piece;
	string played;

	cout << "You have no valid moves!" << endl;
	for (int i = 0; i < MAXEXCHANGPIECES; i++) //asks for a piece to exhange in the pool twice
	{
		if (pool.showNumber() == 0) //if the pool is empty passes
		{
			cout << "The Pool is empty therefore no pieces could be exhanged!" << endl;
			Sleep(1000);
			return;
		}

		cout << "Choose a piece to exchange" << endl;
		cin >> piece;

		if (sizeof(piece) > 1)
		{
			cout << "Invalid input! Please retry!" << endl;
			Sleep(1000);
			return;
		}
		else if (!p1.isInHand(piece))
		{
			cout << "You must exchange a piece from your hand!" << endl;
			Sleep(1000);
			return;
		}
		else
		{
			p1.removeFromHand(piece);
			p1.includeinHand(pool.givePiece());
			pool.addToPool(piece);
		}
	}
	counter++;
	return;
}

//--------------------------------------------------------------------------

void hasOneMove(int& counter, Person& p1, Pool& pool, Board& board1, bool& playedonce, int points, string played)    //If the player can only place one piece on the board
{
	if (board1.played(played, points, playedonce))
	{

		counter++;
		cout << "You made a valid move!" << endl;
		Sleep(1000);

		p1.addPoints(points);
		p1.removePlayed(played);

		if (pool.showNumber() == 0)
		{
			cout << "The Pool is empty therefore no pieces could be exhanged!" << endl;
		}
		else
			p1.includeinHand(pool.givePiece());

		points = 0;

		return;
	}
	else
	{

		cout << "The move you made is invalid! Please retry!" << endl;
		Sleep(1000);
		return;
	}
}

//--------------------------------------------------------------------------

void hasTwoMoves(int& counter, Person& p1, Pool& pool, Board& board1,bool& playedonce, int points, string played)   //For the 1º move of 2 possible moves
{
	//counter isn't increased since the next move is made by the same player	
	if (board1.played(played, points, playedonce))
	{

		cout << "You made a valid move!" << endl;
		Sleep(1000);

		p1.addPoints(points);
		p1.removePlayed(played);

		points = 0;
		playedonce = true;
		return;
	}
	else
	{
		cout << "The move you made is invalid! Please retry!" << endl;
		Sleep(1000);
		return;
	}
}

//--------------------------------------------------------------------------

void roundG(int& counter, Person& p1, Pool& pool, Board& board1, bool& playedonce)      //Represents one round of the game
{
	int points{ 0 };  //points - counts the points won with a single move
	string played;

	if (p1.showHandSize() == 0) //If the player's hand doesn't have any more chips then the pool doesn't have any either so the move is skipped
	{
		handIsEmpty(counter);
		return;
	}
	if (playedonce)     //If it's already the second move       (Playedonce is a flag to detect how many times he can play)
	{
		playedOnce(counter, p1, pool, board1, playedonce, points);
		return;
	}
	else if (board1.hasMoves(p1.showhand()) == 0)  // If they cant play any letter they have
	{
		hasNoMoves(counter, p1, pool, playedonce);
		return;
	}
	else //if they can play only once or if he can play twice
	{
		cout << "Choose a piece to play in the following format 'Yx letter'" << endl;

		getline(cin, played);

		if (!verifyInput(played, board1, p1))
		{
			Sleep(1000);
			return;
		}

		if (board1.hasMoves(p1.showhand()) == 1)        //If the player can only play once in his round
		{
			hasOneMove(counter, p1, pool, board1, playedonce, points, played);
			return;
		}
		else if (board1.hasMoves(p1.showhand()) == 2)    //If he is able to play twice (the first time)
		{
			hasTwoMoves(counter, p1, pool, board1, playedonce, points, played);
			return;
		}
	}
}

//--------------------------------------------------------------------------

void winning(Person p1, Person p2, Person p3, Person p4, int numPlayers)    //wining conditions and print of the winning message
{
	vector<Person> pointOrder = { p1, p2, p3, p4 };

	bubbleSort(pointOrder, descending);

	if (numPlayers == 2)
	{
		if (pointOrder[0].showpoints() == pointOrder[1].showpoints())
		{
			cout << "The game ended in a draw with both players finishing with " << pointOrder[0].showpoints() << " points!" << endl;
		}
		else
			cout << pointOrder[0].showname() << " is the winner with " << pointOrder[0].showpoints() << " points!" << endl;
	}
	else if (numPlayers == 3)
	{
		if (pointOrder[0].showpoints() == pointOrder[1].showpoints() && pointOrder[0].showpoints() == pointOrder[2].showpoints())
		{
			cout << "The game ended in a draw with all players finishing with " << pointOrder[0].showpoints() << " points!" << endl;
		}
		else if (pointOrder[0].showpoints() == pointOrder[1].showpoints() && pointOrder[0].showpoints() != pointOrder[2].showpoints())
		{
			cout << "The game ended in a draw with players" << pointOrder[0].showname() << " and " << pointOrder[1].showname() << "finishing with " << pointOrder[0].showpoints() << " points!" << endl;
		}
		else
		{
			cout << pointOrder[0].showname() << " is the winner with " << pointOrder[0].showpoints() << " points!" << endl;

			if (pointOrder[2].showpoints() == pointOrder[1].showpoints())
			{
				cout << "The ramaing two players ended up in a draw for second place with " << pointOrder[2].showpoints() << " points each!" << endl;
			}
			else
				cout << pointOrder[1].showname() << " got second place " << pointOrder[1].showpoints() << " points!" << endl;
		}
	}
	else
	{
		if (pointOrder[0].showpoints() == pointOrder[1].showpoints() && pointOrder[0].showpoints() == pointOrder[2].showpoints() && pointOrder[0].showpoints() == pointOrder[3].showpoints())
		{
			cout << "The game ended in a draw with all players finishing with " << pointOrder[0].showpoints() << " points!" << endl;
		}
		else if (pointOrder[0].showpoints() == pointOrder[1].showpoints() && pointOrder[0].showpoints() == pointOrder[2].showpoints() && pointOrder[0].showpoints() != pointOrder[3].showpoints())
		{
			cout << "The game ended in a draw with players " << pointOrder[0].showname() << " and " << pointOrder[1].showname() << "finishing with " << pointOrder[0].showpoints() << " points!" << endl;
			if (pointOrder[2].showpoints() == pointOrder[3].showpoints())
			{
				cout << "The ramaing two players ended up in a draw for second place with " << pointOrder[2].showpoints() << " points each!" << endl;
			}
			else
			{
				cout << pointOrder[2].showname() << " got second place " << pointOrder[2].showpoints() << " points!" << endl;
			}
		}
		else
		{
			cout << pointOrder[0].showname() << " is the winner with " << pointOrder[0].showpoints() << " points!" << endl;

			if (pointOrder[2].showpoints() == pointOrder[1].showpoints() && pointOrder[1].showpoints() == pointOrder[3].showpoints())
			{
				cout << "The ramaing three players ended up in a draw for second place with " << pointOrder[2].showpoints() << " points each!" << endl;
			}
			else if (pointOrder[2].showpoints() == pointOrder[1].showpoints() && pointOrder[1].showpoints() != pointOrder[3].showpoints())
			{
				cout << "Players " << pointOrder[1].showname() << " and " << pointOrder[2].showname() << "ended up in a draw for second place with " << pointOrder[1].showpoints() << " points!" << endl;
			}
			else
			{
				cout << pointOrder[1].showname() << " got second place " << pointOrder[1].showpoints() << " points!" << endl;

				if (pointOrder[2].showpoints() == pointOrder[3].showpoints())
				{
					cout << "The ramaing two players ended up in a draw for third place with " << pointOrder[2].showpoints() << " points each!" << endl;
				}
				else
				{
					cout << pointOrder[2].showname() << " got third place " << pointOrder[2].showpoints() << " points!" << endl;
				}
			}
		}
	}
}

//--------------------------------------------------------------------------


int main() {

	//game-------
	Person p1(1), p2(2), p3(3), p4(4); //inicialization of 4 default players
	int numPlayers, counter{ 0 }; //counter -> round counter
	bool playedonce = false; //flag to know if the player is playing for the second time in the same round
	//----------

	cout << "Please insert the name of the file that contains the board! If you haven't created a custom one, choose 'BOARD' to use the default one." << endl;

	Board board1(validateBoard());
	Pool pool(board1.exportList());
	
	verifyPlayerNum(numPlayers,pool); //veryfies if the number of players is valid

	definePlayerNames(p1, p2, p3, p4, pool, numPlayers); //defines player names

	// GAME ----------
	while (p1.showHandSize() != 0 || p2.showHandSize() != 0 || p3.showHandSize() != 0 || p4.showHandSize() != 0) //End condition (no more pieces in the hands mean that there are no pieces in the pool either)
	{
		board1.show(Alphabet, counter, numPlayers, p1.showpoints(), p2.showpoints(), p3.showpoints(), p4.showpoints(), p1.showhand(), p2.showhand(), p3.showhand(), p4.showhand(), p1.showname(), p2.showname(), p3.showname(), p4.showname(), pool.showNumber());
		//board1.showNM();

		if (counter % numPlayers == 0)   //-> P1 ---------------
		{
			roundG(counter, p1, pool, board1, playedonce);
		}
		else if (counter % numPlayers == 1)   //-> P2
		{
			roundG(counter, p2, pool, board1, playedonce);
		}
		else if (counter % numPlayers == 2)   //-> P3
		{
			roundG(counter, p3, pool, board1, playedonce);
		}
		else if (counter % numPlayers == 3)   //-> P4
		{
			roundG(counter, p4, pool, board1, playedonce);
		}
	}
	//----------------

	board1.show(Alphabet, counter, numPlayers, p1.showpoints(), p2.showpoints(), p3.showpoints(), p4.showpoints(), p1.showhand(), p2.showhand(), p3.showhand(), p4.showhand(), p1.showname(), p2.showname(), p3.showname(), p4.showname(), pool.showNumber());

	// Winning Message

	winning(p1, p2, p3, p4, numPlayers);

return 0;
}