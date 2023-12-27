#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0, s = 0;
	cin >> n >> s;
	vector<int> Nv;
	Nv.resize(n);
	int i = 0;
	int Sum = 0;
	for (i = 0;i < n;i++)
	{
		cin >> Nv[i];
		Sum += Nv[i];
	}
	sort(Nv.begin(), Nv.end(),greater<int>());
	double WaitTime = 0;
	vector<int> Sv(Nv.end()-s, Nv.end());
	for (i = 0;i < s;i++)
	{
		Nv.pop_back();
	}
	while (Nv.size())
	{
		WaitTime += Sv.back()*Nv.size();
		for (auto& e : Sv)
		{
			e -= Sv.back();
		}
		Sv[Sv.size() - 1] = Nv.back();
		Nv.pop_back();
		sort(Sv.begin(), Sv.end(),greater<int>());
	}
	printf("%.3llf\n", (WaitTime + Sum) / n);
	int x = 0;
	return 0;
}
