#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float i, f, s;
	const int M_PI = 3.1415926;

	cout << "insert the interval and step (biggining end step) ";
	cin >> i >> f >> s;

	cout << "ang" << "  " << "sin" << "  " << "cos" << "  " << "tan" << endl;
	for (float n = i; n <= f; n += s)
	{
		cout << n << "  " << sin(n* M_PI/180) << "  " << cos(n * M_PI / 180) << "  " << tan(n * M_PI / 180) << endl;

	}
	return 0;
}
