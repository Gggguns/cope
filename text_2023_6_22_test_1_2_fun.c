#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_22_test_1_2.h"

//买节点
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

//初始化链表
void InitLickList(LickList* L)
{
	assert(L);
	L->guardhead.next = NULL;
	L->size = 0;
	L->tail = &L->guardhead;
}

//摧毁链表
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

//创建链表
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

//输出链表
void PrintLickList(LickList* L)
{
	assert(L);
	printf("当前链表各节点的数据：\n");
	Node* cur = L->guardhead.next;
	while (cur)
	{
		Node* next = cur->next;
		printf("%d ", cur->data);
		cur = next;
	}
}

//删除第i个节点
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

//插入一个节点在第i个节点前
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

//尾插节点
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

//按位置获取第i个节点信息
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

//按值查找数据位置
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