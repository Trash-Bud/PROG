#include <iostream>
using namespace std;

struct Date {
    unsigned int year, month, day;
};

void readDate(Date* d) //a)
{
    int year, month, day;
    cout << "insert the date in the following format:" << endl;
    
    cout << "YYYY: ";
    cin >> year;
    cout << "MM: ";
    cin >> month;
    cout << "DD: ";
    cin >> day;

    d->year = year;
    d->month = month;
    d->day = day;
}

void writeDate(const Date *d) //b)
{
    cout << d->year << "/" << d->month << "/" << d->day << endl;;

}

int compareDates(const Date* d1, const Date* d2) //c)
{
    if (d1->year > d2->year)
    {
        return 1;
    }
    else if (d1->year == d2->year)
    {
        if (d1->month > d2->month)
        {
            return 1;
        }
        else if (d1->month == d2->month)
        {
            if (d1->day > d2->day)
            {
                return 1;
            }
            else if (d1->day == d2->day)
            {
                return 0;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    else
        return -1;
}

void sortDates(Date* d1, Date* d2) //d)
{
    Date d4;
    Date* d3;
    d3 = &d4;

    if (compareDates(d1, d2) == 1)
    {
        *d3 = *d2;
        *d2 = *d1;
        *d1 = *d3;
    }
 
}

int main() //e)
{
    Date d;
    Date d2;
    Date* date;
    Date* date2;
    date2 = &d2;
    date = &d;

    readDate(date);
    readDate(date2);

    writeDate(date);
    writeDate(date2);
    cout << endl;

    sortDates(date, date2);

    writeDate(date);
    writeDate(date2);
    cout << endl;

    return 0;
}
