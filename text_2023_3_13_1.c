#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num1 = 0, num2 = 0, a = 0, b = 0,r=0;
	scanf("%d%d", &num1, &num2);
	if (num1 < num2)
	{
		num1 = num1 ^ num2;
		num2 = num1 ^ num2;
		num1 = num1 ^ num2;
	}
	a = num1;b = num2;
	do
	{
		if (!b)
			break;
		r = a % b;
		a = b;
		b = r;
	} while (r);
	printf("最小公倍数=%d，最大公约数=%d\n", num1 * num2 / a, a);
	return 0;
}