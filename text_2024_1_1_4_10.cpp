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
	bool Find(vector<string>& Res, vector<string>& Cmp)
	{
		bool Ret = false;
		bitset<11> B;
		//���ļ����ݽ������в���
		for (auto& ConEle : _v)
		{
			string str = ConEle;
			transform(str.begin(), str.end(),str.begin(), ::tolower);
			//��ǰ���ж�
			int i = 0;
			bool Flag = false;
			for (auto& e : Cmp)
			{
				if (str.find(e)!=string::npos)
				{
					B.set(i);
					Flag = true;
					if (Ret)
						break;
				}
				i++;
			}
			//��¼��ǰ�����ݲ��ҽ��
			if (Flag)
			{
				Res.push_back(str);
				if (B.count() == Cmp.size())
				{
					Ret = true;
				}
			}
		}
		return Ret;
	}

	
	string _name;
	vector<string> _v;
};

void Split(vector<string>& FindStr)
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
		FindStr.push_back(tmp);
		posi = pos+1;
	}
	string tmp(str.begin() + posi, str.end());
	FindStr.push_back(tmp);
}

//���
void OutPut(vector <vector< string >>& Res)
{
	int Sum = Res[0].size();
	cout << Sum << endl;
	if (Sum)
	{
		int i = 0;
		for (auto Name : Res[0])
		{
			i++;
			cout << Name << endl;
			for (auto& Contant : Res[i])
			{
				cout << Contant << endl;
			}
		}
	}
	else
	{
		cout << "No Found\n";
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
	vector<vector<string>> FindStrArr;
	FindStrArr.resize(M);
	for(i=0;i<M;i++)
	{
		//���
		Split(FindStrArr[i]);
	}
	
	
	for (i = 0;i < M;i++)
	{
		vector <vector< string >> EndRes(1, vector<string>());
		//����ÿ���ļ�
		for (auto& e : F)
		{
			vector<string> TempRes;
			if (e.Find(TempRes, FindStrArr[i]))
			{
				EndRes[0].push_back(e._name);
				EndRes.push_back(TempRes);
			}
		}
		OutPut(EndRes);
	}
	
	
	return 0;
}


