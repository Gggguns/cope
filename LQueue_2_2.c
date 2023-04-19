#include"LQueue.h"


//���г�ʼ��
void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//���еĴݻ�
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

//���е�����
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

//���еĳ���
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

//���еĳ���
int QueueSize(Queue* pq)
{
	return pq->size;
}

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}

//��������Ԫ��
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//���е���βԪ��
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}