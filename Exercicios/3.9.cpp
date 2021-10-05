#include <iostream>
#include <map>
using namespace std;

bool isLeap(int year)
{
	if (year % 100 == 0 && year % 400 != 0)
		return true;
	else
		return false;
}

int numDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 11 || month == 9)
		return 30;
	else if (month == 2)
	{
		if (isLeap(year))
			return 29;
		else
			return 28;
	}
	else
		return 31;		
}

void daysWeek(int month, int year)
{
	int days, a, s, ds, n{ 0 };

	a = year - (year/100) * 100;
	s = year / 100;

	map<int, int> n_leap = {
	{ 1, 0 },
	{ 2, 3 },
	{ 3, 3 },
	{ 4, 6 },
	{ 5, 1 },
	{ 6, 4 },
	{ 7, 6 },
	{ 8, 2 },
	{ 9, 5 },
	{ 10, 0 },
	{ 11, 3 },
	{ 12, 5 },
	};

	map<int, string> month_n = {
	{ 1, "January" },
	{ 2, "February"},
	{ 3, "March" },
	{ 4, "April" },
	{ 5, "May" },
	{ 6, "June" },
	{ 7, "July" },
	{ 8, "August" },
	{ 9, "September" },
	{ 10, "October" },
	{ 11, "November" },
	{ 12, "December" },
	};
	
	days = numDays(month, year);

	if (month == 1)
	{
		if (isLeap(year))
		{
			ds = ((((int)floor((5 * a) / 4) + 6 + 1 - 2 * (s % 4) + 7) % 7) - 1) % 7;
		}
		else
		{
			ds = ((((int)floor((5 * a) / 4) + n_leap[month] + 1 - 2 * (s % 4) + 7) % 7) - 1) % 7;
		}
	}
	else if (month == 2)
	{
		if (isLeap(year))
		{
			ds = ((((int)floor((5 * a) / 4) + 2 + 1 - 2 * (s % 4) + 7) % 7) - 1) % 7;
		}
		else
		{
			ds = ((((int)floor((5 * a) / 4) + n_leap[month] + 1 - 2 * (s % 4) + 7) % 7) - 1) % 7;
		}
	}
	else
	{
		ds = ((((int)floor((5 * a) / 4) + n_leap[month] + 1 - 2 * (s % 4) + 7) % 7) - 1) % 7;
	}
	cout << month_n[month] << " /" << year << endl;
	cout << "SUN  MON  TUE  WED  THU  FRI  SAT" << endl;

	for (int i = 0; n <= days; i++)
	{
		if (i >= ds)
		{
			n++;
			if (i % 7 == 0)
			{
				cout << endl;
			}
			cout << n << "    ";
		}
		else
			cout << "--    ";
	}
	cout << endl << endl;
}
int main()
{
	int year;
	cout << "insert the year: ";
	cin >> year;

	for (int month = 1; month <= 12; month++)
	{
		daysWeek(month, year);
	}
	return 0;
}
