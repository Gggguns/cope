#include"SQStack.h"

//ջ֡��ʼ��
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

//ջ֡������
void STDestroy(Stack* ST)
{
	free(ST->data);
	ST->capacity = 0;
	ST->size = 0;
}

//ջ֡��ѹջ
void STPush(Stack* ST, SQSTDataType x)
{
	assert(ST);
	assert(ST->data);
	STCheck(ST);
	ST->data[ST->size] = x;
	ST->size++;
}

//ջ֡�ĳ�ջ
void STPop(Stack* ST)
{
	assert(ST);
	if (ST->size)
	{
		ST->size--;
	}
}

//ջ֡��ջ��
SQSTDataType STTop(Stack* ST)
{
	assert(ST);
	assert(ST->size);
	return ST->data[ST->size-1];
}

//�������
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

//ջ���п�
bool STEmpty(Stack* ST)
{
	assert(ST);
	return ST->size == 0;
}

//ջ������
bool STFull(Stack* ST)
{
	assert(ST);
	return ST->size == ST->capacity;
}

//ջ�ĳ���
int STLength(Stack* ST)
{
	assert(ST);
	return ST->size;
}