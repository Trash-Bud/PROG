#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double side1, side2, side3, area, semiper;
    side1 = distance(x1,y1,x2,y2);
    side2 = distance(x3, y3, x2, y2);
    side3 = distance(x1, y1, x3, y3);
    semiper = (side1 + side2 + side3) / 2;
    area = sqrt(semiper * (semiper - side1) * (semiper - side2) * (semiper - side3));
    cout << "The area of that triangle is: " << area;
    return area;
}

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

    area(x1, y1, x2, y2, x3, y3);

	return 0;
