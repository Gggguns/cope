#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_4_22_CG1_1.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* NewNode = (SListNode*)calloc(1, sizeof(SListNode));
	if (NewNode == NULL)
	{
		perror("calloc fail");
		return NewNode;
	}
	else
	{
		NewNode->data = x;
		NewNode->next = NULL;
		return NewNode;
	}
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("[num=%d,score=%d]\n", cur->data.num,cur->data.score);
		cur = cur->next;
	}
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* ptr = BuySListNode(x);
	SListNode* tail = *pplist;
	if (ptr == NULL)
		printf("β��ʧ��\n");
	else if (*pplist == NULL)
	{
		*pplist = ptr;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = ptr;
	}
}

// �����������
void SListDestroy(SListNode** pplist)
{
	SListNode* des = *pplist;
	SListNode* Judge = *pplist;
	*pplist = NULL;
	while (Judge)
	{
		des = Judge;
		Judge = Judge->next;
		free(des);
		des = NULL;
	}
}