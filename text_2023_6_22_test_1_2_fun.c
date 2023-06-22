#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_22_test_1_2.h"

//��ڵ�
Node* BuyNode(LKListData x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("BuyNode malloc fail");
		return NULL;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

//��ʼ������
void InitLickList(LickList* L)
{
	assert(L);
	L->guardhead.next = NULL;
	L->size = 0;
	L->tail = &L->guardhead;
}

//�ݻ�����
void DestroyLickList(LickList* L)
{
	assert(L);
	Node* cur = L->guardhead.next;
	while (cur)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	L->guardhead.next = NULL;
	L->size = 0;
	L->tail = NULL;
}

//��������
void CreateLickList(LickList* L)
{
	char ch;
	LKListData x;
	do
	{
		scanf("%d", &x);
		PushBackLickList(L, x);
		ch = getchar();
		
	} while (ch == ' ');
}

//�������
void PrintLickList(LickList* L)
{
	assert(L);
	printf("��ǰ������ڵ�����ݣ�\n");
	Node* cur = L->guardhead.next;
	while (cur)
	{
		Node* next = cur->next;
		printf("%d ", cur->data);
		cur = next;
	}
}

//ɾ����i���ڵ�
void DeleNodeLickList(LickList* L, int i)
{
	assert(L);
	int j = 0;
	Node* pre = &L->guardhead;
	Node* cur = pre->next;
	while (j <= i&&j<=L->size)
	{
		j++;
		pre = cur;
		cur = pre->next;
	}
	if (cur && i == j)
	{
		pre->next = cur->next;
		free(cur);
		cur = NULL;
	}
}

//����һ���ڵ��ڵ�i���ڵ�ǰ
void InsertLickList(LickList* L, int i, LKListData x)
{
	assert(L);
	int j = 0;
	Node* pre = &L->guardhead;
	Node* cur = pre->next;
	while (j <= i && j <= L->size)
	{
		j++;
		pre = cur;
		cur = pre->next;
	}
	Node* newnode = BuyNode(x);
	if (newnode)
	{
		if(i==j)
		{
			newnode->next = cur;
			pre->next = newnode;
		}
		if (j < i)
		{
			L->tail->next = newnode;
			L->tail = L->tail->next;
		}
	}
}

//β��ڵ�
void PushBackLickList(LickList* L, LKListData x)
{
	Node* newnode = BuyNode(x);
	if (newnode)
	{
		L->tail->next = newnode;
		L->tail = L->tail->next;
		L->size++;
	}
}

//��λ�û�ȡ��i���ڵ���Ϣ
Node* GetNodeLickList(LickList* L, int i)
{
	assert(L);
	int j = 1;
	Node* cur = L->guardhead.next;
	while (j < i && j <= L->size)
	{
		j++;
		cur = cur->next;
	}
	if (i == j)
		return cur;
	else
		return NULL;
}

//��ֵ��������λ��
Node* FindNodeLickList(LickList* L, LKListData x)
{
	assert(L);
	Node* cur = L->guardhead.next;
	while (cur)
	{
		Node* next = cur->next;
		if (cur->data == x)
			return cur;
		cur = next;
	}
	return NULL;
}