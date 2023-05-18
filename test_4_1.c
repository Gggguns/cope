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
	int i=0, j=0;
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

//求某个顶点的度
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

//往图中插入一个顶点
void VertexPush(AdjList* graph)
{
	assert(graph);
	if (graph->vexnum == VERTEX_MAX_NUM)
	{
		printf("顶点数据存放达到上限\n");
		return;
	}
	printf("请输入顶点的信息：");
	scanf("%c", &(graph->vertex[graph->vexnum].data));
	graph->vertex[graph->vexnum].firstarc = NULL;
	graph->vexnum++;

}

//往图中插入一条边
void ArcPush(AdjList* graph)
{
	printf("请输入增加弧的信息（格式为“3，3”）：");
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

//删去图中的某个顶点
void VertexDele(AdjList* graph)
{
	ArcNode* cur;
	ArcNode* next;
	printf("请输入要删除第几个节点：");
	int i = 0;
	scanf("%d", &i);
	if (i == 0)
	{
		printf("输入违法数据\n");
		return;
	}
	cur = graph->vertex[i - 1].firstarc;
	//释放顶点的弧
	while (cur)
	{
		next = cur->nextarc;
		free(cur);
		cur = next;
	}
	int j = 0;
	//调整删除顶点后的各顶点位置
	for (j = i - 1;j < graph->vexnum - 1;j++)
	{
		graph->vertex[j].data = graph->vertex[j + 1].data;
		graph->vertex[j].firstarc = graph->vertex[j].firstarc;
	}
	graph->vexnum--;
	//调整边的信息
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

//删去图中的某条边
void ArcDele(AdjList* graph)
{
	printf("请输入要删除弧的信息（格式为“3，3”）:\n");
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