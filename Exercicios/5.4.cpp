#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

bool sequenceSearch1(const string& s, int nc, char c)
{
	int counter{ 0 };

	for (int i = 0; i < s.size(); i++)
	{
		while (s[i] == c)
		{
			counter++;
			i++;
		}
		if (counter == nc)
			return true;
		else
			counter = 0;
	}
	return false;
		
}

bool sequenceSearch2(const string& s, int nc, char c)
{
	string str;
	int counter;

	for (int i = 0; i < s.size(); i++)
	{
		str = s.substr(i, nc);
		size_t n = count(str.begin(), str.end(), c);
		if (n == nc)
			return true;
	}
	return false;
}


int main()
{
	bool c;
	//c = sequenceSearch1("abcddeedddf", 4, 'd');
	c = sequenceSearch2("abcddeedddf", 4 , 'd');
	cout << c;

	return 0;
}
