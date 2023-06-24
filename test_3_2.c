#define _CRT_SECURE_NO_WARNINGS
#include"test_3_2.h"
//创建哈夫曼树
HNode* HuFuManTreeCreate(int*arr,int size)
{
	int count = size * 2 - 1;
	HNode* ht = (HNode*)malloc(sizeof(HNode) * count);
	if (ht == NULL)
	{
		perror("HuFuManTreeCreate malloc fail");
		return NULL;
	}
	HNode* hu = ht;
	int i = 0;
	//初始化叶子节点
	for (i = 0;i < size;i++)
	{
		hu[i].weight = arr[i];
		hu[i].left = -1;
		hu[i].parent = -1;
		hu[i].right = -1;
	}
	//初始化分支节点
	for (i = size;i < count;i++)
	{
		hu[i].weight = 0;
		hu[i].left = hu[i].parent = hu[i].right = -1;
	}
	//构建哈夫曼树
	for (i = size;i < count;i++)
	{
		int Min1 = 1000, Min2 = 1000, Min1i = 0, Min2i = 0;
		int j = 0;
		for (j = 0;j < i;j++)
		{
			if (hu[j].parent == -1 && hu[j].weight < Min1)
			{
				Min2 = Min1;
				Min2i = Min1i;
				Min1 = hu[j].weight;
				Min1i = j;
			}
			else if (hu[j].parent == -1 && hu[j].weight < Min2)
			{
				Min2 = hu[j].weight;
				Min2i = j;
			}
		}
		hu[Min1i].parent = hu[Min2i].parent = i;
		hu[i].weight = Min1 + Min2;
		hu[i].left = Min1i;
		hu[i].right = Min2i;
	}
	return ht;
}

HCode** HuFuManCode(HNode* ht, int size)
{
	HCode** hc = (HCode**)malloc(sizeof(HCode*) * size);
	char* cp = (char*)malloc(sizeof(char) * size);
	cp[size - 1] = '\0';
	int child = 0;
	int parent = 0;
	int i = 0;
	for(i=0;i<size;i++)
	{
		int start = size - 1;
		for (child = i, parent = ht[i].parent;parent != -1;child = parent, parent = ht[parent].parent)
		{
			if (ht[parent].left == child)
				cp[--start] = '0';
			else
				cp[--start] = '1';
		}
		hc[i] = (char*)malloc(sizeof(char) * (size - start));
		strcpy(hc[i], &cp[start]);
	}
	free(cp);
	return hc;
}