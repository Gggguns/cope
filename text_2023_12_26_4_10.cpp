#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<list>
#include<algorithm>
using namespace std;
struct File
{
	//����
	void InPut()
	{
		cin >> _name;
		string str;
		getline(cin, str);
		while (str == "")
		{
			getline(cin, str);
		}
		while (str != "#")
		{
			_v.push_back(str);
			getline(cin, str);
		}
	}
	//�ļ�����
	bool Find(list<string>& Res, vector<string>& Cmp)
	{
		bool flag = false;
		bitset<11> B;
		//���ļ����ݽ������в���
		for (auto& ConEle : _v)
		{
			string str = ConEle;
			transform(str.begin(), str.end(),str.begin(), ::tolower);
			//��ǰ���ж�
			int i = 0;
			for (auto& e : Cmp)
			{
				if (str.find(e)!=string::npos)
				{
					B.set(i);
					if (flag)
						break;
				}
				i++;
			}
			//��¼��ǰ�����ݲ��ҽ��
			if (B.count() > 0)
			{
				Res.push_back(str);
				if (B.count() == Cmp.size())
				{
					flag = true;
				}
			}
		}
		return flag;
	}

	
	string _name;
	vector<string> _v;
};

void Split(vector<string>& Cmp)
{
	size_t pos = 0;
	string str;
	getline(cin, str);
	while (str == "")
	{
		getline(cin, str);
	}
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	size_t posi = 0;
	for (pos = str.find(' ');pos != string::npos;pos = str.find(' ', pos + 1))
	{
		string tmp(str.begin() + posi, str.begin() + pos);
		Cmp.push_back(tmp);
		posi = pos+1;
	}
	string tmp(str.begin() + posi, str.end());
	Cmp.push_back(tmp);
}

//���
void OutPut(int Sum,vector<string>Res)
{
	cout << Sum << endl;
	if (Sum == 0)
	{
		cout << "No Found\n";
		return;
	}
	for (auto& e : Res)
	{
		cout << e << endl;
	}
}














int main()
{
	int n = 0;
	cin >> n;
	vector<File> F(n,File());
	//����
	int i = 0;
	for (i = 0;i < n;i++)
	{
		F[i].InPut();
	}
	
	//����
	int M = 0;
	cin >> M;
	for(i=0;i<M;i++)
	{
		int Sum = 0;
		
		vector<string> Cmp;

		//���
		Split(Cmp);
		list<string> EndRes;
		//����ÿ���ļ�
		for (auto& e : F)
		{
			list<string> TempRes;
			if (e.Find(TempRes, Cmp))
			{
				Sum++;
			}			
			
		}
		cout << Sum << endl;
	}
	
	return 0;
}





