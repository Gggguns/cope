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
	//ͳ���ַ�����
	float count = 0;
	for (auto e : str)
	{
		//Сд��ĸͳ��
		if ('a' <= e && e <= 'z')
		{
			v[e - 'a']++;
			count++;
			continue;
		}
		//��д��ĸͳ��
		if ('A' <= e && e <= 'Z')
		{
			v[e - 'A']++;
			count++;
			continue;
		}
	}
	//������
	char ch = 'A';
	for (auto e : v)
	{
		if(e!=0)
		{
			float Res = (float)e / count*100;
			cout << ch <<": " << e << ' ';
			printf("%.1lf", Res);
			cout << '%' << ' ';
			//����ͼ
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