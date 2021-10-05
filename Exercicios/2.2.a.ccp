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
		cout << "largest number =" << a << endl;
	}
	if (c > b&& c > a)
	{
		cout << "largest number =" << c << endl;
	}
	if (a < b && c < b)
	{
		cout << "largest number =" << b << endl;
	}

	if (a < b&& a < c)
	{
		cout << "smallest number =" << a << endl;
	}
	if (c < b&& c < a)
	{
		cout << "smallest number =" << c << endl;
	}
	if (a > b && c > b)
	{
		cout << "smallest number =" << b << endl;
	}

	return 0;
}
