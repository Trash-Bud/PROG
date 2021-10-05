#include <iostream>
using namespace std;

int main()
{
	int s;
	const int n = 1000;
	
	cout << "2 is a prime number" << endl;
	cout << "3 is a prime number" << endl;

	for (int i = 5; i < n; i++)
	{
		s = sqrt(i);
		for (int f = 2; f <= s; f++)
		{
			if (i % f == 0)
				break;
			else if (f == s)
			{
				cout << i << " is a prime number"<<endl;
				break;
			}
		}
	}

	return 0;
}
