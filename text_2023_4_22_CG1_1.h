#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int num;
	int score;
};

typedef struct student SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(SListNode* plist);

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);

// �����������
void SListDestroy(SListNode** plist);