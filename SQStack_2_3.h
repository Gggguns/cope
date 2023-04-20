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

//栈初始化
void STInit(Stack* ST);

//栈的销毁
void STDestroy(Stack* ST);

//栈的压栈
void STPush(Stack* ST, SQSTDataType x);

//栈的出栈
void STPop(Stack* ST);

//栈的栈顶
SQSTDataType STTop(Stack* ST);

//检查容量
void STCheck(Stack* ST);

//栈的判空
bool STEmpty(Stack* ST);

//栈的判满
bool STFull(Stack* ST);

//栈的长度
int STLength(Stack* ST);
