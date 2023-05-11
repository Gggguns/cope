#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define VERTEX_MAX_NUM 20
typedef enum { DG, DN, UDG, UDN } GraphKind;

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

