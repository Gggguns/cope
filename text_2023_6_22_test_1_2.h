#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
typedef int LKListData;

//节点
typedef struct Node
{
	LKListData data;
	struct Node* next;
}Node;

typedef struct LickList
{
	int size;
	Node guardhead;
	Node*tail;

}LickList;

//买节点
Node* BuyNode(LKListData x);

//初始化链表
void InitLickList(LickList* L);

//摧毁链表
void DestroyLickList(LickList* L);

//创建链表
void CreateLickList(LickList* L);

//输出链表
void PrintLickList(LickList* L);

//删除第i个节点
void DeleNodeLickList(LickList* L, int i);

//插入一个节点在第i个节点前
void InsertLickList(LickList* L, int i, LKListData x);

//尾插某个节点
void PushBackLickList(LickList* L, LKListData x);

//按位置获取第i个节点信息
Node* GetNodeLickList(LickList* L, int i);

//按值查找数据位置
Node* FindNodeLickList(LickList* L, LKListData x);

