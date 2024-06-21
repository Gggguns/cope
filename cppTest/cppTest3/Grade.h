// Grade.h: interface for the Grade class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRADE_H__0BCDBA6E_412D_4566_881F_678FA1C66EFF__INCLUDED_)
#define AFX_GRADE_H__0BCDBA6E_412D_4566_881F_678FA1C66EFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Student.h"

class Grade  
{
private:
	int maxSize;    //�༶�ܹ�����ѧ����������
	Student* stus;    //��¼�༶ѧ������ָ��ָ������飬��Ϊ��֪������Ĵ�С�����ǵ�����ɾѧ���Ĳ������õ�����Ӧ�ø�����
	int count;   //��¼�༶�ϵ�ʵ��ѧ������
public:
	Student* getStudent(int index);
	int getCount();
	int findStudent(string stuNo);   // ��ѧУ��Ѱĳ��ѧ�������ҵ������ظ�ѧ����ѧ�������е���ţ���0��ʼ����
	bool deleteStudent(string stuNo);   //ɾ��ָ��ѧ�ŵ�ѧ������ѧ�����ڣ���ѧ��������ɾ������������������ѧ�����λ��ǰ��1λ������ֱ�ӷ���false;
	bool addStudent(Student stu);   //��ɾ������δ�����򽫸��������ѧ���������󣻷���ֱ�ӷ���false;
	double calCourseAverage(int course);    //����ĳ�ſε�ƽ���֡�course = 1��Ӣ�course = 2����ѧ��course = 3���������
	Student findMaxScoreStudent();   //Ѱ���ܷ֣���ƽ���֣���ߵ�ѧ��
	Grade();    //ȱʡ���캯��������ϵͳʹ�õģ��û������øú�����������
	Grade(int maxSize);    //���캯����ȷ���༶���������������Ӧ�Ĵ洢�ռ䣬ʵ��������ʼ��Ϊ0��
	Grade(Grade &grade);    //�������캯����������ĳ�Ա����ָ�������Ӧ�Զ��忽�����캯��
	int CountEnglish();     //Ӣ�ﲻ���������
	int CountMath();     //��ѧ�����������
	int CountComputer();     //����������������
	int CountCpp();     //C++�����������
	bool Pass(int Score);  //�Ƿ�ϸ�
	virtual ~Grade();

};

#endif // !defined(AFX_GRADE_H__0BCDBA6E_412D_4566_881F_678FA1C66EFF__INCLUDED_)
