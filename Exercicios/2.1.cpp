#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d, e, f;
	double x, y;

	cout << "input the 6 values:" << endl;
	cout << "a?";
	cin >> a;
	cout << "b?";
	cin >> b;
	cout << "c?";
	cin >> c;
	cout << "d?";
	cin >> d;
	cout << "e?";
	cin >> e;
	cout << "f?";
	cin >> f;

	x = (c * e - b * f) / (a * e - b * d);
	y = (c * e - b * f) / (a * e - b * d);

	if (a * e - b * d == 0)
	{
		cout << "impossible system" << endl;
	}
	else
	{
		cout << "x is " << x << endl;
		cout << "y is " << y << endl;
	}
	return 0;
}
