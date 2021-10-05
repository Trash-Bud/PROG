#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) //a)
{
	int b;
	for (int e = v.size() - 1; e > 0; e--)
	{
		for (int i = 0; i < e; i++)
		{
			if (v[i] > v[i + 1])
			{
				b = v[i];
				v[i] = v[i + 1];
				v[i + 1] = b;
			}
		}
	}
}

void bubbleSort2(vector<int>& v) //c)
{
	int b, swi{ 1 }, a{ 0 };
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

bool ascending(int x, int y) //e)
{
	if (x < y)
	{
		return true;
	}
	else
		return false;
}

bool descending(int x, int y) //e
{
	if (x > y)
	{
		return true;
	}
	else
		return false;
}

void bubbleSort4(vector<int>& v, bool f(int x, int y)) //e
{
	int b, swi{ 1 }, a{ 0 };
	while (swi != 0)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (f(v[i],v[i+1]))
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



void bubbleSort3(vector<int>& v) //d)
{
	int b, swi{ 1 }, a{ 0 };
	char c;

	while (true)
	{
		cout << "type 'a' for ascending order and 'd' for descending" << endl;
		cin >> c;
		if (c == 'a')
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
			break;
		}
		else if (c == 'd')
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
			break;
		}
	}
}

int main() //b
{
	vector<int> v = { 7,4,5,3,8,4,2,5,8,0,0,1 };

	bubbleSort4(v, ascending);


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ",";
	}

	bubbleSort4(v, descending);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ",";
	}

	return 0;
}
