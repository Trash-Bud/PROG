#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int M_PI = 3.1415926;

	cout << "ang" << "  " << "sin" << "  " << "cos" << "  " << "tan" << endl;
	for (float n = 0; n <= 90; n += 15)
	{
		cout << n << "  " << sin(n* M_PI/180) << "  " << cos(n * M_PI / 180) << "  " << tan(n * M_PI / 180) << endl;

	}
	return 0;
}
