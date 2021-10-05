#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int value) //a)
{
	int lb, up, mid, size;
	bool variable_found{ false };

	size = v.size() - 1;
	lb = 0;
	up = size;
	mid = up / 2;

	while (variable_found != true)
	{

		if (v[mid] > value)
		{
			up = mid - 1;
		}
		else if (v[mid] < value)
		{
			lb = mid +1;
		}
		else
		{
			variable_found = true;
		}
		mid = lb + ((up - lb) / 2);	

		if (lb > up)
		{
			mid = -1;
			variable_found = true;
		}
	}

	return mid;

}


int main() //b
{
	vector<int> v = { 0,2,5,6,7,32,67,87,99,130};
	int res;

	res = binarySearch(v, 30);

	cout << res;

	return 0;

}
