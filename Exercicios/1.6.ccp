#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double d1, d2, d3, s, a;

	cout << "insert the coordinates of the vertices of the triangle" << endl;
	cout << "A (x y)?";
	cin >> x1 >> y1;
	cout << "B (x y)?";
	cin >> x2 >> y2;
	cout << "C (x y)?";
	cin >> x3 >> y3;


	d1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	d2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	d3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	s = (d1 + d2 + d3) / 2;
	a = sqrt(s * (s - d1) * (s - d2) * (s - d3));

	cout << "area = " << a << endl;

	return 0;
}
