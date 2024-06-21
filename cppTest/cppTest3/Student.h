// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__76FB9D3E_C4EE_404B_873F_27DEE233BF50__INCLUDED_)
#define AFX_STUDENT_H__76FB9D3E_C4EE_404B_873F_27DEE233BF50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "string"
#include "iostream"
#include "cstdlib"
using namespace std;

class Student  
{
private:
	string stuNumber;   //学号，格式为：BJ16XX，最后两位为序号
	string stuName;     //姓名
	double englishScore;   //英语成绩
	double mathScore;      //数学成绩
	double computerScore;    //计算机成绩
	double cppScore;        //C++成绩 

public:
	Student(Student &stu);
	double getCourseScore(int course);   //返回某门课的成绩。course = 1：英语；course = 2：数学；course = 3：计算机。
	string getStudentNumber();
	string getStudentName();
	Student();   //缺省构造函数，因为没有提供变更学号与姓名的函数，用户不应该使用该函数创建对象
	Student(string number, string name);    //用姓名及学号构造学生
	void enterScore(double e, double m, double c,double cpp);   //录入三门课的成绩
	double everage();   //计算该学生的平均成绩
	void show();    //显示该学生的信息
	virtual ~Student();    //析构函数
};

#endif // !defined(AFX_STUDENT_H__76FB9D3E_C4EE_404B_873F_27DEE233BF50__INCLUDED_)
