#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BinaryTreeNode* QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//���г�ʼ��
void QueueInit(Queue* pq);

//���еĴݻ�
void QueueDestroy(Queue* pq);

//���е�����
void QueuePush(Queue* pq , QueueDataType x);

//���еĳ���
void QueuePop(Queue* pq);

//���еĳ���
int QueueSize(Queue* pq);

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//��������Ԫ��
QueueDataType QueueFront(Queue* pq);

//���е���βԪ��
QueueDataType QueueBack(Queue* pq);