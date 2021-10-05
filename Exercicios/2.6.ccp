#include <iostream>
using namespace std;

int main()
{
	double n, q, j, t;

	cout << "insert the values(number of years, amount deposited (€), anual interest rate (%))" << endl;
	cin >> n >> q >> j;

	do
	{
		q = q + (j / 100) * q;
		n--;
	} while (n != 0);


	cout << "the ammount is " << q << "€";

	return 0;
}
