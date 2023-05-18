#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define VERTEX_MAX_NUM 20
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef char VertexData;

//���ڵ����������
typedef int OtherInfo;

//���ڵ�
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//�������������
typedef char VertexData;

//����ڵ�
typedef struct VertexNode
{
	VertexData data;
	ArcNode* firstarc;
}VertexNode;

//�ڽӱ��ͼ
typedef struct AdjacencyListGraph
{
	VertexNode vertex[VERTEX_MAX_NUM];
	int vexnum;
	int arcnum;
	GraphKind kind;
}AdjList;


//����ͼ
void CreateAdjList(AdjList* graph);

//�ݻ�ͼ
void DestroyAdjList(AdjList* graph);

//������ȱ������ӳ���
void DFSAL(AdjList* graph, int i,bool*visited);

//������ȱ���
void DFSTraverAL(AdjList* graph);

//������ȱ������ӳ���
void BFSM(AdjList* graph, int k, bool* visited);

//������ȱ���
void BFSTraverseAL(AdjList* graph);

//��ĳ������Ķ�
int VertexDegree(AdjList* graph, int num);

//��ͼ�в���һ������
void VertexPush(AdjList* graph);

//��ͼ�в���һ����
void ArcPush(AdjList* graph);

//ɾȥͼ�е�ĳ������
void VertexDele(AdjList* graph);

//ɾȥͼ�е�ĳ����
void ArcDele(AdjList* graph);


//����

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

//���г�ʼ��
void QueueInit(Queue* pq);

//���еĴݻ�
void QueueDestroy(Queue* pq);

//���е�����
void QueuePush(Queue* pq ,QueueDataType x);

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
