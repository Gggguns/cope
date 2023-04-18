#include"LQueue.h"


//队列初始化
void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列的摧毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列的入列
void QueuePush(Queue* pq , QueueDataType x)
{
	assert(pq);
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node)
	{
		node->data = x;
		node->next = NULL;
	}
	else
	{
		perror("malloc fail");
		return;
	}
	if (!pq->head)
	{
		pq->head = pq->tail = node;
	}
	else
	{
		pq->tail->next = node;
		pq->tail = node;
	}
	pq->size++;
}

//队列的出列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	QNode* cur = pq->head;
	pq->head = pq->head->next;
	pq->size--;
	free(cur);
	cur = NULL;
}

//队列的长度
int QueueSize(Queue* pq)
{
	return pq->size;
}

//队列是否为空
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}

//队列列首元素
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//队列的列尾元素
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}