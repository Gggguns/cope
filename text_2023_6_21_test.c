#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_21_test.h"
int cmp(const void* e1, const void* e2)
{
	return *(SQListData*)e1 - *(SQListData*)e2;
}
int main()
{
	SQList L;
	SequenceListInit(&L);
	/*printf("����β��1,2\n");
	SequenceListPushBack(&L, 1);
	SequenceListPushBack(&L, 2);
	SequenceListPrint(&L);
	printf("����ͷ��66��9\n");
	SequenceListPushFront(&L, 66);
	SequenceListPushFront(&L, 9);
	SequenceListPrint(&L);
	printf("ͷɾ\n");
	SequenceListPopFront(&L);
	SequenceListPrint(&L);
	printf("βɾ\n");
	SequenceListPopBack(&L);
	SequenceListPrint(&L);
	printf("����1\n");
	SequenceListFind(&L, 1);
	printf("����0\n");
	SequenceListFind(&L, 0);
	printf("�����±�1λ�õĲ���\n");
	SequenceListInsert(&L, 1, 999);
	SequenceListPrint(&L);
	printf("�����±�1λ�õ�ɾ��\n");
	SequenceListDelePos(&L, 1);
	SequenceListPrint(&L);*/

	/*SequenceListPushBack(&L, 1);
	SequenceListPushBack(&L, 2);
	SequenceListPushBack(&L, 1);
	SequenceListPushBack(&L, 8);
	SequenceListPushBack(&L, 3);
	SequenceListPushBack(&L, 2);
	SequenceListPrint(&L);
	SequenceListXCount(&L, 1);
	SequenceListXCount(&L, 100);
	SequenceListDestory(&L);*/

	/*SequenceListPushBack(&L, 1);
	SequenceListPushBack(&L, 2);
	SequenceListPushBack(&L, 3);
	SequenceListPushBack(&L, 4);
	SequenceListPushBack(&L, 5);
	printf("����ǰ��\n");
	SequenceListPrint(&L);
	SequenceListReversion(&L);
	printf("���ú�\n");
	SequenceListPrint(&L);

	SequenceListPushBack(&L, 6);
	printf("����ǰ��\n");
	SequenceListPrint(&L);
	SequenceListReversion(&L);
	printf("���ú�\n");
	SequenceListPrint(&L);*/


	srand(time(NULL));
	int i = 0;
	int arr[50] = { 0 };
	while (i < 50)
	{
		arr[i] = rand() % 100;
		i++;
	}
	i = 0;
	while (i < 50)
	{
		if (arr[i] % 2 == 0)
			SequenceListPushBack(&L, arr[i]);
		i++;
	}
	SequenceListPrint(&L);
	printf("˳���ĳ���Ϊ%d\n", SequenceListLenth(&L));
	SQListData ran = rand() % 100;
	printf("���²����������%d���������±�Ϊ10��λ��\n",ran);
	SequenceListInsert(&L, 10, ran);
	SequenceListPrint(&L);
	qsort(L.data, L.size, sizeof(L.data[0]), cmp);
	SequenceListPrint(&L);





























	SequenceListDestory(&L);
	return 0;
}