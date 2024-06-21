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

//�������캯������Ҫ��ȿ���
Grade::Grade(Grade &grade)
{
	maxSize = grade.maxSize;
	count = grade.count;
	stus = new Student[maxSize];    //ѧ����Ϣ��Ҫ��ȿ��������ѧ����Ϣ������ÿ��ѧ������Ϣ��Student��Ŀ������캯�����)
	for (int i = 0; i < count; i ++)
	{
		stus[i] = grade.stus[i];
	}
}

Grade::~Grade()
{

}

/**
����༶�Ѿ���Ա��ֱ�ӷ���false;
���򽫸�ѧ����ӵ������β����
��Ϊ�����ӵ�ѧ����ѧ�Ų����ظ���
*/
bool Grade::addStudent(Student stu)
{
	if (count >= maxSize)   //�༶�Ѿ���Ա������������ѧ��
		return false;

	stus[count] = stu;
	count ++;
	return true;
}


bool Grade::deleteStudent(string stuNo)
{
	int index = findStudent(stuNo);  //���ظ�ѧ���ڰ༶�����е���ţ�����ѧ���е���ţ�����0��ʼ����

	if (index == -1)   //��ѧ��������
		return false;

	for (int i = index; i < count - 1; i ++)  //����ѧ�������ѧ����Ϣ����ǰ��1λ
	{
		stus[i] = stus[i + 1];
	}
	count --;
	return true;
}

//���Ҹ�ѧ���ڰ༶�����е�λ�ã���0��ʼ�������������ڣ��򷵻أ�1
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

//����ĳ�ſε�ƽ���֡�course = 1��Ӣ�course = 2����ѧ��course = 3���������
double Grade::calCourseAverage(int course)
{
	double average = 0;
	for (int i = 0; i < count; i ++)
	{
		average += stus[i].getCourseScore(course);
	}
	return average / count;
	
}

//Ѱ���ܷ֣���ƽ���֣���ߵ�ѧ��   
Student Grade::findMaxScoreStudent()
{
	Student stu;
	double maxScore = -1;

	for (int i = 0; i < count; i ++)  //Ѱ��ƽ������ߵ�ѧ��
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

//����������ָ����ѧ�������ָ�룬������0��ʼ; ��������ֵ�Ƿ���Ч���ж�
//���ֱ�ӷ��ض�����ʵ���ص�ֻ����ԭ����ֵ��ͬ������һ���������Է��صĶ�������޸ģ�����ı�ԭ����
Student* Grade::getStudent(int index)
{
	return &stus[index];
}

//Ӣ�ﲻ���������
int Grade::CountEnglish() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(1)))Ret++;
	}
	return Ret;
}
//��ѧ�����������
int Grade::CountMath() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(2)))Ret++;
	}
	return Ret;
}
//����������������
int Grade::CountComputer() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(3)))Ret++;
	}
	return Ret;
}
//C++�����������
int Grade::CountCpp() {
	int Ret = 0;
	for (int i = 0;i < count;i++) {
		if (!Pass(stus[i].getCourseScore(4)))Ret++;
	}
	return Ret;
}
//�Ƿ񼰸�
bool Grade::Pass(int Score) {
	return Score >= 60;
}
