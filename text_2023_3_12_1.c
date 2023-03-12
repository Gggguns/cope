#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
	int arr[N][N] = { 0 };
	int Time = N;
	int i = 0,j=0;
	for (i = 0;i < N ;i++)
	{
		arr[i][0] = 1;
		for (j = 0;j < i;j++)
		{
			arr[i][j + 1] = arr[i - 1][j] + arr[i - 1][j + 1];
		}
		arr[i][j] = 1;
	}
	while (Time--)
	{
		i = N - Time - 1;
		for (j = 0;j < N - Time;j++)
		{
			printf("%-1d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}