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
	int maxSize;    //班级能够容纳学生的最多个数
	Student* stus;    //记录班级学生，用指向指针的数组，因为不知道数组的大小；考虑到有增删学生的操作，用单链表应该更合适
	int count;   //记录班级上的实际学生数量
public:
	Student* getStudent(int index);
	int getCount();
	int findStudent(string stuNo);   // 按学校查寻某个学生，若找到，返回该学生在学生数组中的序号，从0开始索引
	bool deleteStudent(string stuNo);   //删除指定学号的学生。若学生存在，从学生数组中删除，并将数组中其后的学生存放位置前移1位；否则，直接返回false;
	bool addStudent(Student stu);   //若删除人数未满，则将该生添加在学生数组的最后；否则，直接返回false;
	double calCourseAverage(int course);    //计算某门课的平均分。course = 1：英语；course = 2：数学；course = 3：计算机。
	Student findMaxScoreStudent();   //寻找总分（或平均分）最高的学生
	Grade();    //缺省构造函数，留给系统使用的，用户不该用该函数创建对象
	Grade(int maxSize);    //构造函数，确定班级最大人数，开辟相应的存储空间，实际人数初始化为0。
	Grade(Grade &grade);    //拷贝构造函数。由于类的成员含有指针变量，应自定义拷贝构造函数
	int CountEnglish();     //英语不及格的人数
	int CountMath();     //数学不及格的人数
	int CountComputer();     //计算机不及格的人数
	int CountCpp();     //C++不及格的人数
	bool Pass(int Score);  //是否合格
	virtual ~Grade();

};

#endif // !defined(AFX_GRADE_H__0BCDBA6E_412D_4566_881F_678FA1C66EFF__INCLUDED_)
