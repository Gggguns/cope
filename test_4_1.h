#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define VERTEX_MAX_NUM 20
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef char VertexData;

//弧节点的数据类型
typedef int OtherInfo;

//弧节点
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//顶点的数据类型
typedef char VertexData;

//顶点节点
typedef struct VertexNode
{
	VertexData data;
	ArcNode* firstarc;
}VertexNode;

//邻接表的图
typedef struct AdjacencyListGraph
{
	VertexNode vertex[VERTEX_MAX_NUM];
	int vexnum;
	int arcnum;
	GraphKind kind;
}AdjList;


//创建图
void CreateAdjList(AdjList* graph);

//摧毁图
void DestroyAdjList(AdjList* graph);

//深度优先遍历的子程序
void DFSAL(AdjList* graph, int i,bool*visited);

//深度优先遍历
void DFSTraverAL(AdjList* graph);

//广度优先遍历的子程序
void BFSM(AdjList* graph, int k, bool* visited);

//广度优先遍历
void BFSTraverseAL(AdjList* graph);

//求某个顶点的度
int VertexDegree(AdjList* graph, int num);

//往图中插入一个顶点
void VertexPush(AdjList* graph);

//往图中插入一条边
void ArcPush(AdjList* graph);

//删去图中的某个顶点
void VertexDele(AdjList* graph);

//删去图中的某条边
void ArcDele(AdjList* graph);


//队列

typedef  int QueueDataType;
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

//队列初始化
void QueueInit(Queue* pq);

//队列的摧毁
void QueueDestroy(Queue* pq);

//队列的入列
void QueuePush(Queue* pq ,QueueDataType x);

//队列的出列
void QueuePop(Queue* pq);

//队列的长度
int QueueSize(Queue* pq);

//队列是否为空
bool QueueEmpty(Queue* pq);

//队列列首元素
QueueDataType QueueFront(Queue* pq);

//队列的列尾元素
QueueDataType QueueBack(Queue* pq);
