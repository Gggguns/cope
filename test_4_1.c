#define _CRT_SECURE_NO_WARNINGS
#include"test_4_1.h"

//创建图
void CreateAdjList(AdjList* graph)
{
	int i, j, k;
	ArcNode* arcnode = NULL;
	printf("请输入顶点数和边数（以空格作为间隔符）:\n");
	scanf("%d%d", &graph->vexnum, &graph->arcnum);
	printf("请输入顶点的信息（输入格式为：<回车>顶点号）:");
	for (i = 0;i < graph->vexnum;i++)
	{
		scanf("\n%c", &(graph->vertex[i].data));
		graph->vertex[i].firstarc = NULL;
	}
	printf("请输入弧的信息（格式为“3，3”）:\n");
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

//销毁图
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

//深度优先遍历的子程序
void DFSAL(AdjList* graph, int i,bool*visited)
{
	ArcNode* node;
	
	printf("visit vertex:V%c\n", graph->vertex[i].data);//访问节点v

	visited[i] = true;//标记已访问v

	node = graph->vertex[i].firstarc;//取v边表的头指针

	while (node)//依次搜索v的邻接点
	{
		if (!visited[node->adjvex])
		{
			DFSAL(graph, node->adjvex,visited);//若v未访问，则以v为出发点向纵深搜索
		}
		node = node->nextarc;//找下一个邻接点
	}
}

//深度优先遍历
void DFSTraverAL(AdjList* graph)
{
	int i;
	static bool visited[VERTEX_MAX_NUM];
	for (i = 0;i < graph->vexnum;i++)
	{
		visited[i] = false;//标志向量初始化
	}
	for (i = 0;i < graph->vexnum;i++)
	{
		if (!visited[i])
			DFSAL(graph, i, visited);
	}
}

//广度优先遍历的子程序
void BFSM(AdjList* graph,int k,bool*visited)
{
	int i, j;
	ArcNode* node;
	Queue QU;
	QueueInit(&QU);
	QueuePush(&QU, k);//v入列
	while (!QueueEmpty(&QU))
	{
		i = QueueFront(&QU);
		QueuePop(&QU);
		if (!visited[i])
		{
			printf("visit vertex:V%c\n", graph->vertex[i].data);//访问节点v
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

//广度优先遍历
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


//队列



//队列的初始化
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

//队列的入列
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

//队列的出列
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

//队列是否为空
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}

//队列的长度
int QueueSize(Queue* pq)
{
	return pq->size;
}

//队列的列首元素
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
	assert(pq->head);
	return pq->tail->data;
}