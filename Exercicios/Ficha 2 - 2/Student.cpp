#include "Student.h"

using namespace std;

int Student::weightShortExam = 20;

int Student::weightProject = 30;

int Student::weightExam = 50;

Student::Student()
{
	this->code = "none";
	this->name = "none";
}

Student::Student(const std::string& code, const std::string& name)
{
	this->code = code;
	this->name = name;
}

void Student::setGrades(double shortExam, double project, double exam)
{
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;

	this->finalGrade = round((this->shortExam *weightShortExam + this->project * weightProject + this->exam * weightExam)/100);
}

std::string Student::getCode() const
{
	return this->code;
}

std::string Student::getName() const
{
	return this->name;
}

int Student::getFinalGrade() const
{
	return this->finalGrade;
}

bool Student::isApproved() const
{
	if (this->finalGrade >= 10)
		return true;
	else
		return false;
}
