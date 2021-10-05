#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h> 
#include <ctime>

using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void setcolor(unsigned int color)
{
	if (color == 0 || (color > 12 && color <= 15))
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, color);
	}
	else if (color == 80)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 9);
	}
	else if (color == 81)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 12);
	}
	else if (color == 70)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 1);
	}
	else if (color == 71)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 4);
	}
	else if (color % 12 == 5)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 13);
	}
	else if (color % 12 == 1)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 14);
	}
	else if (color % 12 == 4)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 15);
	}
	else if (color % 12 == 9)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 11);
	}
	else if (color % 12 == 0)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, 13);
	}
	else
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, color % 12);
	}
}

void forced_end(int p1, int p2, int game_type) //sees who has more points if the game can't be played any longer
{
	if (p1 > p2)
	{
		cout << "The winner is player 1 with " << p1 << " points!";
	}
	else if (p1 < p2)
	{
		if (game_type == 1)
			cout << "The winner is player 2 with " << p2 << " points!";
		else
			cout << "The winner is the bot with " << p2 << " points!";
	}
	else
		cout << "The game ended in a draw with each player having " << p2 << " points!";
}

void board(int player,int a[], int p1, int p2,int print_type) //Calls the board
{
	if (print_type == 1)
		system("cls");

	if (player == 1) //board for player 1
	{
		setcolor(14);
		cout << "------------------------------------------------------------------------------------------------" << endl;

		setcolor(70);
		cout << "Player 2";

		setcolor(7);
		cout << " - Score: " << p2 << endl << endl;

		setcolor(80);
		cout << "f     e     d     c     b     a" << endl;

		setcolor(a[11]);
		cout << a[11];

		setcolor(a[10]);
		cout << setw(6) << a[10];

		setcolor(a[9]);
		cout << setw(6) << a[9];

		setcolor(a[8]);
		cout << setw(6) << a[8];

		setcolor(a[7]);
		cout << setw(6) << a[7];

		setcolor(a[6]);
		cout << setw(6) << a[6];

		cout<< endl << endl;

		setcolor(a[0]);
		cout << a[0];

		setcolor(a[1]);
		cout << setw(6) << a[1];

		setcolor(a[2]);
		cout << setw(6) << a[2];

		setcolor(a[3]);
		cout << setw(6) << a[3];

		setcolor(a[4]);
		cout << setw(6) << a[4];

		setcolor(a[5]);
		cout << setw(6) << a[5];

		cout<< endl;

		setcolor(81);
		cout << "A     B     C     D     E     F" << endl << endl;

		setcolor(71);
		cout << "Player 1";

		setcolor(7);

		cout << " - Score: " << p1;
		setcolor(14);

		cout << " - Currently Choosing" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
	}
	else if (player == 2|| player == 3) //board for player 2 and bot
	{
		setcolor(14);
		cout << "------------------------------------------------------------------------------------------------" << endl;

		setcolor(71);
		cout << "Player 1 ";

		setcolor(7);
		cout <<"- Score: " << p1 << endl << endl;

		setcolor(81);
		cout << "F     E     D     C     B     A" << endl;

		setcolor(a[5]);
		cout << a[5];

		setcolor(a[4]);
		cout << setw(6) << a[4];

		setcolor(a[3]);
		cout << setw(6) << a[3];

		setcolor(a[2]);
		cout << setw(6) << a[2];

		setcolor(a[1]);
		cout << setw(6) << a[1];

		setcolor(a[0]);
		cout << setw(6) << a[0];

		cout << endl << endl;

		setcolor(a[6]);
		cout << a[6];

		setcolor(a[7]);
		cout << setw(6) << a[7];

		setcolor(a[8]);
		cout << setw(6) << a[8];

		setcolor(a[9]);
		cout << setw(6) << a[9];

		setcolor(a[10]);
		cout << setw(6) << a[10];

		setcolor(a[11]);
		cout << setw(6) << a[11];

		cout << endl;

		setcolor(80);
		cout << "a     b     c     d     e     f" << endl << endl;

		setcolor(70);
		cout << "Player 2 ";

		setcolor(7);
		cout << " - Score: " << p2 << " - Currently Choosing" << endl;

		setcolor(14);
		cout << "------------------------------------------------------------------------------------------------" << endl;
	}

}

