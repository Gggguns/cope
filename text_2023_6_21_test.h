#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#define SQListData int 

//˳���
typedef struct SequenceList
{
	int size;
	int capacity;
	SQListData* data;
}SQList;

//˳���ĳ�ʼ��
void SequenceListInit(SQList* L);

//˳���Ĵݻ�
void SequenceListDestory(SQList* L);

//˳���ĳ���
int SequenceListLenth(SQList* L);

//˳����posλ�ò���
void SequenceListInsert(SQList* L, int pos, SQListData x);

//˳����β��
void SequenceListPushBack(SQList* L, SQListData x);

//˳����ͷ��
void SequenceListPushFront(SQList* L, SQListData x);

//˳����βɾ
void SequenceListPopBack(SQList* L);

//˳����ͷɾ
void SequenceListPopFront(SQList* L);

//˳����posλ��ɾ��
void SequenceListDelePos(SQList* L, int pos);

//˳�����������
void SequenceListCheckCapacity(SQList* L);

//˳���Ĵ�ӡ
void SequenceListPrint(SQList* L);

//˳�������ݲ���
void SequenceListFind(SQList* L, SQListData x);

//˳����ĳ��ֵ�ĸ���
void SequenceListXCount(SQList* L, SQListData x);

//˳��������
void SequenceListReversion(SQList* L);