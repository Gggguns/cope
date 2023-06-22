#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_22_test_1_2.h"
int main()
{
	LickList L;
	//初始化链表
	InitLickList(&L);
	//创建链表
	CreateLickList(&L);
	//打印链表
	PrintLickList(&L);
	//访问第i个节点
	srand(time(NULL));
	int i = rand()%10;
	printf("\n访问第%d个节点\n", i);
	Node* ret = GetNodeLickList(&L, i);
	if(ret)
		printf("第%d个节点的数据为%d\n",i, ret->data);
	printf("查找9和12\n");
	ret = FindNodeLickList(&L, 10);
	if (ret)
	{
		printf("找到了,在%p\n", ret);
	}
	else
	{
		printf("没找着\n");
	}
	if (ret=FindNodeLickList(&L, 12))
	{
		printf("找到了,在%p\n", ret);
	}
	else
	{
		printf("没找着\n");
	}

















	DestroyLickList(&L);
	return 0;
}