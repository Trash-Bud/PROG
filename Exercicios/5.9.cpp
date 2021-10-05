#include <iostream>
#include <vector>
#include <stdlib.h>   
#include <time.h> 
#include <string>
using namespace std;

struct streetAdress {
    string street, city;
    unsigned int doorNumber;
};

struct person {
    string name, gender;
    unsigned int age;
    streetAdress adress;
};

void readData(vector<person>& people)
{
    unsigned int a;
    person p;

    cout << "Input the number of people you wish to include: ";
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cout << "Name: ";
        cin >> p.name;
        cout << "Age: ";
        cin >> p.age;
        cout << "Gender(F/M): ";
        cin >> p.gender;
        cout << "Street: ";
        cin >> p.adress.street;
        cout << "City: ";
        cin >> p.adress.city;
        cout << "Door Number: ";
        cin >> p.adress.doorNumber;
        people.push_back(p);
    }

}

void compareCities(vector<person> people)
{
    if (people.size() > 1)
    {
        for (int i = 0; i < people.size() - 1; i++)
        {
            cout << endl << people[i].name << " lives in " << people[i].adress.city << " city with ";
            for (int e = i; e < people.size(); e++)
            {
                if (people[i].adress.city == people[e].adress.city)
                {
                    cout << people[e].name << ", ";
                    people.erase(people.begin() + e);
                }
            }
        }
    }
}


int main()
{
    vector<person> people;
    readData(people);
    compareCities(people);

    return 0;
}
