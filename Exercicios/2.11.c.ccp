#include <iostream>
using namespace std;

int main()
{
	float n, sum{ 1 }, x, term{ 1 };

	cout << "Enter n  ";
	cin >> n;
	cout << "Enter x  ";
	cin >> x;
	
	if (n == 0)
		cout << sum;
	else
	{
		for (float i = 1; i <= n; i++)
		{
			term = term *(-(x / i));
			sum += term;
		}
		cout <<endl<< sum;
	}
	return 0;
}
