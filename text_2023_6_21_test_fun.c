#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_21_test.h"
//˳���ĳ�ʼ��
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

//˳���Ĵݻ�
void SequenceListDestory(SQList* L)
{
	assert(L && L->data);
	L->capacity = 0;
	L->size = 0;
	free(L->data);
	L->data = NULL;
}

//˳���ĳ���
int SequenceListLenth(SQList* L)
{
	assert(L);
	return L->size;
}

//˳����posλ�ò���
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

//˳����β��
void SequenceListPushBack(SQList* L, SQListData x)
{
	assert(L);
	assert(L->data);
	SequenceListCheckCapacity(L);
	L->data[L->size] = x;
	L->size++;
}

//˳����ͷ��
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

//˳����βɾ
void SequenceListPopBack(SQList* L)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("˳���������Ѿ�Ϊ��\n");
		return;
	}
	else
	{
		L->size--;
		return;
	}
}

//˳����ͷɾ
void SequenceListPopFront(SQList* L)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("˳���������Ѿ�Ϊ��\n");
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

//˳����posλ��ɾ��
void SequenceListDelePos(SQList* L, int pos)
{
	assert(L && L->data);
	if (L->size == 0)
	{
		printf("˳���������Ѿ�Ϊ��\n");
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

//˳���������������
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

//˳���Ĵ�ӡ
void SequenceListPrint(SQList* L)
{
	int i = 0;
	printf("˳���ǰ��������ݣ�\n");
	while (i < L->size)
	{
		printf("%02d ", L->data[i]);
		i++;
	}
	printf("\n");
	return;
}

//˳�������ݲ���
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
		printf("\n����Ϊ���������ݵ�����λ��,����%d��λ��\n",count);
	}
	else
	{
		printf("ûҪ�ҵ����ҵ�����\n");
	}

}

//˳����ĳ��ֵ�ĸ���
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
	printf("˳���������%d�ĸ���Ϊ%d\n", x, count);
}

//˳��������
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
