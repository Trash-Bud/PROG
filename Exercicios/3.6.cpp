#include <iostream>
#include <iomanip>
#include <ctime> 
 


using namespace std;

float timeElapsed(double t)
{
	double m{ 0 };

	m = clock();

	if (t == 0)
		cout << 0 << endl;
	else
		cout << m - t << endl;
	
	return m;
}

int main()
{
	double t{ 0 };
	t = timeElapsed(t);

	cout<< 3 * 3;

	t = timeElapsed(t);
	cout << 3 * 3;
	cout << 3 * 3;
	cout << 3 * 3;
	t = timeElapsed(t);
	cout << 3 * 3;
	cout << 3 * 3;
	t = timeElapsed(t);

	
}
