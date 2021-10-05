#include <iostream>
using namespace std;

int main()
{
	int h1, min1, s1, h2, min2, s2;
	int tf, df, hf, minf, sf;

	cout << "Time1 (hours minutes seconds) ?";
	cin >> h1 >> min1 >> s1;
	cout << "Time2 (hours minutes seconds) ?";
	cin >> h2 >> min2 >> s2;

	tf = (h1 + h2) * 3600 + (min1 + min2) * 60 + s1 + s2;
	sf = tf % 60;
	minf = (tf / 60) % 60;
	hf = (tf / 3600) % 24;
	df = tf / 3600 / 24;

	cout << "time1 + Time 2 = " << df << " day, " << hf << " hours, " << minf << " minutes and " << sf << " seconds";

	return 0;
}
