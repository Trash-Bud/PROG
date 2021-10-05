#include <iostream>
using namespace std;

int main()
{
	double A, B, C;
	double mean, Amean, Bmean, Cmean;

	cout << "Please, input 3 integer numbers" << endl;
	cout << "A?";
	cin >> A;
	cout << "B?";
	cin >> B;
	cout << "C?";
	cin >> C;

	mean = (A + B + C) / 3;
	Amean = A - mean;
	Bmean = B - mean;
	Cmean = C - mean;

	cout << "mean = " << mean << endl;
	cout << "A-mean = " << Amean << endl;
	cout << "B-mean = " << Bmean << endl;
	cout << "C-mean = " << Cmean << endl;

	return 0;
}
