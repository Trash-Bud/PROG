#include <iostream>
#include <iomanip>

using namespace std;

int gcdf(int n1, int n2)
{
	if (n1 == n2)
		return n1;
	else if (n1 == 0)
		return n2;
	else if (n2 == 0)
		return n1;
	else
	{
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;
		}
		return n1;
	}
}

int gcdf2(int n1, int n2)
{
	int res;

	if (n1 == n2)
		res = n1;
	else if (n1 == 0)
		res = n2;
	else if (n2 == 0)
		res = n1;
	else
	{
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;
		}
		res = n1;
	}
	return res;
}
int main()
{
	int n1, n2, gcd;

	cout << "insert the two numbers: ";
	cin >> n1 >> n2;


	gcd = gcdf(n1, n2);

	cout <<gcd;

	return 0;
}
