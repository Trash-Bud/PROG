#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cout << "insert the two numbers:" << endl << "n1?";
	cin >> a;
	cout << "n2?";
	cin >> b;

	c = a + b;

	if (a > b)
	{
		if (c > a)
			cout << "sum overflow" << endl;
		else if (c < b)
			cout << "sum underflow" << endl;
		else
			cout << "result = " << c << endl;
	}

	if (a < b)
	{
		if (c > b)
			cout << "sum overflow" << endl;
		else if (c < a)
			cout << "sum underflow" << endl;
		else
			cout << "result = " << c << endl;
	}

	return 0;
}
