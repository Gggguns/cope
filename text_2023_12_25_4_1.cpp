#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int Fac(int n)
{
	if(n==0||n==1)
	{
		return 1;
	}
	return Fac(n - 1) * n;
}
int main()
{
	int n = 0;
	cin >> n;
	int Res=Fac(n);
	cout << Res;
	return 0;
}