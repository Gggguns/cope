#define _CRT_SECURE_NO_WARNINGS
#include"test_3_2.h"
int main()
{
	int arr[8] = { 5,29,7,8,14,23,3,11 };
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