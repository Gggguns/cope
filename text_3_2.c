#define _CRT_SECURE_NO_WARNINGS
#include"test_3_2.h"
int main()
{
	int arr[8] = { 15,3,14,12,6,9,24,17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HNode*ht=HuFuManTreeCreate(arr, size);
	HCode** hc = HuFuManCode(ht, size);
	int i = 0;
	for (i = 0;i < size;i++)
	{
		printf("%s\n", hc[i]);
	}
	for (i = 0;i < size;i++)
	{
		free(hc[i]);
	}
	free(hc);
	return 0;
}