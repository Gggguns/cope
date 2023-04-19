#include"SQStack.h"

//Õ»Ö¡³õÊ¼»¯
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

//Õ»Ö¡µÄÏú»Ù
void STDestroy(Stack* ST)
{
	free(ST->data);
	ST->capacity = 0;
	ST->size = 0;
}

//Õ»Ö¡µÄÑ¹Õ»
void STPush(Stack* ST, SQSTDataType x)
{
	assert(ST);
	assert(ST->data);
	STCheck(ST);
	ST->data[ST->size] = x;
	ST->size++;
}

//Õ»Ö¡µÄ³öÕ»
void STPop(Stack* ST)
{
	assert(ST);
	if (ST->size)
	{
		ST->size--;
	}
}

//Õ»Ö¡µÄÕ»¶¥
SQSTDataType STTop(Stack* ST)
{
	assert(ST);
	assert(ST->size);
	return ST->data[ST->size-1];
}

//¼ì²éÈÝÁ¿
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

//Õ»µÄÅÐ¿Õ
bool STEmpty(Stack* ST)
{
	assert(ST);
	return ST->size == 0;
}

//Õ»µÄÅÐÂú
bool STFull(Stack* ST)
{
	assert(ST);
	return ST->size == ST->capacity;
}

//Õ»µÄ³¤¶È
int STLength(Stack* ST)
{
	assert(ST);
	return ST->size;
}