bool starve(int b[], int player, int choice) //checks if the opponent is going to be starved
{
	//same process as sowing and capturing but a new array is created to prevent updating the current array from bein altered

	int a[12];
	int current, hand;

	for (int i = 0; i < 12; i++)
	{
		a[i] = b[i];
	}

	hand = a[choice];
	current = choice;
	a[choice] = 0;

	for (int i = hand; i != 0; i--)
	{
		current = current % 12;
		if (current == choice)
		{
			i++;
			current++;
		}
		else if (a[current] >= 12)
		{
			i++;
			current++;
		}
		else
		{
			a[current]++;
			current++;
		}
	}
	current = current - 1;

	if (player == 1)
	{
		while (current >= 6 && current <= 11 && (a[current] == 3 || a[current] == 2))
		{
			a[current] = 0;
			current--;
			current = current % 12;
		}
		if (a[6] == 0 && a[7] == 0 && a[8] == 0 && a[9] == 0 && a[10] == 0 && a[11] == 0)
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		while (current >= 0 && current <= 5 && (a[current] == 3 || a[current] == 2))
		{
			a[current] = 0;
			current--;
			current = current % 12;
		}
		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
			return true;
		else
			return false;

	}

}

void capturing(int a[], int& p1, int& p2, int current, int player, int print_type) //captures seeds
{
	int round_score{ 0 };
	char b;

	if (player == 1)
	{
		if (current >= 6 && current <= 11)	//checks if sowing ended in the opponents house
		{
			if (a[current] != 2 && a[current] != 3)
			{
				board(player, a, p1, p2,print_type);
				setcolor(5);
				cout << "The last house didn't have exactly 2 or 3 seeds so no seeds were captured!" << endl <<endl;
				setcolor(14);
				Sleep(1000);
			}
			else
			{
				while (current >= 6 && current <= 11 && (a[current] == 3 || a[current] == 2)) //while the number of seeds is 2 or 3 and the house belongs to an oponent it captures seeds
				{
					cout << "Type 'n' to capture:" << endl;
					cin >> b;
					if (b == 'n')
					{

						setcolor(5);
						cout << "Capturing..." << endl;
						setcolor(14);
						Sleep(250);

						p1 += a[current];
						round_score += a[current];

						setcolor(5);
						cout <<  a[current] << " seeds captured from the opponents house!" << endl;
						setcolor(14);
						Sleep(1000);

						a[current] = 0;
						current--; //goes through the houses counter clockwise
						current = current % 12; //stops the counter from going out f the array's range

						board(player, a, p1, p2,print_type);
					}
				}
				board(player, a, p1, p2, print_type);
				setcolor(5);
				cout <<  "A total of " << round_score << " seeds were captured this round!" << endl<< endl;
				setcolor(14);
				Sleep(1000);

				round_score = 0; //resets the round score
			}
		}
		else
		{
			board(player, a, p1, p2, print_type);
			setcolor(5);
			cout <<  "Sowing ended in the player's house so no seeds were captured!" << endl<<endl;
			setcolor(14);
			Sleep(1000);
		}

	}
	else if (player == 2)
	{
		if (current >= 0 && current <= 5)
		{
			if (a[current] != 2 && a[current] != 3)
			{
				board(player, a, p1, p2, print_type);
				setcolor(5);
				cout << "The last house didn't have exactly 2 or 3 pellets so no seeds were captured!" << endl<<endl;
				setcolor(14);
				Sleep(1000);
			}
			else
			{
				while (current >= 0 && current <= 5 && (a[current] == 3 || a[current] == 2))
				{
					cout <<  "Type 'n' to capture:" << endl;
					cin >> b;

					if (b == 'n')
					{
						setcolor(5);
						cout << "Capturing..." << endl;
						setcolor(14);
						Sleep(100);

						p2 += a[current];
						round_score += a[current];

						setcolor(5);
						cout <<  a[current] << " seeds were captured from the opponents house!" << endl;
						setcolor(14);
						Sleep(1000);

						a[current] = 0;
						current--;
						current = current % 12;

						board(player, a, p1, p2, print_type);
					}
					cin.clear();
				}
				board(player, a, p1, p2, print_type);
				setcolor(5);
				cout <<  "A total of " << round_score << " seeds were captured this round!" << endl<<endl;
				setcolor(14);
				Sleep(1000);

				round_score = 0;
			}
		}
		else
		{
			board(player, a, p1, p2, print_type);
			setcolor(5);
			cout <<  "Sowing ended in the player's house so no seeds were captured!" << endl<<endl;
			setcolor(14);
			Sleep(1000);
		}
	}
	else
	{
		if (current >= 0 && current <= 5)
		{
			if (a[current] != 2 && a[current] != 3) 
			{
				board(player, a, p1, p2, print_type);
				setcolor(5);
				cout << "The last house didn't have exactly 2 or 3 pellets so no seeds were captured!" << endl << endl;
				setcolor(14);
				Sleep(1000);
			}
			else //bot captures automatically
			{
				while (current >= 0 && current <= 5 && (a[current] == 3 || a[current] == 2))
				{
					setcolor(5);
					cout << "Capturing..." << endl;
					setcolor(14);
					Sleep(1000);

					p2 += a[current];
					round_score += a[current];

					setcolor(5);
					cout << a[current] << " seeds were captured from the opponents house!" << endl;
					setcolor(14);
					Sleep(1000);

					a[current] = 0;
					current--;
					current = current % 12;

					board(player, a, p1, p2, print_type);

				}
				board(player, a, p1, p2, print_type);
				setcolor(5);
				cout << "A total of " << round_score << " seeds were captured this round!" << endl << endl;
				setcolor(14);
				Sleep(1000);

				round_score = 0;
			}
		}
		else
		{
			board(player, a, p1, p2, print_type);
			setcolor(5);
			cout << "Sowing ended in the player's house so no seeds were captured!" << endl << endl;
			setcolor(14);
			Sleep(1000);
		}

	}
}

