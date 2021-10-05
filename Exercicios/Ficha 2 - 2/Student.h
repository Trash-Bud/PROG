#include <string>


#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
	Student();
	Student(const std::string& code, const std::string& name);
	void setGrades(double shortExam, double project, double exam);

	std::string getCode() const;
	std::string getName() const;
	int getFinalGrade() const;
	bool isApproved() const;

	static int weightShortExam, weightProject, weightExam; // weights in percentage (ex: 20,30,50)

private:
	std::string code;
	std::string name;
	double shortExam, project, exam;
	int finalGrade;

};
#endif