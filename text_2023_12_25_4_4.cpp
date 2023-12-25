#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	long long Num1 = 0, Num2 = 0;
	cin >> Num1 >> Num2;
	if (Num1 < 0)
	{
		Num1 = Num1 * (-1);
	}
	if (Num2 < 0)
	{
		Num2 = Num2 * (-1);
	}
	
	//将Num1确定为最大的数
	if (Num2 > Num1)
	{
		swap(Num2, Num1);
	}
	long long x = Num1, y = Num2;
	//求最小公倍数
	while (Num2)
	{
		long long R = Num1 % Num2;
		Num1 = Num2;
		Num2 = R;
	}
	printf("%lld",x*y/Num1);
	return 0;
}