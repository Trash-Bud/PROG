//a ---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

void readArray(vector <int> &v, size_t nElement)
{
    int b;
    for (int i = 0; i < nElement; i++)
    {
        cout << "index " << i << ": ";
        cin >> b;
        v.push_back(b);
    }
}


int findMultValuesInArray(vector <int> v, size_t nElem, int value, size_t pos1, size_t pos2, vector <size_t> &index)
{
    int t = 0;
    for (int i = pos1; i <= pos2; i++)
    {
        if (v[i] == value)
        {
            index.push_back(i);
            t++;
        }
    }
    return t;
}


int  main()
{
    int value;
    vector <int> v;
    vector <size_t> index;
    size_t pos1, pos2, nElement;

    cout << "INSERT THE NUMBER OF VALUES TO BE INSERTED: " << endl;
    cin >> nElement;

    cout << "INSERT THE VALUES FOR THE ARRAY: "<< endl;
    readArray(v, nElement);

    cout << "INSERT THE VALUE TO BE SEARCHED: ";
    cin >> value;
    
    cout << "INSERT THE SEARCH'S UPPER BOUND: ";
    cin >> pos1;

    cout << "INSERT THE SEARCH'S LOWER BOUND (MUST BE LOWER THAN "<< nElement <<" ): ";
    cin >> pos2;
    
    cout << findMultValuesInArray(v, 10, value, pos1, pos2, index);

    return 0;
}
//b --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

void readArray(vector <int>& v)
{
    int b, i{ 0 };
    while (true)
    {
        cout << "index " << i << ": ";
        i++;
        cin >> b;
        if (cin.eof())
        {
            cin.clear();
            break;
        }
        else
            v.push_back(b);
    }
}


int findMultValuesInArray(vector <int> v, size_t nElem, int value, size_t pos1, size_t pos2, vector <size_t>& index)
{
    int t = 0;
    for (int i = pos1; i <= pos2; i++)
    {
        if (v[i] == value)
        {
            index.push_back(i);
            t++;
        }
    }
    return t;
}


int  main()
{
    int value;
    vector <int> v;
    vector <size_t> index;
    size_t pos1, pos2;

    //cout << "INSERT THE NUMBER OF VALUES TO BE INSERTED: " << endl;
    //cin >> nElement;

    cout << "INSERT THE VALUES FOR THE ARRAY: " << endl;
    readArray(v);

    cout << "INSERT THE VALUE TO BE SEARCHED: ";
    cin >> value;

    cout << "INSERT THE SEARCH'S UPPER BOUND: ";
    cin >> pos1;

    cout << "INSERT THE SEARCH'S LOWER BOUND (MUST BE A VALID INDEX): ";
    cin >> pos2;

    cout << findMultValuesInArray(v, 10, value, pos1, pos2, index);

    return 0;
}
