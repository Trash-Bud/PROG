#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float n, rq{ 1 }, dif{ 7 }, delta, nMaxlter, rqn{ 1 }, dif2, prec{0};

	cout << "insert a value: ";
	cin >> n;
	cout << "insert a delta: ";
	cin >> delta;
	cout << "insert a max number of iterarations: ";
	cin >> nMaxlter;

	cout << "rq" << "   " << "rqn" << "   " << "rqn^2" << "   " << "dif"<<endl;

	dif2 = delta;

	while (dif2 < 1 && dif != 0)
	{
		prec++;
		dif2 = dif2 * 10;
	}

	while (dif > delta || nMaxlter != 0 )
	{
		rqn = rq;
		rq = (rq + n / rq) / 2;
		dif = n - pow(rq, 2);

		cout << fixed << setprecision(prec) << setfill('0');
		cout << rqn << "   " << rq << "   " << pow(rq, 2) << "   " << dif << endl;

		nMaxlter--;

	}




	return 0;
}
