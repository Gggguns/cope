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
	/*printf("依次尾插1,2\n");
	SequenceListPushBack(&L, 1);
	SequenceListPushBack(&L, 2);
	SequenceListPrint(&L);
	printf("依次头插66，9\n");
	SequenceListPushFront(&L, 66);
	SequenceListPushFront(&L, 9);
	SequenceListPrint(&L);
	printf("头删\n");
	SequenceListPopFront(&L);
	SequenceListPrint(&L);
	printf("尾删\n");
	SequenceListPopBack(&L);
	SequenceListPrint(&L);
	printf("查找1\n");
	SequenceListFind(&L, 1);
	printf("查找0\n");
	SequenceListFind(&L, 0);
	printf("数组下标1位置的插入\n");
	SequenceListInsert(&L, 1, 999);
	SequenceListPrint(&L);
	printf("数组下标1位置的删除\n");
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
	printf("逆置前：\n");
	SequenceListPrint(&L);
	SequenceListReversion(&L);
	printf("逆置后：\n");
	SequenceListPrint(&L);

	SequenceListPushBack(&L, 6);
	printf("逆置前：\n");
	SequenceListPrint(&L);
	SequenceListReversion(&L);
	printf("逆置后：\n");
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
	printf("顺序表的长度为%d\n", SequenceListLenth(&L));
	SQListData ran = rand() % 100;
	printf("将新产生的随机数%d插入数组下标为10的位置\n",ran);
	SequenceListInsert(&L, 10, ran);
	SequenceListPrint(&L);
	qsort(L.data, L.size, sizeof(L.data[0]), cmp);
	SequenceListPrint(&L);





























	SequenceListDestory(&L);
	return 0;
}