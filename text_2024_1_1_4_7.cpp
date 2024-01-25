#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct Baby
{
	Baby(int Num = 0)
		:_Num(Num)
	{}
	bool IsGenius(int k)
	{
		int Sum = 0;
		int Num = _Num;
		while (Num)
		{
			Sum += (Num % 10);
			Num /= 10;
		}
		int Res = _Num - Sum;
		return  Res >= k;
	}
	int _Num = 0;
};
int main()
{
	int n = 0, k = 0;
	int i = 0;
	int Num = 0, Sum = 0;
	cin >> n >> k;
	for (i = 1;i < n + 1;i++)
	{
		Baby B(i);
		if (B.IsGenius(k))
		{
			Sum++;
		}
	}

	cout << Sum;
	return 0;
}