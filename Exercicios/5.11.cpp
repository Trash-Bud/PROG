#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

void bubbleSort(vector<string>& v, char order) //a
{
	int swi{ 1 }, a{ 0 };
	string b;

	if (order == 'a')
	{
		while (swi != 0)
		{
			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] > v[i + 1])
				{
					a++;
					b = v[i];
					v[i] = v[i + 1];
					v[i + 1] = b;
				}
			}
			swi = a;
			a = 0;
		}
	}
	else if (order == 'd')
	{
		while (swi != 0)
		{
			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] < v[i + 1])
				{
					a++;
					b = v[i];
					v[i] = v[i + 1];
					v[i + 1] = b;
				}
			}
			swi = a;
			a = 0;
		}
	}
}



int main()
{
	vector<string> v;
	string c;
	fstream inFile;
	ofstream outfile;

	inFile.open("C:\\Users\\Joana\\Documents\\Uni\\Programação\\name.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	while (inFile >> c)
	{
		v.push_back(c);
	}
	inFile.close();

	bubbleSort(v, 'a');

	outfile.open("C:\\Users\\Joana\\Documents\\Uni\\Programação\\names_sorted.txt");

	for (int i = 0; i < v.size(); i++)
	{
		outfile << v[i]<< " ";
	}

	outfile.close();

	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << ",";
	//}

	//cout << endl;

	//bubbleSort(v, 'd');
	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << ",";
	//}

	return 0;
}
