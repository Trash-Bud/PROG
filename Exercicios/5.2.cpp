#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <string>
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



//int main()
//{
//	vector<string> v;
//	string c;
//
//	cout << "Type the name to sort. When you are done type 'stop'." << endl;
//
//	while (c != "stop")
//	{
//		cin >> c;
//		if (c!= "stop")
//			v.push_back(c);
//	}
//
//	bubbleSort(v, 'a');
//
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << ",";
//	}
//
//	cout << endl;
//
//	bubbleSort(v, 'd');
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << ",";
//	}
//
//	return 0;
//}
