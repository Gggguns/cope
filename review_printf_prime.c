#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0, ret1 = 0, ret2 = 0,count1=0,count2=0;
	int prime1(int x);
	int prine2(int x);
	for ( i = 0;i < 10000;i++)
	{
		ret1=prime1(i);
		if (ret1 == 1)
			count1++;
		ret2=prime2(i);
		if (1 == ret2)
			count2++;
	}
	printf("count1=%d\n", count1);
	printf("count2=%d\n", count2);
}
int prime1(int x)
{
	int i = 0;
	if (x == 0)
		return 0;
	else if (x == 1 || x == 2 || x == 3)
		return 1;
	else
	{
		for (i = 2;i < x;i++)
		{
			if (x % i == 0)
				return 0;
		}
		return 1;
	}
}
int prime2(int x)
{
	int i = 0;
	if (x == 0)
		return 0;
	else if (x == 1 || x == 2 || x == 3)
		return 1;
	else
	{
		for (i = 2;i <= sqrt(x);i++)
		{
			if (x % i == 0)
				return 0;
		}
		return 1;
	}
}