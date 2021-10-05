#include <iostream>
using namespace std;

int main()
{
	int b,n1,n3;

	cout << "Enter a three digit number (???)  ";
	cin >> b;

	n1 = (int)b / 100;
	n3 = b - ((int)b / 10) * 10;

	if (n1 == n3)
		cout << "The number is a polymdrome." << endl;
	else
		cout << "The number is not a polymdrome." << endl;
	return 0;
}
