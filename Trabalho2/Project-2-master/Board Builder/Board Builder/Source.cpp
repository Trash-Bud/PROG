#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>

#include "board.h"
using namespace std;

/* cin << tamanho1 << tamanho2
Defenir o tamanho
Print tabuleiro
cin << palavra Pedir para escolher palavras (condição para parar)  --> "Hh O palavra"
Split pelos espaços
Verificar de a palavra está no dicionário
Verificar se a primeira letra pode ir para a primeira casa
Verificar se na orientação escolhida há espaços suficientes
Verificar se todas as letras podem ser inseridas
"Monstrar o tabuleiro"
cin >> "Edit"
indicar a palavra --> "palavra"
cout >> "move or remove"
move --> "Hh O"

Verificar se a primeira letra pode ir para a primeira casa
Verificar se na orientação escolhida há espaços suficientes
Verificar se todas as letras podem ser inseridas

"Montrar tabuleiro"

...

criar o ficheiro (Dar a opção ao jogador de dar um nome ao ficheiro --> impedir de escolher 'BOARD' e 'WORDS') */

int main()
{
	//constants
	string AlphabeT = "ABCDEFGHIJKLMNOPQRST";
	string Alphabet = "abcdefghijklmnopqrst";
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

	//board
	Board board1;

	//inputs
	int size1, size2;
	string input;
	

	cout << "Define the size of the board!" << endl<<endl;

	while (true)
	{
		cout << "Horizontal: ";
		cin >> size1;
		if (cin.fail())
		{
			cout << "Only numbers please"<<endl<<endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		cout << "Vertical: ";
		cin >> size2;

		if(cin.fail())
		{
			cout << "Only numbers please" << endl<<endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (size1 < 10 || size1 > 20 || size2 < 10 || size2 > 20)
		{
			cout << endl << "Invalid board size! Please select one between 10x10 and 20x20!" << endl << endl;
		}
		else
			break;
	}

	cin.ignore(1000, '\n');

	board1.setSize(size1, size2);
	board1.show(AlphabeT);

	cin.clear();
	while (input != "stop")
	{
		board1.show(AlphabeT);

		cout << endl<< "- To insert a word type the coordinates, orientation and word in the following manner 'Yx H/V word'" << endl;
		cout << "- To remove one of the already created words type 'remove'" << endl;
		cout << "- Once the board is finished type 'stop' to save it" << endl << endl;

		while (true)
		{

			getline(cin, input);

			if (input == "stop")
			{
				break;
			}
			if (input == "remove")
			{
				while (true)
				{
					cout << endl << "Insert the word you want to remove in the following manner 'Yx V/H word'" << endl;
					cout << "Once you're done type 'exit'" << endl;

					getline(cin, input);

					if (input == "exit")
					{
						break;
					}
					if (AlphabeT.substr(0, size2).find(input[0]) == string::npos) {
						cout << "Invalid vertical character! Please insert a character that represents a place in the board!" << endl;
						continue;
					}
					if (Alphabet.substr(0, size1).find(input[1]) == string::npos) {
						cout << "Invalid horizontal character! Please insert a character that represents a place in the board!" << endl;
						continue;
					}
					if (input[3] != 'H' && input[3] != 'V') {
						cout << "Invalid orientation! Please insert 'H' for horizontal or 'V' for vertical!" << endl;
						continue;
					}

					if (board1.remove(input, index))
					{
						Sleep(500);

						cout << "Word removed successfully!" << endl;
						board1.show(AlphabeT);
					}
					else
					{
						cout << "Word is not in the board or was otherwise not properly located!" << endl;
						board1.show(AlphabeT);
					}

				}
				break;
			}
			
			board1.show(AlphabeT);

			if (AlphabeT.substr(0, size2).find(input[0]) == string::npos) {
				cout << "Invalid vertical character! Please insert a character that represents a place in the board!" << endl;
				continue;
			}
			if (Alphabet.substr(0, size1).find(input[1]) == string::npos) {
				cout << "Invalid horizontal character! Please insert a character that represents a place in the board!" << endl;
				continue;
			}
			if (input[3] != 'H' && input[3] != 'V') {
				cout << "Invalid orientation! Please insert 'H' for horizontal or 'V' for vertical!" << endl;
				continue;
			}
			if (!board1.isValid(input, index))
			{
				continue;
			}
			else
			{
				cout <<endl << "The word was added to the board" << endl;
				Sleep(1000);
				board1.show(AlphabeT);

				//cout << endl;
				//for (int i = 0; i < board1.showlpsize(); i++)
				//{
				//	cout << "x = "<< board1.showlpx(i) << endl;                           //checks the size and cotent of letter_Position
				//	cout << "y = " << board1.showlpy(i) << endl;
				//	cout << "letter = " << board1.showlplt(i) << endl;                     // Não deixa escrever rock na vertical e o não esta a escrever
				//}

				break;
			}
		}
	}

	board1.print();

	return 0;
}


