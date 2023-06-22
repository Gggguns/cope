#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_21_test.h"
//顺序表的初始化
void SequenceListInit(SQList* L)
{
	assert(L);
	L->size = 0;
	L->data = (SQListData*)malloc(sizeof(SQListData) * 4);
	if (!L->data)
	{
		perror("Init malloc fail");
		return;
	}
	L->capacity = 4;
}

//顺序表的摧毁
void SequenceListDestory(SQList* L)
{
	assert(L && L->data);
	L->capacity = 0;
	L->size = 0;
	free(L->data);
	L->data = NULL;
}

//顺序表的长度
int SequenceListLenth(SQList* L)
{
	assert(L);
	return L->size;
}

//顺序表的pos位置插入
void SequenceListInsert(SQList* L, int pos, SQListData x)
{
	assert(L);
	assert(L->data);
	SequenceListCheckCapacity(L);
	int exchange = L->size;
	while (pos < exchange)
	{
		L->data[exchange] = L->data[exchange - 1];
		exchange--;
	}
	L->data[pos] = x;
	L->size++;
}

//顺序表的尾插
void SequenceListPushBack(SQList* L, SQListData x)
{
	assert(L);
	assert(L->data);
	SequenceListCheckCapacity(L);
	L->data[L->size] = x;
	L->size++;
}

//顺序表的头插
void SequenceListPushFront(SQList* L, SQListData x)
{
	assert(L);
	assert(L->data);
	SequenceListCheckCapacity(L);
	int exchange = L->size;
	while (exchange > 0)
	{
		L->data[exchange] = L->data[exchange - 1];
		exchange--;
	}
	L->data[0] = x;
	L->size++;
}

//顺序表的尾删
void SequenceListPopBack(SQList* L)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("顺序表的数据已经为空\n");
		return;
	}
	else
	{
		L->size--;
		return;
	}
}

//顺序表的头删
void SequenceListPopFront(SQList* L)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("顺序表的数据已经为空\n");
		return;
	}
	else
	{
		int exchange = 0;
		while (exchange < L->size - 1)
		{
			L->data[exchange] = L->data[exchange + 1];
			exchange++;
		}
		L->size--;
		return;
	}
}

//顺序表的pos位置删除
void SequenceListDelePos(SQList* L, int pos)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("顺序表的数据已经为空\n");
		return;
	}
	else
	{
		int exchange = pos;
		while (exchange < L->size - 1)
		{
			L->data[exchange] = L->data[exchange + 1];
			exchange++;
		}
		L->size--;
	}
}

//顺序表的容量检查扩容
void SequenceListCheckCapacity(SQList* L)
{
	assert(L && L->data);
	if (L->size == L->capacity)
	{
		SQListData* ptr = (SQListData*)realloc(L->data, sizeof(SQListData) * L->capacity * 2);
		if (!ptr)
		{
			perror("Capacity Realloc fail");
			return;
		}
		else
		{
			L->data = ptr;
			ptr = NULL;
			L->capacity *= 2;
		}
	}
}

//顺序表的打印
void SequenceListPrint(SQList* L)
{
	int i = 0;
	printf("顺序表当前储存的数据：\n");
	while (i < L->size)
	{
		printf("%02d ", L->data[i]);
		i++;
	}
	printf("\n");
	return;
}

//顺序表的数据查找
void SequenceListFind(SQList* L,SQListData x)
{
	assert(L && L->data);
	int i = 0;
	int count = 0;
	while (i < L->size)
	{
		if (L->data[i] == x)
		{
			count++;
			printf("%d ",i);
		}
		i++;
	}
	if (count != 0)
	{
		printf("\n以上为所查找数据的所在位置,共有%d个位置\n",count);
	}
	else
	{
		printf("没要找到查找的数据\n");
	}

}

//顺序表的某个值的个数
void SequenceListXCount(SQList* L, SQListData x)
{
	assert(L && L->data);
	int i = 0;
	int count = 0;
	while (i < L->size)
	{
		if (L->data[i] == x)
		{
			count++;
		}
		i++;
	}
	printf("顺序表中数据%d的个数为%d\n", x, count);
}

//顺序表的逆置
void SequenceListReversion(SQList* L)
{
	assert(L && L->data);
	int right = L->size - 1;
	int left = 0;
	while (left < right)
	{
		SQListData tmp = L->data[left];
		L->data[left] = L->data[right];
		L->data[right] = tmp;
		left++;
		right--;
	}
	return;
}
