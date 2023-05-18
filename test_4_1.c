#define _CRT_SECURE_NO_WARNINGS
#include"test_4_1.h"

//����ͼ
void CreateAdjList(AdjList* graph)
{
	int i, j, k;
	ArcNode* arcnode = NULL;
	printf("�����붥�����ͱ������Կո���Ϊ�������:\n");
	scanf("%d%d", &graph->vexnum, &graph->arcnum);
	printf("�����붥�����Ϣ�������ʽΪ��<�س�>����ţ�:");
	for (i = 0;i < graph->vexnum;i++)
	{
		scanf("\n%c", &(graph->vertex[i].data));
		graph->vertex[i].firstarc = NULL;
	}
	printf("�����뻡����Ϣ����ʽΪ��3��3����:\n");
	for (k = 0;k < graph->arcnum;k++)
	{
		
		scanf("%d,%d", &i, &j);
		arcnode = (ArcNode*)malloc(sizeof(ArcNode));
		if (arcnode == NULL)
			break;
		arcnode->adjvex = j;
		arcnode->nextarc = graph->vertex[i].firstarc;
		graph->vertex[i].firstarc = arcnode;
	}
}

//����ͼ
void DestroyAdjList(AdjList* graph)
{
	int i = 0;
	ArcNode* cur;
	ArcNode* next;
	for (i = 0;i < graph->vexnum;i++)
	{
		cur = graph->vertex[i].firstarc;
		while (cur)
		{
			next = cur->nextarc;
			free(cur);
			cur = next;
		}
	}
}

//������ȱ������ӳ���
void DFSAL(AdjList* graph, int i,bool*visited)
{
	ArcNode* node;
	
	printf("visit vertex:V%c\n", graph->vertex[i].data);//���ʽڵ�v

	visited[i] = true;//����ѷ���v

	node = graph->vertex[i].firstarc;//ȡv�߱��ͷָ��

	while (node)//��������v���ڽӵ�
	{
		if (!visited[node->adjvex])
		{
			DFSAL(graph, node->adjvex,visited);//��vδ���ʣ�����vΪ����������������
		}
		node = node->nextarc;//����һ���ڽӵ�
	}
}

//������ȱ���
void DFSTraverAL(AdjList* graph)
{
	int i;
	static bool visited[VERTEX_MAX_NUM];
	for (i = 0;i < graph->vexnum;i++)
	{
		visited[i] = false;//��־������ʼ��
	}
	for (i = 0;i < graph->vexnum;i++)
	{
		if (!visited[i])
			DFSAL(graph, i, visited);
	}
}

//������ȱ������ӳ���
void BFSM(AdjList* graph,int k,bool*visited)
{
	int i, j;
	ArcNode* node;
	Queue QU;
	QueueInit(&QU);
	QueuePush(&QU, k);//v����
	while (!QueueEmpty(&QU))
	{
		i = QueueFront(&QU);
		QueuePop(&QU);
		if (!visited[i])
		{
			printf("visit vertex:V%c\n", graph->vertex[i].data);//���ʽڵ�v
			visited[i] = true;
			node = graph->vertex[i].firstarc;
		}
		else
			node = NULL;
		while (node)
		{
			if(!visited[node->adjvex])
				QueuePush(&QU, node->adjvex);
			node = node->nextarc;
		}
		
	}
	QueueDestroy(&QU);
}

//������ȱ���
void BFSTraverseAL(AdjList* graph)
{
	int i;
	static bool visited[VERTEX_MAX_NUM];
	for (i = 0;i < graph->vexnum;i++)
	{
		visited[i] = false;
	}
	for (i = 0;i < graph->vexnum;i++)
	{
		if (!visited[i])
			BFSM(graph, i, visited);
	}
}


//����



//���еĳ�ʼ��
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
	QNode* cur;
	cur = pq->head;
	while (cur)
	{
		pq->head = pq->head->next;
		free(cur);
		cur = pq->head;
	}
	cur = NULL;
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//���е�����
void QueuePush(Queue* pq, QueueDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (QueueEmpty(pq))
		pq->head = pq->tail = newnode;
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

//���еĳ���
void QueuePop(Queue* pq)
{
	QNode* cur;
	cur = pq->head;
	if (!QueueEmpty(pq))
	{
		pq->head = pq->head->next;
		free(cur);
		pq->size--;
	}
}

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}

//���еĳ���
int QueueSize(Queue* pq)
{
	return pq->size;
}

//���е�����Ԫ��
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
	assert(pq->head);
	return pq->tail->data;
}