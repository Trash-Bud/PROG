#include <iostream>
#include <iomanip>

using namespace std;

double round(double x, unsigned n)
{
	return floor(x * pow(10, n)) / pow(10, n);
}

int main()
{
	double x, result;
	unsigned  n;

	cout << "insert the value to be rounded - ";
	cin >> x;
	cout << "insert the number of decimal places to round to - ";
	cin >> n;

	result = round(x, n);

	cout << result;

	return 0;
}
