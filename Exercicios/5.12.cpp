#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void uncompress(string compressed, string uncompressed)
{
	fstream image;
	ofstream image_uncompressed;
	vector<string> v;
	string path{ "C:\\Users\\Joana\\Documents\\Uni\\Programação\\5.12\\" }, code, pathIn, pathOut, a{ "" };
	double b;
	stringstream str;

	pathOut = path + uncompressed + ".txt";
	pathIn = path + compressed + ".txt";

	image.open(pathIn);

	if (!image)
	{
		cerr << "unable to open file";
		exit(1);
	}

	image_uncompressed.open(pathOut);

	getline(image, code);

	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == ' ')
		{
			v.push_back(a);
			a = "";
		}
		else
			a += code[i];
	}

	v.push_back(a);

	image_uncompressed << v[0] << " " << v[1] << " ";


	for (int i = 0; i < v[2].size(); i++)
	{
		while (isdigit(v[2][i]))
		{
			str << v[2][i];
			i++;
		}

		str >> b;

		str.clear();

		if (v[2][i] == 'b')
		{
			for (int e = 0; e < b; e++)
			{
				image_uncompressed << 'b';
			}
		}
		else if (v[2][i] == 'w')
		{
			for (int e = 0; e < b; e++)
			{
				image_uncompressed << 'w';
			}
		}
	}

	image.close();
	image_uncompressed.close();
}

void compress(string uncompressed, string compressed)
{
	fstream image;
	ofstream image_compressed;
	string path{ "C:\\Users\\Joana\\Documents\\Uni\\Programação\\5.12\\"}, code, pathIn,pathOut;
	int	counter{ 0 };

	pathIn = path + uncompressed + ".txt";
	pathOut = path + compressed + ".txt";

	image.open(pathIn);

	if (!image)
	{
		cerr << "unable to open file";
		exit(1);
	}

	image_compressed.open(pathOut);

	getline(image, code);

	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] != 'b' && code[i] != 'w')
		{
			image_compressed << code[i];
		}
		else if (code[i] == 'b')
		{
			while (code[i] == 'b')
			{
				counter++;
				i++;
			}
			cout << counter << 'b';
			image_compressed << counter<<'b';
			counter = 0;
			i--;
		}
		else 
		{
			while (code[i] == 'w')
			{
				counter++;
				i++;
			}
			cout << counter << 'w';
			image_compressed << counter << 'w';
			counter = 0;
			i--;
		}
	}

	image.close();
	image_compressed.close();
}


int main()
{
	string function, a{ "" };
	vector<string> arguments;

	getline(cin, function);

	for (int i = 0; i < function.size(); i++)
	{
		while (function[i] != ' ' && i < function.size())
		{
			a += function[i];
			i++;
		}
		arguments.push_back(a);
		a = "";
	}

	if (arguments.size() == 3 && arguments[0] == "compress")
	{
		compress(arguments[1], arguments[2]);
	}
	else if (arguments.size() == 3 && arguments[0] == "uncompress")
	{
		uncompress(arguments[1], arguments[2]);
	}
	else
	{
		cerr << "argument not valid";
		exit(1);
	}

	return 0;
}
