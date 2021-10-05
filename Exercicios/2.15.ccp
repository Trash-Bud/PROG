#include <iostream>
#include <ctime>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;

int main()
{
	int n1, n2, res, user_res;

	srand(time(0));

	n1 = rand() % 10;
	n2 = rand() % 10;
	res = n1 * n2;

	cout << "how much is: " << n1 << " x " << n2 << " ? ";

	clock_t begin = clock();

	cin >> user_res;

	clock_t end = clock();

	double elapsed_secs = double(end - begin);

	if (user_res != res)
		cout << "Very Bad";
	else
	{
		if (elapsed_secs < 5000)
			cout << "Good";
		if (elapsed_secs >= 5000 && elapsed_secs <= 10000)
			cout << "Satisfactory";
		if (elapsed_secs > 10000)
			cout << "Insufficient";
	}
	return 0;
}
