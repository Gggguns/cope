#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n = 0, k = 0;
	vector<int> v;
	vector<int> Rs;
	while (cin >> n >> k)
	{
		v.resize(n, 0);
		int i = 0;
		for (i = 0;i < n;i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		Rs.push_back(v[k - 1]);
	}
	
	for (auto e : Rs)
	{
		cout << e << endl;
	}
	return 0;
}