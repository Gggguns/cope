#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int Max = 0, Min = 0, Num = 0;
	int n = 0;
	cin >> n;
	cin >> Num;
	Max = Min = Num;
	int i = 0;
	for (i = 0;i < n-1;i++)
	{
		cin >> Num;
		//�����ֵ
		if (Max < Num)
		{
			Max = Num;
		}
		//����Сֵ
		if (Min > Num)
		{
			Min = Num;
		}
	}
	cout << "max=" << Max << "," << "min=" << Min << endl;
	return 0;
}