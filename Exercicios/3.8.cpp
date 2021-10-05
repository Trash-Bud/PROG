#include <iostream>
#include <sstream> 
using namespace std;

bool readFraction(int &numerator, int &denominator)
{
    cout << "input a fraction: " << endl;
    int a, b;
    if (cin >> a && cin.get() == '/' && cin >> b);
    {
        if (b != 0)
        {
            numerator = a;
            denominator = b;
            return true;
        }
    }
    numerator = 0;
    denominator = 0;
    return false;
}

void reduceFraction(int &numerator, int &denominator)
{
    int gcd, n1, n2;

        if (numerator == denominator)
            gcd = numerator;
        else if (numerator == 0)
            gcd = denominator;
        else
        {
            n1 = numerator;
            n2 = denominator;
            while (n1 != n2)
            {
                if (n1 > n2)
                    n1 -= n2;
                else
                    n2 -= n1;
            }
            gcd = n1;
        }

        numerator = numerator / n1;
        denominator = denominator / n2;
}

void operateFraction()
{
    int n1, n2, n3, n4;
    int res1, res2;
    char a;
    if (readFraction(n1, n2) && cin >> a && readFraction(n3, n4))
    {
        if (a == '+')
        {
            res1 = n1 * n4 + n2 * n3;
            res2 = n2 * n4;
            reduceFraction(res1, res2);
            cout << "the result is: " << res1 << "/" << res2 << endl;
        }
        else if (a == '-')
        {
            res1 = n1 * n4 - n2 * n3;
            res2 = n2 * n4;
            reduceFraction(res1, res2);
            cout << "the result is: " << res1 << "/" << res2 << endl;
        }
        else if (a == '*')
        {
            res1 = n1 * n3;
            res2 = n2 * n4;
            reduceFraction(res1, res2);
            cout << "the result is: " << res1 << "/" << res2 << endl;
        }
        else if (a == '/')
        {
            res1 = n1 * n4;
            res2 = n2 * n3;
            reduceFraction(res1, res2);
            cout << "the result is: " << res1 << "/" << res2 << endl;
        }
        else
            cout << "invalid input" << endl;

    }
    else
        cout << "invalid input" << endl;

}

int main()
{
    int n1,n2;
    char op;
    cout << "choose an option: (A or B)" << endl << "A - operations" << endl << "B - reduction" << endl;
    cin >> op;
    
    if (op == 'A')
    {
        operateFraction();
    }
    else if (op == 'B')
    {
        readFraction(n1,n2);
        reduceFraction(n1, n2);
        cout << n1 << "/" << n2 << endl;
    }
    else
        cout << "invalid operation"<<endl;

    return 0;
}
