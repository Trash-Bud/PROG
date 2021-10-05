#include <iostream>
using namespace std;

int main()
{
	double p, r;
	double M;
	const double PI = 4 * atan(1.0);

	cout << "Input the specific mass of the materials of the sphere  (in kilograms)";
	cin >> p;
	cout << "Input the radious of the sphere (in meters)";
	cin >> r;

	M = (4.0 / 3.0) * p * PI * pow(r,3.0);
	
	cout << "the mass of the sphere is " << M << " Kg/m^3";
	return 0;
}
