#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef int SQSTDataType;

typedef struct Stack
{
	SQSTDataType* data;
	int size;
	int capacity;
}Stack;

//ջ֡��ʼ��
void STInit(Stack* ST);

//ջ֡������
void STDestroy(Stack* ST);

//ջ֡��ѹջ
void STPush(Stack* ST, SQSTDataType x);

//ջ֡�ĳ�ջ
void STPop(Stack* ST);

//ջ֡��ջ��
SQSTDataType STTop(Stack* ST);

//�������
void STCheck(Stack* ST);

//ջ���п�
bool STEmpty(Stack* ST);

//ջ������
bool STFull(Stack* ST);

//ջ�ĳ���
int STLength(Stack* ST);