int choosing(int player, int a[]) // selecting a house to get seeds from
{
	int bot_choice;

	if (player == 3) //bot chooses randomly
	{
		srand(time(NULL));	//generating random seed for generating the random numbers
		bot_choice = rand() % 6 + 6;	//getting random number from 6 to 11

		while (a[bot_choice] == 0) //previously had recursion but it ends up having a chance of exeding the recursion depth if there is only one house with seeds to sow
		{
			bot_choice = rand() % 6 + 6;

		}

		switch (bot_choice) {
		case 6:
			cout << "choice: a" << endl;
			Sleep(500);
			return bot_choice;

		case 7:
			cout << "choice: b" << endl;
			Sleep(500);
			return bot_choice;

		case 8:
			cout << "choice: c" << endl;
			Sleep(500);
			return bot_choice;

		case 9:
			cout << "choice: d" << endl;
			Sleep(500);
			return bot_choice;

		case 10:
			cout << "choice: e" << endl;
			Sleep(500);
			return bot_choice;

		case 11:
			cout << "choice: f" << endl;
			Sleep(500);
			return bot_choice;
		}

	}

	char move;

	setcolor(14);
	cout << "Please choose one of your houses with seeds to sow:" << endl;
	cin >> move;

	cout << endl;

	if (player == 1)
	{
		setcolor(5);
		switch (move) {
		case 'A':
			if (a[0] == 0)
			{

				cout << "This house has no seeds to sow! Please retry!"<<endl;

				return choosing(player, a);
			}
			return 0;
		case 'B':
			if (a[1] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!"<<endl;

				return choosing(player, a);
			}
			return 1;
		case 'C':
			if (a[2] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 2;
		case 'D':
			if (a[3] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 3;
		case 'E':
			if (a[4] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 4;
		case 'F':
			if (a[5] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 5;
		default:
			cout << "The house chosen either belongs to your oponent or isn't a valid house! Please Retry!" << endl;
			setcolor(14);
		}
		choosing(player, a);
	}
	else if (player == 2)
	{
		setcolor(5);
		switch (move) {
		case 'a':
			if (a[6] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 6;
		case 'b':
			if (a[7] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 7;
		case 'c':
			if (a[8] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 8;
		case 'd':
			if (a[9] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 9;
		case 'e':
			if (a[10] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 10;
		case 'f':
			if (a[11] == 0)
			{
				cout << "This house has no seeds to sow! Please retry!" << endl;

				return choosing(player, a);
			}
			return 11;
		default:
			cout << "The house chosen either belongs to your oponent or isn't a valid house! Please Retry!" << endl;
			setcolor(14);
		}
		choosing(player, a);
	}
}

void sowing(int a[], int choice, int &p1, int &p2, int player,int print_type)  //sowing the seeds
{
	int current, hand;
	char b;

	hand = a[choice]; //initial amount of seeds to sow

	current = choice; //current house

	a[choice] = 0; //empties house

	board(player, a, p1, p2, print_type);

	for (int i = hand; i != 0; i--)
	{
			current = current % 12;	//houses are numberes from 0 to 11 (A,B,C,...,d,e,f) therefore this stops current from going over the valid indexes for the houses

			if (current == choice) //skips house from where the seeds were first taken
			{
				i++;	//stops the cycle from ending permaturely due to skipping the house
				current++;	//advances to the next house counter clockwise
			}
			else
			{
				if (player == 3) //bot sows automatically
				{
					setcolor(5);
					cout << "Sowing..." << endl;
					setcolor(14);

					Sleep(1000);

					a[current] ++; 
					current++;	
					board(player, a, p1, p2, print_type);
				}
				else
				{
					cout << "Type 'n' to sow the next seed:" << endl;
					cin >> b;

					if (b != 'n')
						i++;   //stops the cycle from ending permaturely if the user does not input 'n'
					else if (b == 'n')
					{
						setcolor(5);
						cout << "Sowing..." << endl;
						setcolor(14);

						Sleep(100);

						a[current] ++; //increments the seeds on the house
						current++;	//advances to the next house counter clockwise
						board(player, a, p1, p2, print_type);

					}
					cin.clear();
				}

			}
	}
	capturing(a, p1, p2, current - 1, player, print_type);
}

bool call_for_draw(int game_type) //after 30 succecive rounds with no points one asks if the players want to end the game in a draw
{
	char b;
	setcolor(5);
	cout << "The game has gone on for 30 successive turns without any player making points!" << endl << endl;
	setcolor(14);
	while (true)
	{
		if (game_type == 1)
		{

			setcolor(14);
			cout << "Player 1, do you wish to call a draw? (y/n)" << endl;
			cin >> b;
			if (b == 'y')
			{
				while (true)
				{
					cout << "Player 2, do you wish to call a draw? (y/n)" << endl;
					cin >> b;
					if (b == 'y')
					{
						return true;
					}
					else if (b == 'n')
					{
						setcolor(5);
						cout << "Player 2 did not wish to call a draw." << endl;
						setcolor(14);
						return false;
					}
				}
			}
			else if (b == 'n')
			{
				setcolor(5);
				cout << "Player 1 did not wish to call a draw." << endl;
				setcolor(14);
				return false;
			}
		}
		else
		{
			cout << "Player 1, do you wish to call a draw? (y/n)" << endl;
			cin >> b;
			if (b == 'y')
			{
				return true;
			}
			else if (b == 'n')
			{
				return false;
			}
		}
	}
}

bool win_condition(int p1, int p2, int a[], int player, int &p1_prev, int &p2_prev, int &p1_count, int &p2_count, int round, int game_type) //checks if the game has been won
{
	if (player == 1 && round != 1)
	{
		if (p1 == p1_prev)
			p1_count++; //counts for how many turns p1 hasn't earned any points
		else
		{
			p1_count = 0;	//resets counters once p1 gains points
			p1_prev = p1;
		}

	}
	else if ((player == 2 || player == 3 )&& round != 1)
	{
		if (p2 == p2_prev)
			p2_count++; //counts for how many turns p2 hasn't earned any points
		else
		{
			p2_count = 0; //resets counters once p2 gains points
			p2_prev = p2;
		}
	}

	if (p1 >= 25)
	{
		cout << "The winner is Player 1 with "<< p1 <<" points!" << endl;
		return false;
	}
	else if (p2 >= 25 && game_type == 1)
	{
		cout << "The winner is Player 2 with " << p2 << " points!" << endl;
		return false;
	}
	else if (p2 >= 25 && game_type == 2)
	{
		cout << "The winner is the Bot with " << p2 << " points! Try harder next time!" << endl;
		return false;
	}
	else if (p1 == 24 && p2 == 24)
	{
		cout << "The game ended in a draw" << endl;
		return false;
	}
	else if (p1_count >= 10 && p2_count >= 10) //p1_count + p2_count = number of rouns, after 20 rounds of not making any points on either side they will be asked if they wish to ask for a draw
	{
		if (call_for_draw(game_type))
		{
			if (game_type == 1)
				cout << endl << "Players agreed to end the game in a draw!" << endl;
			else
				cout << endl << "Player has agreed to stop the game!" << endl;
			return false;
		}
		else
		{
			p1_count = 8;		//if the players don't agree on a draw p1_count and p2_count are turned to 8 so that in 4 rounds where no points are made they will be prompted again
			p2_count = 8;
			return true;
		}
	}
	else
		return true;
}

void player_choice(int counter, int &player, int game_type) //chooses who is paying nect
{
	if (game_type == 1)
	{
		if (counter % 2 == 0)
			player = 2;
		else
			player = 1;
	}
	else
	{
		if (counter % 2 == 0)
			player = 3;
		else
			player = 1;
	}
}

void starting_screen(int &game_type, int &print_type)
{
	char b{ 'a' };
	setcolor(81);
	cout << "----------Welcome to Oware!----------" << endl << endl;
	setcolor(70);
	cout << "P ";
	setcolor(80);
	cout << "- PLAY" << endl;
	setcolor(70);
	cout << "R ";
	setcolor(80);
	cout << "- RULES" << endl<<endl;
	setcolor(81);
	cout << "-------------------------------------" << endl << endl;
	setcolor(14);
	while (b != 'P' && b != 'R')
	{
		cin >> b;
	}


	if (b == 'R')
	{
		system("cls");

		setcolor(80);
		cout << "---Starting conditions---" << endl;
		setcolor(14);
		cout << "The game starts with four seeds in each house." << endl<<endl;

		setcolor(80);
		cout << "-----Sowing-----" << endl;
		setcolor(14);
		cout << "- Players take turns moving the seeds." << endl;
		cout << "- On a turn, a player chooses one of the six houses under their control." << endl;
		cout << "- The player removes all seeds from that house, and distributes them, dropping one in each house counter - clockwise from this house, in a process called sowing." << endl;
		cout << "- Seeds are not distributed into the end scoring houses, nor into the house drawn from meaning that the starting house is always left empty." << endl << endl;

		setcolor(80);
		cout << "-----Capturing-----" << endl;
		setcolor(14);
		cout << "- Capturing occurs only when a player brings the count of an opponent's house to exactly two or three with the final seed he sowed in that turn. " << endl;
		cout << "- This always captures the seeds in the corresponding house, and if the previous - to - last seed also brought an opponent's house to two or three, these are captured as well, and so on until a house is reached which does not contain two or three seeds or does not belong to the opponent." << endl;
		cout << "- If a move would capture all of an opponent's seeds, the capture is forfeited since this would prevent the opponent from continuing the game, and the seeds are instead left on the board." << endl << endl;

		setcolor(80);
		cout << "-----Winning-----" << endl;
		setcolor(14);
		cout << "- The game is over when one player has captured 25 or more seeds, or each player has taken 24 seeds (draw)." << endl;
		cout << "- If there are 20 successive rounds where no player has made any points they may both decide to call a draw on the grounds of the game having entered a loop." << endl;
		cout << "- If they decide to not settle on a draw they will be asked after every 4 rounds until one of the players makes any points." << endl;
		cout << "- If the game reaches a point where one of the players are unable to keep playing (for exemple: there are no valid moves) the winner is the one who acomulated the most points until that point."<< endl;

		cout << "Type anything to proceed!" << endl;

		cin >> b;
		cin.ignore();
	}

	system("cls");

	setcolor(81);
	cout << "----------Choose Game Type!----------" << endl << endl;
	setcolor(70);
	cout << "R ";
	setcolor(80);
	cout << "- REPLACE PREVIOUS BOARD" << endl;
	setcolor(70);
	cout << "S ";
	setcolor(80);
	cout << "- SHOW PREVIOUS MOVES" << endl << endl;
	setcolor(81);
	cout << "-------------------------------------" << endl << endl;
	setcolor(14);

	while (b != 'R' && b != 'S')
	{
		cin >> b;
	}

	if (b == 'R')
		print_type = 1;
	else if (b == 'S')
		print_type = 2;

	system("cls");

	setcolor(80);
	cout << "----------Please, choose a game mode!----------" << endl << endl;
	setcolor(3);
	cout << "A - Player vs Player!" << endl;
	setcolor(5);
	cout << "B - Player vs Bot!" << endl << endl;
	setcolor(80);
	cout << "-----------------------------------------------" << endl << endl;
	setcolor(14);

	while (b != 'A' && b != 'B')
	{
		cin >> b;
	}

	if (b == 'A')
		game_type = 1;
	else if (b == 'B')
		game_type = 2;

	system("cls");
}

bool pre_starved(int a[], int player) //checks if player was already stavarved
{
	if (player == 1)
	{
		if (a[6] == 0 && a[7] == 0 && a[8] == 0 && a[9] == 0 && a[10] == 0 && a[11] == 0)
		{
			return true;
		}
		else
			return false;

	}
	else
	{
		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
		{
			return true;
		}
		else
			return false;
	}
}

char starved_actions(int table[], int player, int& choice, int p1_seeds, int p2_seeds) 
{
	char end{'n'};

	while (starve(table, player, choice)) 
	{
		if (pre_starved(table,player)) //checks if the oponent is able to play next round
		{							   //if the opponent was previously starved either: forces them to play to give the opponent moves if possible or ends the game due to it being impossible to play further
			if (player == 3)
			{
				for (int i = 6; i <= 11; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i))
					{
						choice = i; //updates choice value
						end = 'n';
						return end; 
					}
				}
				cout << "The game cannot proceed because the player won't be able to sow anymore!"<<endl;
				end = 'y';	//flag to end the game
				return end;

			}
			else if (player == 1)
			{
				for (int i = 0; i <= 5; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i))
					{
						setcolor(5);
						cout << "You can't let your oponent starve! You must choose another move!" << endl;
						setcolor(14);

						choice = choosing(player, table);
						end = 'n';
						return end;
					}
				}
				cout << "The game cannot proceed because player 2 won't be able to sow anymore!" << endl;;
				end = 'y';	//flag to end the game
				break;
			}
			else if (player == 2)
			{
				for (int i = 6; i <= 11; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i))
					{
						setcolor(5);
						cout << "You can't let your oponent starve! You must choose another move!" << endl;
						setcolor(14);

						choice = choosing(player, table);
						end = 'n';
						return end;
					}
				}
				cout << "The game cannot proceed because player 1 won't be able to sow anymore!" << endl;;
				end = 'y';	//flag to end the game
				break;
			}
			
		}
		else
		{
			if (player == 3)
			{
				for (int i = 6; i <= 11; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i) && table[i] != 0)
					{
						choice = choosing(player, table); //updates choice value
						end = 'n';
						return end; //returns end = 'n'
					}
				}
				cout << "The game cannot proceed because the player won't be able to sow anymore! Therefore it has ended in a draw!" << endl;
				end = 'y';	//flag to end the game
				return end;

			}
			else if (player == 1)
			{
				for (int i = 0; i <= 5; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i) && table[i] != 0)
					{

						setcolor(5);
						cout << "You can't let your oponent starve! You must choose another move!" << endl;
						setcolor(14);

						choice = choosing(player, table);
						end = 'n';
						return end;
					}
				}
				cout << "The game cannot proceed because player 2 won't be able to sow anymore!" << endl;;
				end = 'y';	//flag to end the game
				break;
			}
			else if (player == 2)
			{
				for (int i = 6; i <= 11; i++) //checks for each available house to see if there are any moves that fill the oponents houses
				{
					if (!starve(table, player, i) && table[i] != 0)
					{
						setcolor(5);
						cout << "You can't let your oponent starve! You must choose another move!" << endl;
						setcolor(14);

						choice = choosing(player, table);
						end = 'n';
						return end;
					}
				}
				cout << "The game cannot proceed because player 1 won't be able to sow anymore!" << endl;;
				end = 'y';	//flag to end the game
				break;
			}
		}
	}
	return end;
}

