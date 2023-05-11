#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define VERTEX_MAX_NUM 20
typedef enum { DG, DN, UDG, UDN } GraphKind;

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

