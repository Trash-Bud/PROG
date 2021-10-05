#include <iostream>
#include <sstream> 
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};


bool readFraction(Fraction &fraction)
{
    cout << "input a fraction: " << endl;
    int a, b;
    if (cin >> a && cin.get() == '/' && cin >> b);
    {
        if (b != 0)
        {
            fraction.numerator = a;
            fraction.denominator = b;
            return true;
        }
    }

    fraction.numerator = 0;
    fraction.denominator = 0;
    return false;
}

void reduceFraction(Fraction &fraction)
{
    int gcd, n1, n2;

    if (fraction.numerator == fraction.denominator)
        gcd = fraction.numerator;
    else if (fraction.numerator == 0)
        gcd = fraction.denominator;
    else
    {
        n1 = fraction.numerator;
        n2 = fraction.denominator;
        while (n1 != n2)
        {
            if (n1 > n2)
                n1 -= n2;
            else
                n2 -= n1;
        }
        gcd = n1;
    }

    fraction.numerator = fraction.numerator / gcd;
    fraction.denominator = fraction.denominator / gcd;
}

void operateFraction()
{
    Fraction fr1, fr2, fr3;
    char a;
    if (readFraction(fr1) && cin >> a && readFraction(fr2))
    {
        if (a == '+')
        {
            fr3.numerator = fr1.numerator * fr2.denominator + fr2.numerator * fr1.denominator;
            fr3.denominator = fr1.denominator * fr2.denominator;
            reduceFraction(fr3);
            cout << "the result is: " << fr3.numerator << "/" << fr3.denominator << endl;
        }
        else if (a == '-')
        {
            fr3.numerator = fr1.numerator * fr2.denominator - fr2.numerator * fr1.denominator;
            fr3.denominator = fr1.denominator * fr2.denominator;
            reduceFraction(fr3);
            cout << "the result is: " << fr3.numerator << "/" << fr3.denominator << endl;
        }
        else if (a == '*')
        {
            fr3.numerator = fr1.numerator*fr2.numerator;
            fr3.denominator = fr1.denominator*fr2.denominator;
            reduceFraction(fr3);
            cout << "the result is: " << fr3.numerator << "/" << fr3.denominator << endl;
        }
        else if (a == '/')
        {
            fr3.numerator = fr1.numerator * fr2.denominator;
            fr3.denominator = fr1.denominator * fr2.numerator;
            reduceFraction(fr3);
            cout << "the result is: " << fr3.numerator << "/" << fr3.denominator << endl;
        }
        else
            cout << "invalid input" << endl;

    }
    else
        cout << "invalid input" << endl;

}

int main()
{
    Fraction fr1;
    char op;
    cout << "choose an option: (A or B)" << endl << "A - operations" << endl << "B - reduction" << endl;
    cin >> op;

    if (op == 'A')
    {
        operateFraction();
    }
    else if (op == 'B')
    {
        readFraction(fr1);
        reduceFraction(fr1);
        cout << fr1.numerator << "/" << fr1.denominator << endl;
    }
    else
        cout << "invalid operation" << endl;

    return 0;
}
