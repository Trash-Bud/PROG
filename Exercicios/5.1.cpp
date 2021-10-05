#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;


int mod(int a, int b)
{
	if (a > 0)
		return a % b;
	else
	{
		while (a < 0)
		{
			a += b;
		}
	}
	return a;
}

char encryptChar(char c, int key) //a)
{
	int ind;
	char alphabetlower[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char alphabetupper[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	if (islower(c))
	{
		for (int index = 0; index < 26; ++index)
		{
			if (alphabetlower[index] == c)
			{
				ind = index;
				break;
			}
		}

		return alphabetlower[mod((ind + key), 26)];
	}
	else
	{
		for (int index = 0; index < 26; ++index)
		{
			if (alphabetupper[index] == c)
			{
				ind = index;
				break;
			}
		}
		return alphabetupper[mod((ind + key), 26)];
	}
}

string encryptString(string s, int key) //b)
{
	int ind;
	char c, fin;
	string alphabetlower = "abcdefghijklmnopqrstuvwxyz";
	string alphabetupper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (string::size_type i = 0; i < s.size(); i++)
	{
		c = s[i];
		if (islower(c))
		{
			for (string::size_type index = 0; index < 26; index++)
			{
				if (alphabetlower[index] == c)
				{
					ind = index;
					s[i] = alphabetlower[mod(ind + key, 26)];
					break;
				}
			}
		}
		else
		{
			for (string::size_type index = 0; index < 26; ++index)
			{
				if (alphabetupper[index] == c)
				{
					ind = index;
					s[i] = alphabetupper[mod(ind + key, 26)];
					break;
				}
			}
		}
	}

	return s;

}


const char* encryptStringC(const char* s, int key) //d)
{
	int ind, n{ 0 };
	char c, t{ s[0] }, * fin;
	char alphabetlower[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char alphabetupper[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	while (t != NULL)
	{
		n++;
		t = s[n];
	}

	fin = (char*)malloc(n);


	for (int i = 0; i < n; i++)
	{
		c = s[i];
		if (c == ' ')
			fin[i] = ' ';
		else if (islower(c))
		{
			for (int index = 0; index < 26; index++)
			{
				if (alphabetlower[index] == c)
				{
					ind = index;
					fin[i] = alphabetlower[mod(ind + key, 26)];

					break;
				}
			}
		}
		else
		{
			for (int index = 0; index < 26; ++index)
			{
				if (alphabetupper[index] == c)
				{
					ind = index;
					fin[i] = alphabetupper[mod(ind + key, 26)];
					break;
				}
			}
		}
	}

	const char* final = fin;
	return final;

}

int main()
{
	//a)
	//char c{ 'a' }; 
	//int n1{ 2 }, n2{ -5 };

	//cout << encryptChar(c, n1) << endl;
	//cout << encryptChar(c, n2) << endl;

	//b)
	//string s = "The quick brown fox JUMPS over the lazy dog"; 
	//int n1 = 10, n2 = -10;

	//cout << encryptString(s, n1) << endl;
	//cout << encryptString(s, n2) << endl;


	//c)
	const char* s = "The quick brown fox JUMPS over the lazy dog";
	int n1 = 10, n2 = -10;

	cout << encryptStringC(s, n1) << endl;
	cout << encryptStringC(s, n2) << endl;
	return 0;
}


