#define _CRT_SECURE_NO_WARNINGS
#include"test_5_1.h"
#define N 100
void Text()
{
	int arr[N] = { 0 };
	int i = 0;
	time(NULL);
	for (i = 0;i < N;i++)
	{
		arr[i] = rand() % 1000;
	}
	int ret;
	ret=SequenceSearch(arr, sizeof(arr) / sizeof(arr[0]), 500);
	printf("%d\n", ret);
	/*ret = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 500);
	printf("%d\n", ret);*/
}
int main()
{
	Text();
	return 0;
}