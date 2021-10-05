#include <iostream>
using namespace std;

int main()
{
	float n, sum{ 0 },val;

	cout << "Enter n  ";
	cin >> n;
	
	for (float i = 0; i <= n; i++)
	{
		val = pow(-1, i) * (4 / ((2 * i) + 1));
		sum += val;
	}

	cout << sum;
	return 0;
}
