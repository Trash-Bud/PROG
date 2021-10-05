#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void seeVector(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << i << ". " << v[i] << "   ";
}

string normalizeName(const string& name)
{
	vector<string> v;
	string str, final{ "" }, sub{ "" };

	str = name;


	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			continue;
		}
		else
		{
			while (str[i] != ' ')
			{
				if (islower(str[i]))
				{
					str[i] = toupper(str[i]);
				}
				sub += str[i];
				i++;
			}
			v.push_back(sub);
			sub = "";
		}
	}

	for (int e = 0; e < v.size(); e++)
	{
		if (v[e] == "DE" || v[e] == "DO" || v[e] == "DA" || v[e] == "DOS" || v[e] == "DAS" || v[e] == "E")
		{
			continue;
		}
		else if (e == v.size() - 1)
		{
			final += v[e];
		}
		else
		{
			final += v[e] + " ";
		}
	}

	return final;
}





int main()
{
	cout <<normalizeName("            Maria da Felicidade dos Reis e Passos Dias de Aguiar  ");


	return 0;
}
