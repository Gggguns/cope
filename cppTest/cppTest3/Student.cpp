// Student.cpp: implementation of the Student class.
//
//////////////////////////////////////////////////////////////////////

#include "Student.h"
#include "iostream"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//缺省构造函数，什么都不做
Student::Student()
{

}

//以学号及姓名为参数的构造函数，将成绩全部置为－1，表示尚未录入学生成绩
Student::Student(string number, string name)
{
	stuNumber = number;
	stuName = name;
	englishScore = -1;
	mathScore = -1;
	computerScore = -1;
	cppScore=-1;
}

//录入四门课的成绩
void Student::enterScore(double e, double m, double c,double cpp)
{
	englishScore = e;
	mathScore = m;
	computerScore = c;
	cppScore=cpp;
}

//计算该学生的平均成绩
double Student::everage()
{
	return (englishScore + mathScore + computerScore + cppScore) / 4; 
}

//显示该学生的信息
void Student::show()
{
	cout << "The information of the student is: " << endl;
	cout << "the number of the student is: " << stuNumber << endl;
	cout << "the name of the student is: " << stuName << endl;
	cout << "the score of English is: " << englishScore << endl;
	cout << "the score of math is: " << mathScore << endl;
	cout << "the score of computer is: " << computerScore << endl;
	cout << "the score of cpp is: " << cppScore << endl;
	cout << "the average score is: " << everage() << endl;
	cout << endl;
}

Student::~Student()
{

}


string Student::getStudentNumber()
{
	return stuNumber;
}

string Student::getStudentName()
{
	return stuName;
}		

//返回某门课的成绩。course = 1：英语；course = 2：数学；course = 3：计算机:course =4:C++.
double Student::getCourseScore(int course)
{
	switch (course)
	{
	case 1:
		return englishScore;
	case 2:
		return mathScore;
	case 3:
		return computerScore;
	case 4:
		return cppScore;
	default:
		return -1;
	}
}

Student::Student(Student &stu)
{
	stuNumber = stu.stuNumber;
	stuName = stu.stuName;
	englishScore = stu.englishScore;
	mathScore = stu.mathScore;
	computerScore = stu.computerScore;
	cppScore=stu.cppScore;
}
