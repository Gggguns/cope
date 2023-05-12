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