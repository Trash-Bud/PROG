#include <iostream>
using namespace std;

bool readInt(int& x)
{
    char ch;
    int num = 0;
    ch = cin.peek();
    while (ch != '\n')
    {
        if (!(ch >= '0' && ch <= '9')) {
            cin.sync();
            return false;
        }
        num = num * 10 + ch - '0';
        cin.ignore(1);
        ch = cin.peek();
    }

    cin.sync(); // cleans the buffer
    x = num;
    return true;
}


int main()
{
    int x;
    if (readInt(x))
    {
        cout << "The number is " << x << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }
    return 0;
}

