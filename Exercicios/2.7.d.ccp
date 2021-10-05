#include <iostream>
using namespace std;

int main()
{
	int s,t;
	unsigned long int i;

	i = 4294967295;
	t = 0;

	for (unsigned long int n = i; n > 5; i--)
	{
		s = sqrt(i);
		for (int f = 2; f <= s; f++)
		{
			if (i % f == 0)
			break;
			else if (f == s)
			{
				t = 1;
				cout << i << endl;
				break;
			}
		}
		if (t == 1)
			break;
	}
	return 0;
}
