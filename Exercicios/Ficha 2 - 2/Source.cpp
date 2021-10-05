#include <iostream>
#include <string>
#include <vector>

#include "Student.h"

using namespace std;

Student readStudentData()
{
	string code, name;
	double shortExam, project, exam;

	cout << "Student code? ";
	cin >> code;

	cout << "Student name? ";
	cin >> name;

	Student S(code, name);
	
	cout << "Short exam grade? ";
	cin >> shortExam;

	cout << "project grade? ";
	cin >> project;

	cout << "exam grade? ";
	cin >> exam;
	cout << endl;
	S.setGrades(shortExam, project, exam);

	return S;
}

void showAboveAverageStudents(vector<Student> Students)
{
	double average{0};

	for (int i = 0; i < Students.size(); i++)
	{
		average += Students[i].getFinalGrade();
	}

	average = average / Students.size();

	for (int i = 0; i < Students.size(); i++)
	{ 
		if (Students[i].getFinalGrade() > average)
		{
			cout << "Name: " << Students[i].getName() << endl;
			cout << "Code: " << Students[i].getCode() << endl;
			cout << "Final Grade: " << Students[i].getFinalGrade() << endl << endl;
		}
	}
}

int main()
{

	vector <Student> Students;
	int numStudents;

	cout << "How many students need to be logged in? ";
	cin >> numStudents;

	for (int i = 0; i < numStudents; i++)
	{
		Students.push_back(readStudentData());
	}

	showAboveAverageStudents(Students);

	return 0;
}
