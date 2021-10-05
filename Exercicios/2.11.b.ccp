#include <iostream>
using namespace std;

int main()
{
	float n, sum{ 1 }, term{ 1 };

	cout << "Enter n  ";
	cin >> n;
	
	if (n == 0)
		cout << sum;
	else
	{
		for (float i = 1; i <= n; i++)
		{
			term = term * (1 / i);
			sum += term;
		}
		cout <<endl<< sum;
	}
	return 0;
}
