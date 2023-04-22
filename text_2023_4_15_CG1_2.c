#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[1000] = { 0 };
	int i = 0, j = 0;
	char ch;
	do
	{
		scanf("%d",&arr[i++]);
		ch=getchar();

	} while (ch == ',');
	int oddi = 0, eveni = 0,tmp=0;
	for (oddi = 0, eveni = 0;eveni < i;)
	{
			
		while (oddi < eveni && arr[oddi] % 2 != 0)
			oddi++;
		if(arr[eveni]%2!=0)
		{
			tmp = arr[eveni];
			for (j = eveni;oddi < j;j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[oddi] = tmp;
		}
		eveni++;
	}
	for (j = 0;j < i;j++)
	{
		printf("%d", arr[j]);
		if (j < i - 1)
			printf(",");
	}
	return 0;
}