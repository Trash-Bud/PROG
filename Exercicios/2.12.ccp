#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float n, sum{ 1 }, x, term{ 1 }, prec;

	cout << "Enter n  ";
	cin >> n;
	cout << "Enter x  ";
	cin >> x;
	cout << "Enter precision  ";
	cin >> prec;

	if (n == 0)
		cout << sum;
	else
	{
		for (float i = 1; i <= n; i++)
		{
			term = term *(-(x / i));
			sum += term;
		}
		cout << setprecision(prec) << sum;
	}
	return 0;
}
