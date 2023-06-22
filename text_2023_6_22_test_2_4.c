#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef char SQSTDataType;

typedef struct Stack
{
	SQSTDataType* data;
	int size;
	int capacity;
}Stack;
//栈的初始化
void STInit(Stack* ST)
{
	assert(ST);
	SQSTDataType* ptr = (SQSTDataType*)malloc(sizeof(SQSTDataType) * 4);
	if (ptr)
	{
		ST->data = ptr;
		ST->size = 0;
		ST->capacity = 4;
	}
	else
	{
		perror("malloc fail");
		return;
	}
}

//栈的销毁
void STDestroy(Stack* ST)
{
	free(ST->data);
	ST->capacity = 0;
	ST->size = 0;
}

//检查容量
void STCheck(Stack* ST)
{
	assert(ST);
	if (ST->size == ST->capacity)
	{
		SQSTDataType* ptr = (SQSTDataType*)realloc(ST->data, sizeof(SQSTDataType) * ST->capacity * 2);
		if (ptr)
		{
			ST->data = ptr;
			ST->capacity = ST->capacity * 2;
		}
	}
}

//栈的压栈
void STPush(Stack* ST, SQSTDataType x)
{
	assert(ST);
	assert(ST->data);
	STCheck(ST);
	ST->data[ST->size] = x;
	ST->size++;
}

//栈的出栈
void STPop(Stack* ST)
{
	assert(ST);
	if (ST->size)
	{
		ST->size--;
	}
}

//栈的栈顶
SQSTDataType STTop(Stack* ST)
{
	assert(ST);
	assert(ST->size);
	return ST->data[ST->size - 1];
}



//栈的判空
bool STEmpty(Stack* ST)
{
	assert(ST);
	return ST->size == 0;
}
int main()
{
	char s[20] = { 0 };
	SQSTDataType x;
	scanf("%s", s);
	int mid = strlen(s) / 2;
	int i = 0;
	Stack ST;
	STInit(&ST);
	while (i < mid)
	{
		STPush(&ST, s[i]);
		i++;
	}
	if (strlen(s) % 2 == 0)
	{
		i = mid;
	}
	else
	{
		i = mid + 1;
	}
	int flat = 1;
	while (!STEmpty(&ST))
	{
		x=STTop(&ST);
		STPop(&ST);
		if (x != s[i])
		{
			flat = 0;
			break;
		}
		i++;
	}
	if (flat)
	{
		printf("该字符串为回文\n");
	}
	else
	{
		printf("该字符串不是回文\n");
	}
	STDestroy(&ST);
	return 0;
}