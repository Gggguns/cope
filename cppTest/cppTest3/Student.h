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
	string stuNumber;   //ѧ�ţ���ʽΪ��BJ16XX�������λΪ���
	string stuName;     //����
	double englishScore;   //Ӣ��ɼ�
	double mathScore;      //��ѧ�ɼ�
	double computerScore;    //������ɼ�
	double cppScore;        //C++�ɼ� 

public:
	Student(Student &stu);
	double getCourseScore(int course);   //����ĳ�ſεĳɼ���course = 1��Ӣ�course = 2����ѧ��course = 3���������
	string getStudentNumber();
	string getStudentName();
	Student();   //ȱʡ���캯������Ϊû���ṩ���ѧ���������ĺ������û���Ӧ��ʹ�øú�����������
	Student(string number, string name);    //��������ѧ�Ź���ѧ��
	void enterScore(double e, double m, double c,double cpp);   //¼�����ſεĳɼ�
	double everage();   //�����ѧ����ƽ���ɼ�
	void show();    //��ʾ��ѧ������Ϣ
	virtual ~Student();    //��������
};

#endif // !defined(AFX_STUDENT_H__76FB9D3E_C4EE_404B_873F_27DEE233BF50__INCLUDED_)
