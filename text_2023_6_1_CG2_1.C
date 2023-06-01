#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	int begin = left;
	int end = right;
	while (left < right)
	{
		while (left<right&&arr[right] >= arr[keyi])
			right--;
		while (left<right&&arr[left] <= arr[keyi])
			left++;
		Swap(&arr[left], &arr[right]);
	}
	if(arr[keyi]>arr[right])
		Swap(&arr[keyi], &arr[right]);
	QuickSort(arr, begin, left-1);
	QuickSort(arr, left + 1, end);
}
int main()
{
	int size = 0;
	int* arr = NULL;
	int i = 0;
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int) * size);
	time(NULL);
	int j = 1;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
		j = j * (-1);
		arr[i] = arr[i] * j;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr,0,size-1);
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}