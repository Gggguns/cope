#define _CRT_SECURE_NO_WARNINGS
#include"test_4_1.h"
int main()
{
	AdjList Graph;
	CreateAdjList(&Graph);
	//������ȱ���
	printf("������ȱ���\n");
	DFSTraverAL(&Graph);

	//������ȱ���
	printf("������ȱ���\n");
	BFSTraverseAL(&Graph);
	DestroyAdjList(&Graph);
	return 0;
}