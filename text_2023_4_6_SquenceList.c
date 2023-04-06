#include"text_2023_4_6_SquenceList.h"

//˳����ʼ��
void Init_SquenceList(SQList*SQ)
{
	SQDataType*ptr=(SQDataType*)malloc(sizeof(SQDataType)*4);
	if(ptr)
	{
		SQ->data=ptr;
		SQ->size=0;
		SQ->capacity=4;
	}
	else
	{
		perror("malloc fail");
		return;
	}
}

//˳���Ĵݻ�
void Destory_SquenceList(SQList*SQ)
{
	free(SQ->data);
	SQ->size=0;
	SQ->capacity=0;
}

//˳���ĳ���
int Size_SquenceList(SQList*SQ)
{
	return SQ->size;
}

//˳���Ĳ���
int Search_SquenceList(SQList*SQ,SQDataType x)
{
	int i=0;
	for(i=0;i<SQ->size;i++)
	{
		if(SQ->data[i]==x)
			return i;
	}
	return -1;
}

//˳�����������
void CheckCapacity_SquenceList(SQList*SQ)
{
	if(SQ->size==SQ->capacity)
	{
		SQDataType*ptr=(SQDataType*)realloc(SQ->data,sizeof(SQDataType)*SQ->capacity*2);
		if(ptr)
		{
			SQ->data=ptr;
			SQ->capacity=SQ->capacity*2;
		}
		else
		{
			perror("realloc fail");
			return;
		}
	}
	else
		return;
}

//˳���posλ�õĲ���
void InsertPos_SquenceList(SQList*SQ,int pos,SQDataType x)
{
	CheckCapacity_SquenceList(SQ);
	int i=0;
	for(i=SQ->size;pos<i;i--)
	{
		SQ->data[i]=SQ->data[i-1];
	}
	SQ->data[pos]=x;
}

//˳���posλ�õ�ɾ��
void DelePos_SquenceList(SQList*SQ,int pos)
{
	int i=0;
	for(i=pos;i<SQ->size-1;i++)
	{
		SQ->data[i]=SQ->data[i+1];
	}
}

//��ӡ˳���
void Print_SquenceList(SQList*SQ)
{
	int i=0;
	for(i=0;i<SQ->size;i++)
	{
		printf("%d ",SQ->data[i]);
	}
}

//˳����β��
void PushBack_SquenceList(SQList*SQ,SQDataType x)
{
	SQ->data[SQ->size]=x;
	SQ->size++;
}