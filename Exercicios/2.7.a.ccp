#include <iostream>
using namespace std;

int main()
{
	int n, s;

	cout << "insert the number" << endl;
	cin >> n;

	s = sqrt(n);

	for (int i = 2; i = s; i++)
	{
		if (n % i == 0)
		{
			cout << i << " is a divisor of " << n << " therefore is is not a prime number";
			break;
		}
		else if (i == s)
		{
			cout << n << " is a prime number";
			break;
		}
	}

	return 0;
}
