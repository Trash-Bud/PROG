#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <time.h> 
using namespace std;

string slice_str(const char* str, size_t start, size_t end)
{
	size_t j = 0;
	string output;
	for (size_t i = start; i <= end; ++i) {
		output = output + str[i];
	}
	return output;
}

int getMonthInt(string c)
{
	map<string, int> months ={
		{ "Jan", 1 },
		{ "Feb",2 },
		{ "Mar",3 },
		{ "Apr",4 },
		{ "May",5 },
		{ "Jun",6 },
		{ "Jul",7 },
		{ "Aug",8 },
		{ "Sep",9 },
		{ "Oct",10 },
		{ "Nov",11 },
		{ "Dec",12 },
	};
	return months[c];
}

class Date
{
public:
	//b
	Date();

	//a
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(string yearMonthDay); //yearMonthDay must be in format "yyy/mm/dd"
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate() const;	//returns the date in format "yyyy/mm/dd"
	void show() const; // shows the date on the screen in format "yyyy/mm/dd"

	//c)
	bool isValid();
	bool isEqualTo(const Date &date);
	bool isNotEqualTo(const Date& date);
	bool isAfter(const Date& date);
	bool isBefore(const Date& date);

private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int numberDays();
};




bool Date::isEqualTo(const Date& date)
{
	if (this->day == date.day && this->month == date.month && this->year == date.year)
	{
		return true;
	}
	else
		return false;
}

bool Date::isNotEqualTo(const Date& date)
{
	if (this->day == date.day && this->month == date.month && this->year == date.year)
	{
		return false;
	}
	else
		return true;
}

bool Date::isAfter(const Date& date)
{
	if (this->year < date.year)
		return true;
	else if (this->year > date.year)
		return false;
	else
	{
		if (this->month < date.month)
			return true;
		else if (this->month > date.month)
			return false;
		else
		{
			if (this->day < date.day)
				return true;
			else
				return false;
		}
	}		
}

bool Date::isBefore(const Date& date)
{
	if (this->year > date.year)
		return true;
	else if (this->year < date.year)
		return false;
	else
	{
		if (this->month > date.month)
			return true;
		else if (this->month < date.month)
			return false;
		else
		{
			if (this->day > date.day)
				return true;
			else
				return false;
		}
	}
}

Date::Date(){
    time_t my_time = time(NULL);
    char str[30];
    ctime_s(str, sizeof str, &my_time);
    this->day = stoi(slice_str(str,8,9));
    this->year = stoi(slice_str(str,20,23));
    this->month = getMonthInt(slice_str(str,4, 6));
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string yearMonthDay)
{
	stringstream str;
	double x, f{ 0 };

	for (int i = 0; i < yearMonthDay.size(); i++)
	{
		while (isdigit(yearMonthDay[i]))
		{
			str << yearMonthDay[i];
			i++;
		}
		str >> x;
		str.clear();

		if (f == 0)
		{
			this->year = x;
		}
		else if (f == 1)
		{
			this->month = x;
		}
		else
		{
			this->day = x;
		}


		if (yearMonthDay[i] == '/')
			f++;
	}


}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

unsigned int Date::getYear() const
{
	return this->year;
}

unsigned int Date::getMonth() const
{
	return this->month;
}

unsigned int Date::getDay() const
{
	return this->day;
}

string Date::getDate() const
{
	string result;
	
	result = to_string(this->year) + "/" + to_string(this->month) + "/" + to_string(this->day);

	return result;
}

void Date::show() const
{
	cout << getDate() << endl;
}

bool Date::isValid()
{
	if (this->numberDays() == 0)
	{
		return false;
	}
	else
	{
		if (this->day > numberDays())
		{
			return false;
		}
		else
			return true;
	}
}

unsigned int Date::numberDays()
{
	if (this->month == 11 || this->month == 4 || this->month == 6 || this->month == 9)
		return 30;
	else if (this->month == 2)
	{
		if (this->year % 100 == 0 && this->year % 400 != 0)
			return 28;
		else
			return 27;
	}
	else if (this->month >12)
		return 0;
	else
		return 31;
}


int main()
{
	Date d1(2020, 5, 3), d2("2009/11/37"), d;

	d.show();
	d1.show();
	d2.show();
	cout << d2.getDay() << "," << d2.getMonth() << "," << d2.getYear() << endl;

	d2.setDate(2000, 3, 4);
	cout << d2.getDay() << "," << d2.getMonth() << "," << d2.getYear()<< endl;

	if (d2.isValid())
	{
		cout << "It's valid" << endl;
	}
	else
		cout << "It's invalid" << endl;

	if (d2.isAfter(d1))
	{
		d1.show();
		cout << " is after"<<endl;
		d2.show();
	}
	else
	{
		d1.show();
		cout << " is not after"<<endl;
		d2.show();
	}

	if (d2.isBefore(d1))
	{
		d1.show();
		cout << " is before"<<endl;
		d2.show();
	}
	else
	{
		d1.show();
		cout << " is not before"<<endl;
		d2.show();
	}

	return 0;
}
