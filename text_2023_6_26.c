#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_26.h"
int main()
{
	int arr[7] = { 5,6,3,2,4,1,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	return 0;
}