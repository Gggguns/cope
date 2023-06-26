#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_26.h"

//�����ӡ
void Print(int* arr, int size)
{
	assert(arr);
	int i = 0;
	for (i = 0;i < size;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ð������
void BubbleSort(int* arr, int size)
{
	int i = 0, j = 0;
	for (i = 0;i < size - 1;i++)
	{
		for (j = 0;j < size - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
		}
		printf("��%d������\n",i+1);
		Print(arr, size);
	}
}
