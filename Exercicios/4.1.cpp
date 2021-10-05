#include <iostream>
using namespace std;

void readArray(int a[], size_t nElement)
{
    int b;
    for (int i = 0; i < nElement; i++)
    {
        cout << "index " << i << ": ";
        cin >> a[i];
    }
}

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2)
{
    for (int i = pos1; i <= pos2; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}

int findValueInArrayButBetter(const int a[], size_t nElem, int value)
{
    for (int i = 0; i <= nElem; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}

int findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[])
{
    int t = 0;
    for (int i = pos1; i <= pos2; i++)
    {
        if (a[i] == value)
        {
            index[t] == i;
            t++;
        }
    }
    return t;
}


int  main()
{
    int a[10], value;
    size_t pos1, pos2, index[10];

    cout << "INSERT THE VALUES FOR THE ARRAY: "<< endl;
    readArray(a, 10);

    cout << "INSERT THE VALUE TO BE SEARCHED: ";
    cin >> value;
    
    cout << "INSERT THE SEARCH'S UPPER BOUND: ";
    cin >> pos1;

    cout << "INSERT THE SEARCH'S LOWER BOUND (MUST BE LOWER THAN 10): ";
    cin >> pos2;
    
    cout << findMultValuesInArray(a, 10, value, pos1, pos2, index);

    return 0;
