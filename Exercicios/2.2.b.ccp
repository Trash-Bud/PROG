#include <iostream>
using namespace std;

int main()
{
	double a, b, c;

	cout << "input 3 numbers:" << endl;
	cout << "n1?";
	cin >> a;
	cout << "n2?";
	cin >> b;
	cout << "n3?";
	cin >> c;

	if (a> b && a >c)
	{
		if (b > c)
			cout << a << "," << b << "," << c << endl;
		else
			cout << a << "," << c << "," << b << endl;
	}
	if (c > b && c > a)
	{
		if (b > a)
			cout << c << "," << b << "," << a << endl;
		else
			cout << c << "," << a << "," << b << endl;
	}
	if (a < b && c < b)
	{
		if (a > c)
			cout << b << "," << a << "," << c << endl;
		else
			cout << b << "," << c << "," << a << endl;
	}

	return 0;
}
2.2
c)
#include <iostream>
using namespace std;

int main()
{
	double a, b, c;

	cout << "input 3 sides of the triangle:" << endl;
	cout << "l1?";
	cin >> a;
	cout << "l2?";
	cin >> b;
	cout << "l3?";
	cin >> c;

	if (a < 0 || b<0 || c < 0)
		cout << "numbers have to be positive" << endl;
	else
	{
		if (a > b&& a > c)
		{
			if (b + c > a)
				cout << "it's not a triangle" << endl;
			else
				cout << "it's a triangle" << endl;
		}
		if (c > b&& c > a)
		{
			if (b + a > c)
				cout << "it's not a triangle" << endl;
			else
				cout << "it's a triangle" << endl;
		}
		if (a < b && c < b)
		{
			if (a + c > b)
				cout << "it's not a triangle" << endl;
			else
				cout << "it's a triangle" << endl;
		}
	}
	return 0;
}
