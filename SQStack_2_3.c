#include"SQStack.h"

//栈的初始化
void STInit(Stack* ST)
{
	assert(ST);
	SQSTDataType* ptr = (SQSTDataType*)malloc(sizeof(SQSTDataType)*4);
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
	return ST->data[ST->size-1];
}

//检查容量
void STCheck(Stack* ST)
{
	assert(ST);
	if (ST->size == ST->capacity)
	{
		SQSTDataType* ptr = (SQSTDataType*)realloc(ST->data,sizeof(SQSTDataType) * ST->capacity * 2);
		if (ptr)
		{
			ST->data = ptr;
			ST->capacity = ST->capacity * 2;
		}
	}
}

//栈的判空
bool STEmpty(Stack* ST)
{
	assert(ST);
	return ST->size == 0;
}

//栈的判满
bool STFull(Stack* ST)
{
	assert(ST);
	return ST->size == ST->capacity;
}

//栈的长度
int STLength(Stack* ST)
{
	assert(ST);
	return ST->size;
}