int main()
{
	int table[] = {4,4,4,4,4,4,4,4,4,4,4,4};
	int round_counter{ 1 }, p1_seeds{ 0 }, p2_seeds{ 0 }, choice{ 0 }, player{ 1 }, p1_prev{ 0 }, p2_prev{ 0 }, p1_count{ 0 }, p2_count{ 0 }, game_type{ 0 }, print_type{ 0 };
	char end;

	starting_screen(game_type, print_type);

	while (win_condition(p1_seeds,p2_seeds,table, player,p1_prev,p2_prev, p1_count, p2_count, round_counter, game_type)) 
	{
		if (print_type == 1)
		{
			system("cls");
			cout << "ROUND: " << round_counter << endl;
			Sleep(500);
		}
		else
			cout << "ROUND: " << round_counter << endl;

		player_choice(round_counter, player,game_type);
		board(player, table, p1_seeds, p2_seeds, print_type);
		choice = choosing(player, table);
		end = starved_actions(table, player, choice, p1_seeds, p2_seeds);

		if (end == 'y')
		{
			forced_end(p1_seeds, p2_seeds, game_type);
			cout << endl;
			break;
		}

		sowing(table, choice, p1_seeds, p2_seeds, player, print_type);
		round_counter++;
	}

	return 0;
}
