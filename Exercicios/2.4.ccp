#include <iostream>
using namespace std;

int main()
{
	double a, b;

	cout << "insert the weight:" << endl << "n1?";
	cin >> a;

	if (a <= 500)
		cout << "the price is 5€";
	if (501 <= a && a <= 1000)
	{
		b = ceil((a - 500) / 100);
		cout << "the price is " << 5 + b * 1.5 << "€";
	}
	if (a > 1000)
	{
		b = ceil((a - 1000) / 250);
		cout << "the price is " << 12.5 + b * 5 << "€";
	}
	return 0;
}

