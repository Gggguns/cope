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
		scanf("%c", &(graph->vertex[i].data));
		graph->vertex[i].firstarc = NULL;
	}
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