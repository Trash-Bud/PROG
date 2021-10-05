#include <iostream>
#include <vector>
using namespace std;

int descending(const void* x, const void* y) //a
{

	if (*(int*)x > * (int*) y)
		return -1;
	else if (*(int*)x < *(int*)y)
		return 1;
	else
		return 0;
}

int ascending(const void* x, const void* y) //b
{

	if (*(int*)x > * (int*)y)
		return 1;
	else if (*(int*)x < *(int*)y)
		return -1;
	else
		return 0;
}

int main() //c
{
	int a[] = {2,5,6,8,2,4,6,3,6,2};
	
	qsort(a, sizeof(a) / 8, 4, ascending);
	qsort(a + 5, sizeof(a) / 8, 4, ascending);


	for (int i = 0; i < sizeof(a)/ 4; i++)
	{
		cout << a[i] << ",";
	}

	return 0;
}
