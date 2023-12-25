#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define Half 0.5

int main()
{
	string str;
	getline(cin, str);
	vector<int> v;
	v.resize(26,0);
	//统计字符数量
	float count = 0;
	for (auto e : str)
	{
		//小写字母统计
		if ('a' <= e && e <= 'z')
		{
			v[e - 'a']++;
			count++;
			continue;
		}
		//大写字母统计
		if ('A' <= e && e <= 'Z')
		{
			v[e - 'A']++;
			count++;
			continue;
		}
	}
	//输出结果
	char ch = 'A';
	for (auto e : v)
	{
		if(e!=0)
		{
			float Res = (float)e / count*100;
			cout << ch <<": " << e << ' ';
			printf("%.1lf", Res);
			cout << '%' << ' ';
			//条形图
			int i = 1;
			for (i = 1;i < Res + Half;i++)
			{
				cout << '*';
			}
			cout << endl;
		}
		ch++;
	}
	return 0;
}