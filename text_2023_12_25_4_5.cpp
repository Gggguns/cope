#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Student
{
	string _name;
	int _Fare=0;
	int _Num=0;
};

bool cmp(Student& s1 , Student& s2)
{
	if (s1._Fare > s2._Fare)
	{
		return true;
	}
	else if (s1._Fare < s2._Fare)
	{
		return false;
	}
	else
	{
		if (s1._name < s2._name)
		{
			return true;
		}
		else if (s1._name > s2._name)
		{
			return false;
		}
		else
		{
			if (s1._Num < s2._Num)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void Print(Student&s)
{
	cout << s._Num << ' ' << s._name << ' ' << s._Fare<<endl;
}
int main()
{
	vector<Student> v;
	int n = 0;
	cin >> n;
	int i = 0;
	for (i = 0;i < n;i++)
	{
		Student s;
		s._Num = i + 1;
		cin >> s._name;
		char ch;
		int Sum = 0;
		cin >> Sum;
		int Num = 0;
		for (ch = getchar();ch == ' ';ch = getchar())
		{
			cin >> Num;
			Sum += Num;
		}
		s._Fare = Sum;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	i = 1;
	int count=0;
	for (auto& e : v)
	{
		
		if(e._Fare != v[i]._Fare)
		{
			cout << count + 1 << ' ';
			i = count+1;
		}
		else
		{
			cout << i  << ' ';
		}
		Print(e);
		count++;
	}
	return 0;
}