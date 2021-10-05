#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& v) 
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


void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) //a)
{

	for (int i = 0; i < v2.size(); i++)
		v3.push_back(v2[i]);
	for (int i = 0; i < v1.size(); i++)
		v3.push_back(v1[i]);
}

void vectorInstersection(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) //a)
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int e = 0; e < v2.size(); e++)
		{
			if (v1[i] == v2[e])
			{
				v3.push_back(v2[e]);
				break;
			}
		}
	}
	removeDuplicates(v3);
}


int main() //b
{
	vector<int> v = { 3,3,3,3,3,6,3,2,4,5,6,4,4,6,7,8,7,6,4,5,6,44,3,88,88};
	vector<int> v2 = { 6,4,3,2,2,22,6,7,8,9,6,5,4,3,22,45,6 };
	vector<int> v3;

	vectorUnion(v, v2, v3);

	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << ",";
	}
	cout << endl;

	v3 = {};

	vectorInstersection(v, v2, v3);

	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << ",";
	}
	cout << endl;

	return 0;

}
