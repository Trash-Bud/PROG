#include <iostream>

using namespace std;

int main()
{
	int n, l{ 0 }, b, dig;
	float sum{ 0 }, mean, large, small, std{ 0 };


	cout << "input your sequence (end by pressing Ctr+Z) ";
	cin >> n;

	b = n;
	dig = b % 10;
	large = dig;
	small = dig;

	while (b != 0)
	{
		l += 1;
		dig = b % 10;
		sum += dig;
		if (dig > large)
			large = dig;
		if (dig < small)
			small = dig;

		b = b / 10;
	}

	mean = sum / l;

	for (int i = 1; i <= l; i++)
	{
		dig = n % 10;
		std += pow(dig - mean, 2);
		n = n / 10;

	}
	std =sqrt( std / l);

	cout << "sum = " << sum << endl << "mean = " << mean << endl << "standard deviation = " << std << endl << "largest = " << large << endl << "smallest = " << small;

	return 0;
}
