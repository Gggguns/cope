#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int SQDataType;

typedef struct SquenceList
{
	SQDataType *data;
	int size;
	int capacity;
}SQList;

//˳����ʼ��
void Init_SquenceList(SQList*SQ);

//˳���Ĵݻ�
void Destory_SquenceList(SQList*SQ);

//˳���ĳ���
int Size_SquenceList(SQList*SQ);

//˳���Ĳ���
int Search_SquenceList(SQList*SQ);

//˳�����������
void CheckCapacity_SquenceList(SQList*SQ);

//˳���posλ�õĲ���
void Insert_SquenceList(SQList*SQ);

//˳���posλ�õ�ɾ��
void Dele_SquenceList(SQList*SQ);

//��ӡ˳���
void Print_SquenceList(SQList*SQ);

//˳����β��
void PushBack_SquenceList(SQList*SQ,SQDataType x);