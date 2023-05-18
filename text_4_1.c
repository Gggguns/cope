#define _CRT_SECURE_NO_WARNINGS
#include"test_4_1.h"
int main()
{
	AdjList Graph;
	CreateAdjList(&Graph);
	//深度优先遍历
	printf("深度优先遍历\n");
	DFSTraverAL(&Graph);

	//广度优先遍历
	printf("广度优先遍历\n");
	BFSTraverseAL(&Graph);
	DestroyAdjList(&Graph);
	return 0;
}