#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	float Median = 0;
	float Average = 0, Sum = 0;
	int i = 0;
	vector<float> v;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		int Num = 0;
		cin >> Num;
		v.push_back(Num);
		Sum += Num;
	}
	sort(v.begin(), v.end());
	Average = Sum / v.size();
	if (n % 2 == 0)
	{
		Median = (v[n / 2] + v[n / 2 - 1]) / 2;
	}
	else
	{
		Median = v[n / 2];
	}
	printf("meam=%.2lf median=%.1lf\n", Average, Median);
	return 0;
}