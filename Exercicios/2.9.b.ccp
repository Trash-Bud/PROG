#include <iostream>
using namespace std;

int main()
{
	int b, b1, n{ 0 }, n1{ 0 }, c{ 0 }, n2, n3, n4;

	cout << "Enter a three digit number (???)  ";
	cin >> b;

	b1 = b;
	
	while (b != 0)
	{
		b = (int)b / 10;
		n++;
	}

	for (int i = n-1; i >= 0; i--)
	{
		n2 = (int)(b1 / pow(10, i));
		n3 = ((int)(b1 / pow(10, i + 1))) * 10;
		n4 = n2 - n3;
		n1 += pow(10, c) * n4;
		c++;
	}

	if (n1 == b)
		cout << "The number is a palyndrome";
	else
		cout << "The number is not a palyndrome";
	return 0;
}
