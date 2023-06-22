#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#define SQListData int 

//顺序表
typedef struct SequenceList
{
	int size;
	int capacity;
	SQListData* data;
}SQList;

//顺序表的初始化
void SequenceListInit(SQList* L);

//顺序表的摧毁
void SequenceListDestory(SQList* L);

//顺序表的长度
int SequenceListLenth(SQList* L);

//顺序表的pos位置插入
void SequenceListInsert(SQList* L, int pos, SQListData x);

//顺序表的尾插
void SequenceListPushBack(SQList* L, SQListData x);

//顺序表的头插
void SequenceListPushFront(SQList* L, SQListData x);

//顺序表的尾删
void SequenceListPopBack(SQList* L);

//顺序表的头删
void SequenceListPopFront(SQList* L);

//顺序表的pos位置删除
void SequenceListDelePos(SQList* L, int pos);

//顺序表的容量检查
void SequenceListCheckCapacity(SQList* L);

//顺序表的打印
void SequenceListPrint(SQList* L);

//顺序表的数据查找
void SequenceListFind(SQList* L, SQListData x);

//顺序表的某个值的个数
void SequenceListXCount(SQList* L, SQListData x);

//顺序表的逆置
void SequenceListReversion(SQList* L);