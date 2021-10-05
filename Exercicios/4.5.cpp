#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& v) //a)
{
	int size;

	size = v.size() - 1;

	for (int i = 0; i < size; i++)
	{
		for (int e = i + 1; e < size; e++)
		{
			while (v[i] == v[e] && e < size)
			{
				for (int f = e; f < size - 1; f++)
				{
					v[f] = v[f + 1];
				}
				size--;
				v.pop_back();
			}
		}
	}
	v.pop_back();
}



int main() //b
{
	vector<int> v = { 3,3,3,3,3,6,3,2,4,5,6,4,4,6,7,8,7,6,4,5,6,44,3,88,88};
	
	removeDuplicates(v);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ",";
	}

	return 0;

}
