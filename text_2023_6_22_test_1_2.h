#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
typedef int LKListData;

//�ڵ�
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

//��ڵ�
Node* BuyNode(LKListData x);

//��ʼ������
void InitLickList(LickList* L);

//�ݻ�����
void DestroyLickList(LickList* L);

//��������
void CreateLickList(LickList* L);

//�������
void PrintLickList(LickList* L);

//ɾ����i���ڵ�
void DeleNodeLickList(LickList* L, int i);

//����һ���ڵ��ڵ�i���ڵ�ǰ
void InsertLickList(LickList* L, int i, LKListData x);

//β��ĳ���ڵ�
void PushBackLickList(LickList* L, LKListData x);

//��λ�û�ȡ��i���ڵ���Ϣ
Node* GetNodeLickList(LickList* L, int i);

//��ֵ��������λ��
Node* FindNodeLickList(LickList* L, LKListData x);

