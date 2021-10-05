#include <iostream>
#include <vector>
#include <stdlib.h>   
#include <time.h> 
using namespace std;

struct EuroMilionBet {
    vector<unsigned> mainNumbers;
    vector<unsigned> luckyStars;
};


void vectorInstersection(const vector<unsigned>& v1, const vector<unsigned>& v2, vector<unsigned>& v3) //a)
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int e = 0; e < v2.size(); e++)
		{
			if (v1[i] == v2[e])
			{
				v3.push_back(v2[e]);
				break;
			}
		}
	}
}

void readBet(EuroMilionBet& bet)
{
    unsigned a{ 57 };

    for (int i = 0; i < 5; i++)
    {
        while (a > 50 || a < 1)
        {
            cout << i << " - chose a main number between 1 and 50: ";
            cin >> a;
        }
        bet.mainNumbers.push_back(a);
        a = 57;
    }
    for (int i = 0; i < 2; i++)
    {
        while (a > 12 || a < 1)
        {
            cout << i << " - chose a lucky star between 1 and 12: ";
            cin >> a;
        }
        bet.luckyStars.push_back(a);
        a = 57;
    }
}

void generateKey(EuroMilionBet &Key)
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Key.mainNumbers.push_back(rand() % 50 + 1);
    }
    for (int i = 0; i < 2; i++)
    {
        Key.luckyStars.push_back(rand() % 12 + 1);
    }
}

void resultBet(EuroMilionBet& bet, EuroMilionBet& key, EuroMilionBet &result)
{
    vectorInstersection(bet.mainNumbers, key.mainNumbers, result.mainNumbers);
    vectorInstersection(bet.luckyStars, key.luckyStars, result.luckyStars);
}

int main()
{
    EuroMilionBet bet, key, result;
    generateKey(key);
    readBet(bet);
    resultBet(bet, key, result);

    cout << "Bet(MN): ";

    for (int i = 0; i < bet.mainNumbers.size(); i++)
    {
        cout << bet.mainNumbers[i] << " ";
    }

    cout << endl<< "Bet(LS): ";

    for (int i = 0; i < bet.luckyStars.size(); i++)
    {
        cout << bet.luckyStars[i] << " ";
    }

    cout << endl<< "Key(MN): ";
    for (int i = 0; i < key.mainNumbers.size(); i++)
    {
        cout << key.mainNumbers[i] << " ";
    }

    cout <<endl<< "Key(LS): ";

    for (int i = 0; i < key.luckyStars.size(); i++)
    {
        cout << key.luckyStars[i] << " ";
    }

    cout << endl<<"Main numbers guessed: ";

    for (int i = 0; i < result.mainNumbers.size(); i++)
    {
        cout << result.mainNumbers[i] << " ";
    }

    cout << endl << "Main numbers guessed: ";

    for (int i = 0; i < result.luckyStars.size(); i++)
    {
        cout << result.luckyStars[i] << " ";
    }

    return 0;
}
