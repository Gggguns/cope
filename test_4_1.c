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
	int i=0, j=0;
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

//��ĳ������Ķ�
int VertexDegree(AdjList* graph, int num)
{
	int i = 0;
	ArcNode* node = NULL;
	if (num < VERTEX_MAX_NUM + 1)
		node = graph->vertex[num - 1].firstarc;
	while (node)
	{
		i++;
		node = node->nextarc;
	}
	return i;
}

//��ͼ�в���һ������
void VertexPush(AdjList* graph)
{
	assert(graph);
	if (graph->vexnum == VERTEX_MAX_NUM)
	{
		printf("�������ݴ�Ŵﵽ����\n");
		return;
	}
	printf("�����붥�����Ϣ��");
	scanf("%c", &(graph->vertex[graph->vexnum].data));
	graph->vertex[graph->vexnum].firstarc = NULL;
	graph->vexnum++;

}

//��ͼ�в���һ����
void ArcPush(AdjList* graph)
{
	printf("���������ӻ�����Ϣ����ʽΪ��3��3������");
	ArcNode* arcnode = NULL;
	int i,j;
	scanf("%d,%d", &i, &j);
	arcnode = (ArcNode*)malloc(sizeof(ArcNode));
	if (arcnode == NULL)
	{
		perror("ArcPush malloc fail");
		return;
	}
	arcnode->adjvex = j;
	arcnode->nextarc = graph->vertex[i].firstarc;
	graph->vertex[i].firstarc = arcnode;
}

//ɾȥͼ�е�ĳ������
void VertexDele(AdjList* graph)
{
	ArcNode* cur;
	ArcNode* next;
	printf("������Ҫɾ���ڼ����ڵ㣺");
	int i = 0;
	scanf("%d", &i);
	if (i == 0)
	{
		printf("����Υ������\n");
		return;
	}
	cur = graph->vertex[i - 1].firstarc;
	//�ͷŶ���Ļ�
	while (cur)
	{
		next = cur->nextarc;
		free(cur);
		cur = next;
	}
	int j = 0;
	//����ɾ�������ĸ�����λ��
	for (j = i - 1;j < graph->vexnum - 1;j++)
	{
		graph->vertex[j].data = graph->vertex[j + 1].data;
		graph->vertex[j].firstarc = graph->vertex[j].firstarc;
	}
	graph->vexnum--;
	//�����ߵ���Ϣ
	for (j = 0;j < graph->vexnum;j++);
	{
		if (graph->vertex[j].firstarc->adjvex == i - 1)
		{
			ArcNode* Des = graph->vertex[j].firstarc;
			graph->vertex[j].firstarc = Des->nextarc;
			free(Des);
		}
		cur = graph->vertex[j].firstarc;
		while (cur)
		{
			if (cur->adjvex > i - 1)
				cur->adjvex--;
			next = cur->nextarc;
			if (next->adjvex == i - 1)
			{
				cur->nextarc = next->nextarc;
				free(next);
				next = cur->nextarc;
			}
			cur = next;
		}
	}
}

//ɾȥͼ�е�ĳ����
void ArcDele(AdjList* graph)
{
	printf("������Ҫɾ��������Ϣ����ʽΪ��3��3����:\n");
	int i=0, j=0;
	scanf("%d,%d",&i,&j);
	ArcNode* cur = graph->vertex[i].firstarc;
	if (cur && cur->adjvex == j)
	{
		graph->vertex[i].firstarc = cur->nextarc;
		free(cur);
		cur = NULL;
		return;
	}
	while (cur)
	{
		ArcNode* next = cur->nextarc;
		if (next && next->adjvex == j)
		{
			cur->nextarc = next->nextarc;
			free(next);
			break;
		}
		cur = next;
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