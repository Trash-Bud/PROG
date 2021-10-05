#include <iostream>
using namespace std;

int main()
{
	float A, B, C, R, X1, X2;

	cout << "Solution of Ax^2 + Bx + C = 0"<< endl << "Insert the coefficients(A B C) :";
	cin >> A >> B >> C;

	R = pow(B, 2) - 4 * A * C;
	X1 = (-B + sqrt(R)) / (2 * A);
	X2 = (-B - sqrt(R)) / (2 * A);

	if (R < 0)
		cout << "The equation has 2 complex roots :" << X1 << " and " << X2;
	else if (R == 0)
		cout << "The equation has 2 equal real roots :" << X1;
	else
		cout << "The equation has 2 real roots :" << X1 << " and " << X2;


	return 0;
}
