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



int main() {
	string filename;
	ifstream test;
	string Alphabet = "ABCDEFGHIJKLMNOPQRST", played;
	Person p1(1), p2(2), p3(3), p4(4);
	int numPlayers, counter{ 0 }, points{ 0 };
	string input;
	vector <char> chars;
	char piece;
	bool playedonce = false;


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

	cout << "Please insert the name of the file that contains the board information! If you haven't created a custom one, choose BOARD to use the default one." << endl;

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
			break;
		}
	}

	Board board1(filename);
	chars = board1.exportList();
	Pool pool(chars);

	board1.show(Alphabet);

	cout << endl <<"How many players?" << endl;
	cin >> numPlayers;

	for(int i=0; i<numPlayers; i++)
	{
		cout << "Insert the name of the Player: ";
		cin >> input;

		if (p1.showorder() - 1 == i)
		{
			p1.defineName(input);
			for (int e = 0; e < 7; e++)
			{
				piece = pool.givePiece();
				p1.includeinHand(piece);
			}
		}
		if (p2.showorder() - 1 == i)
		{
			p2.defineName(input);
			for (int e = 0; e < 7; e++)
			{
				piece = pool.givePiece();
				p2.includeinHand(piece);
			}
		}
		if (p3.showorder() - 1 == i)
		{
			p3.defineName(input);
			for (int e = 0; e < 7; e++)
			{
				piece = pool.givePiece();
				p3.includeinHand(piece);
			}
		}
		if (p4.showorder() - 1 == i)
		{
			p4.defineName(input);
			for (int e = 0; e < 7; e++)
			{
				piece = pool.givePiece();
				p4.includeinHand(piece);
			}
		}
	}

	while (p1.showHandSize() != 0 || p2.showHandSize() != 0 || p3.showHandSize() != 0 || p4.showHandSize() != 0)
	{
		
		if (counter % numPlayers == 0)   //-> P1
		{
			if (p1.showHandSize() == 0)
			{
				cout << " The player's hand is empty, therefore they were skipped." << endl;
				Sleep(1000);
				counter++;
				continue;
			}
			else if (board1.hasMoves(p1.showhand()) == 0)
			{
				cout << "There are no valid moves! Choose two pieces to exchange in the Pool." << endl;
				for (int i = 0; i < 2; i++)
				{
					cin >> piece;
					//verificar se o input é válido
					p1.removeFromHand(piece);
					p1.includeinHand(pool.givePiece());
					pool.addToPool(piece);
					
				}
				counter++;
				continue;
			}
			else
			{
				cout << " Choose a piece to play in the following format 'Yx_letter'." << endl;
				p1.printhand();
				cin >> played;
				//verificar se o input é válido
				if(board1.hasMoves(p1.showhand()) == 1)
				{
					if (board1.played(played, points, playedonce))
					{
						
						counter++;
						cout << "It was a valid play" << endl;
						p1.addPoints(points);
						p1.removePlayed(played);
						p1.includeinHand(pool.givePiece());
						points = 0;
						board1.show(Alphabet);
						continue;
					}
					else
					{
						
						cout << "It was not a valid play." << endl;
						continue;						
					}
				}
				else if (board1.hasMoves(p1.showhand()) == 2)
				{
					
					if (!playedonce)
					{
						
						if (board1.played(played, points, playedonce))
						{

							cout << "It was a valid play" << endl;
							p1.addPoints(points);
							p1.removePlayed(played);
							
							points = 0;
							playedonce = true;
							continue;
						}
						else
						{
							cout << "It was not a valid play." << endl;
							continue;
						}
					}
					else
					{
						if (board1.played(played, points, playedonce))
						{
							counter++;
							cout << "It was a valid play" << endl;
							p1.addPoints(points);
							p1.removePlayed(played);
							p1.includeinHand(pool.givePiece());
							p1.includeinHand(pool.givePiece());
							points = 0;
							board1.show(Alphabet);
							playedonce = false;
							continue;
							
						}
						else
						{
							cout << "It was not a valid play." << endl;
							continue;
						}
					}

				}
			}


		}
		if (counter % numPlayers == 1)   //-> P2
		{
			
			if (p2.showHandSize() == 0)
			{
				cout << " The player's hand is empty, therefore they were skipped." << endl;
				Sleep(1000);
				counter++;
				continue;
			}
			else if (board1.hasMoves(p2.showhand()) == 0)
			{
				cout << "There are no valid moves! Choose two pieces to exchange in the Pool." << endl;
				for (int i = 0; i < 2; i++)
				{
					cin >> piece;
					//verificar se o input é válido
					p2.removeFromHand(piece);
					p2.includeinHand(pool.givePiece());
					pool.addToPool(piece);

				}
				counter++;
				continue;
			}
			else
			{
				
				cout << " Choose a piece to play in the following format 'Yx_letter'." << endl;
				p2.printhand();
				cin >> played;
				//verificar se o input é válido
				if (board1.hasMoves(p2.showhand()) == 1)
				{
					if (board1.played(played, points, playedonce))
					{

						counter++;
						cout << "It was a valid play" << endl;
						p2.addPoints(points);
						p2.removePlayed(played);
						p2.includeinHand(pool.givePiece());
						points = 0;
						board1.show(Alphabet);
						continue;
						
					}
					else
					{

						cout << "It was not a valid play." << endl;
						continue;
					}
				}
				else if (board1.hasMoves(p2.showhand()) == 2)
				{

					if (!playedonce)
					{
						
						if (board1.played(played, points, playedonce))
						{

							cout << "It was a valid play" << endl;
							p2.addPoints(points);
							p2.removePlayed(played);

							points = 0;
							playedonce = true;
							continue;
						}
						else
						{
							cout << "It was not a valid play." << endl;
							continue;
						}
					}
					else
					{
						//corrigir o 2;
						if (board1.played(played, points, playedonce))
						{
							counter++;
							cout << "It was a valid play" << endl;
							p2.addPoints(points);
							p2.removePlayed(played);
							p2.includeinHand(pool.givePiece());
							p2.includeinHand(pool.givePiece());
							points = 0;
							board1.show(Alphabet);
							playedonce = false;
							continue;
							
						}
						else
						{
							cout << "It was not a valid play." << endl;
							continue;
						}
					}

				}
			}


		}
		if (counter % numPlayers == 2)   //-> P3
		{
			if (p3.showHandSize() == 0)
			{
				cout << " The player's hand is empty, therefore they were skipped." << endl;
				Sleep(1000);
				counter++;
				continue;
			}
		}
		if (counter % numPlayers == 3)   //-> P4
		{
			if (p4.showHandSize() == 0)
			{
				cout << " The player's hand is empty, therefore they were skipped." << endl;
				Sleep(1000);
				counter++;
				continue;
			}
		}
		
		;
	}



	return 0;
}