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

//顺序表初始化
void Init_SquenceList(SQList*SQ);

//顺序表的摧毁
void Destory_SquenceList(SQList*SQ);

//顺序表的长度
int Size_SquenceList(SQList*SQ);

//顺序表的查找
int Search_SquenceList(SQList*SQ);

//顺序表的容量检查
void CheckCapacity_SquenceList(SQList*SQ);

//顺序表pos位置的插入
void Insert_SquenceList(SQList*SQ);

//顺序表pos位置的删除
void Dele_SquenceList(SQList*SQ);

//打印顺序表
void Print_SquenceList(SQList*SQ);

//顺序表的尾插
void PushBack_SquenceList(SQList*SQ,SQDataType x);