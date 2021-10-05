#include <iostream>
using namespace std;

int main()
{
	int b,t;

	cout << "Enter a number  ";
	cin >> b;
	
	while (b != 1)
	{
		for (int i = 2; i <= b; i++)
		{
			while (b % i == 0)
			{
				cout << i << endl;
				b = b / i;
			}
		}

	}
	
	return 0;
}
