#include <iostream>
#include <iomanip>

using namespace std;

void sqrt(float n, float delta, float nMaxlter)
{
	float rq{ 1 }, dif{ 7 }, rqn{ 1 }, prec{ 0 }, dif2;

	dif2 = delta;

	while (dif2 < 1 && dif != 0)
	{
		prec++;
		dif2 = dif2 * 10;
	}

	while (dif > delta || nMaxlter != 0)
	{
		rqn = rq;
		rq = (rq + n / rq) / 2;
		dif = n - pow(rq, 2);

		cout << fixed << setprecision(prec) << setfill('0');
		cout << rqn << "   " << rq << "   " << pow(rq, 2) << "   " << dif << endl;

		nMaxlter--;

	}


}

int main()
{
	float n, delta, nMaxlter;

	cout << "insert a value: ";
	cin >> n;
	cout << "insert a delta: ";
	cin >> delta;
	cout << "insert a max number of iterarations: ";
	cin >> nMaxlter;

	cout << "rq" << "   " << "rqn" << "   " << "rqn^2" << "   " << "dif" << endl;

	sqrt(n, delta, nMaxlter);


	return 0;
}
