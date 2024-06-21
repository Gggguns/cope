// Grade.cpp: implementation of the Grade class.
//
//////////////////////////////////////////////////////////////////////

#include "Grade.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Grade::Grade()
{

}

Grade::Grade(int maxSize)
{
	this->maxSize = maxSize;
	stus = new Student[maxSize];
	count = 0;
}

//拷贝构造函数，需要深度拷贝
Grade::Grade(Grade &grade)
{
	maxSize = grade.maxSize;
	count = grade.count;
	stus = new Student[maxSize];    //学生信息需要深度拷贝：逐个学生信息拷贝（每个学生的信息由Student类的拷贝构造函数完成)
	for (int i = 0; i < count; i ++)
	{
		stus[i] = grade.stus[i];
	}
}

Grade::~Grade()
{

}

/**
如果班级已经满员，直接返回false;
否则将该学生添加到数组的尾部。
认为新增加的学生的学号不会重复！
*/
bool Grade::addStudent(Student stu)
{
	if (count >= maxSize)   //班级已经满员，不能再增加学生
		return false;

	stus[count] = stu;
	count ++;
	return true;
}


bool Grade::deleteStudent(string stuNo)
{
	int index = findStudent(stuNo);  //返回该学生在班级数组中的序号（不是学号中的序号），从0开始索引

	if (index == -1)   //该学生不存在
		return false;

	for (int i = index; i < count - 1; i ++)  //将该学生后面的学生信息依次前移1位
	{
		stus[i] = stus[i + 1];
	}
	count --;
	return true;
}

//查找该学生在班级数组中的位置，从0开始索引；若不存在，则返回－1
int Grade::findStudent(string stuNo)
{
	for (int i = 0; i < count; i ++)
	{
		string number = stus[i].getStudentNumber();
		
		if (number.compare(stuNo) == 0)
		{
			return i;
		}
	}

	return -1;
}

//计算某门课的平均分。course = 1：英语；course = 2：数学；course = 3：计算机。
double Grade::calCourseAverage(int course)
{
	double average = 0;
	for (int i = 0; i < count; i ++)
	{
		average += stus[i].getCourseScore(course);
	}
	return average / count;
	
}

//寻找总分（或平均分）最高的学生   
Student Grade::findMaxScoreStudent()
{
	Student stu;
	double maxScore = -1;

	for (int i = 0; i < count; i ++)  //寻找平均分最高的学生
	{
		if (maxScore < stus[i].everage())
		{
			stu = stus[i];
			maxScore = stu.everage();
		}
	}

	return stu;
}

int Grade::getCount()
{
	return count;
}

//返回由索引指定的学生对象的指针，索引从0开始; 不对索引值是否有效作判断
//如果直接返回对象，其实返回的只是与原对象值相同的另外一个对象；若对返回的对象进行修改，不会改变原对象！
Student* Grade::getStudent(int index)
{
	return &stus[index];
}

//英语不及格的人数
int Grade::CountEnglish() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(1)))Ret++;
	}
	return Ret;
}
//数学不及格的人数
int Grade::CountMath() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(2)))Ret++;
	}
	return Ret;
}
//计算机不及格的人数
int Grade::CountComputer() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(3)))Ret++;
	}
	return Ret;
}
//C++不及格的人数
int Grade::CountCpp() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(4)))Ret++;
	}
	return Ret;
}
//是否及格
bool Grade::Pass(int Score) {
	return Score >= 60;
}
