#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_22_test_1_2.h"
int main()
{
	LickList L;
	//��ʼ������
	InitLickList(&L);
	//��������
	CreateLickList(&L);
	//��ӡ����
	PrintLickList(&L);
	//���ʵ�i���ڵ�
	srand(time(NULL));
	int i = rand()%10;
	printf("\n���ʵ�%d���ڵ�\n", i);
	Node* ret = GetNodeLickList(&L, i);
	if(ret)
		printf("��%d���ڵ������Ϊ%d\n",i, ret->data);
	printf("����9��12\n");
	ret = FindNodeLickList(&L, 10);
	if (ret)
	{
		printf("�ҵ���,��%p\n", ret);
	}
	else
	{
		printf("û����\n");
	}
	if (ret=FindNodeLickList(&L, 12))
	{
		printf("�ҵ���,��%p\n", ret);
	}
	else
	{
		printf("û����\n");
	}

















	DestroyLickList(&L);
	return 0;
}