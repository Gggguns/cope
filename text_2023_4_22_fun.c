#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_4_22.h"
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* NewNode=(SListNode*)calloc(1, sizeof(SListNode));
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
		printf("%d ", cur->data);
		cur = cur->next;
	}
	//printf("NULL");
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode*ptr=BuySListNode(x);
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode*ptr=BuySListNode(x);
	if (ptr == NULL)
	{
		printf("ͷ��ʧ��\n");
	}
	else
	{
		ptr->next = *pplist;
		*pplist = ptr;
	}
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	SListNode* tail = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	else if (tail->next==NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	SListNode* frist = *pplist;
	if ((*pplist) == NULL)
		return;
	*pplist = (*pplist)->next;
	free(frist);
	frist = NULL;
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
		return NULL;
	else
	{
		while (plist)
		{
			if (plist->data == x)
				return plist;
			plist = plist->next;
		}
		return NULL;
	}
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* ret = NULL;
	ret=BuySListNode(x);
	if (ret == NULL)
		printf("����ʧ��\n");
	else
	{
		ret->next = pos->next;
		pos->next=ret;
	}
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	SListNode* After = NULL;
	if (!pos->next)
		return;
	After = pos->next->next;
	free(pos->next);
	pos->next = After;
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
		
	}
	des = NULL;
}

SListNode* Combine(SListNode* head1, SListNode* head2)
{
	SListNode* guard = (SListNode*)malloc(sizeof(SListNode));
	if (!guard)
	{
		perror("malloc fail");
		return NULL;
	}
	SListNode* tail = guard;
	SListNode* end1 = head1, * end2 = head2;

	while (end1 && end2)
	{
		while (end1 && end1->next && end1->next->data == end1->data)
		{
			SListNode* des = end1;
			end1 = end1->next;
			free(des);
		}
		while (end2 && end2->next && end2->next->data == end2->data)
		{
			SListNode* des = end2;
			end2 = end2->next;
			free(des);
		}
		if (end1->data < end2->data)
		{
			tail->next = end1;
			end1 = end1->next;
		}
		else if (end1->data == end2->data)
		{
			tail->next = end1;
			end1 = end1->next;
			SListNode* des = end2;
			end2 = end2->next;
			free(des);
		}
		else
		{
			tail->next = end2;
			end2 = end2->next;
		}
		tail = tail->next;

	}
	if (end2)
	{
		tail->next = end2;
	}
	if (end1)
	{
		tail->next = end1;
	}
	SListNode* head = guard->next;
	free(guard);
	return head;
}