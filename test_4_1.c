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