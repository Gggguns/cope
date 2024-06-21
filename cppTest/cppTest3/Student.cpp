// Student.cpp: implementation of the Student class.
//
//////////////////////////////////////////////////////////////////////

#include "Student.h"
#include "iostream"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//ȱʡ���캯����ʲô������
Student::Student()
{

}

//��ѧ�ż�����Ϊ�����Ĺ��캯�������ɼ�ȫ����Ϊ��1����ʾ��δ¼��ѧ���ɼ�
Student::Student(string number, string name)
{
	stuNumber = number;
	stuName = name;
	englishScore = -1;
	mathScore = -1;
	computerScore = -1;
	cppScore=-1;
}

//¼�����ſεĳɼ�
void Student::enterScore(double e, double m, double c,double cpp)
{
	englishScore = e;
	mathScore = m;
	computerScore = c;
	cppScore=cpp;
}

//�����ѧ����ƽ���ɼ�
double Student::everage()
{
	return (englishScore + mathScore + computerScore + cppScore) / 4; 
}

//��ʾ��ѧ������Ϣ
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

//����ĳ�ſεĳɼ���course = 1��Ӣ�course = 2����ѧ��course = 3�������:course =4:C++.
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
