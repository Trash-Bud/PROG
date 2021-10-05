#include <iostream>
#include <vector>
using namespace std;

const int NE = 5;

void localMax(const int a[][NE])
{
	for (int i = 0; i < NE; i++)
	{
		if (i == 0 || i == 4)
		{
			continue;
		}

		for (int e = 0; e < NE; e++)
		{
			if (e == 0 || e == 4)
			{
				continue;
			}
			if (a[i][e] > a[i][e - 1] && a[i][e] > a[i][e - 1] && a[i][e] > a[i + 1][e] && a[i][e] > a[i - 1][e] && a[i][e] > a[i - 1][e - 1] && a[i][e] > a[i - 1][e + 1] && a[i][e] > a[i + 1][e - 1] && a[i][e] > a[i + 1][e + 1])
			{
				cout << "(" << i << ", " << e << ") - " << a[i][e] << endl;
			}
		}
	}


}


int main() //b
{
	const int a[][NE] = { {7,3,4,1,3}, {2,9,6,2,1}, {1,3,5,1,4}, {6,5,2,7,5}, {4,2,1,3,6} };

	localMax(a);

	return 0;
}
