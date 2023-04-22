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

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);

// 单链表打印
void SListPrint(SListNode* plist);

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);

// 单链表的销毁
void SListDestroy(SListNode** plist);