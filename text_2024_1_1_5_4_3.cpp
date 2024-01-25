#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<list>
#include<bitset>
#include<vector>
using namespace std;
struct Node
{
	Node(int Num = 0, Node* Next = nullptr)
		:_Num(Num)
		,_Next(Next)
	{}
	int _Num;
	Node* _Next;
};
struct Piont
{
	int _x = 0;
	int _y = 0;
};
class Travel
{
public:
	void Input()
	{
		int n = 0;
		cin >> n;
		_v.resize(n);
		int i = 0;
		Piont p;
		for (i = 0;i < n - 1;i++)
		{
			cin >> p._x >> p._y;
			_v[p._x - 1].push_back(p._y - 1);
			_v[p._y - 1].push_back(p._x - 1);
		}
	}
	void Output()
	{
		int Max = 0;
		int i = 0;
		for (i = 0;i < _v.size();i++)
		{
			vector<int> Bitset(_v.size(), 0);
			Max = max(Max, DFS(_v, i, 1, Bitset));
		}
		cout << Max;
	}
	int DFS(vector<list<int>>& v, int start, int Sum, vector<int> Bitset)
	{
		if (Bitset[start] == 1)
		{
			return Sum - 1;
		}


		for (auto e : v[start])
		{
			Bitset[start] = 1;
			Sum = max(Sum, DFS(v, e, Sum + 1, Bitset));
		}
		return Sum;
	}
private:
	vector<list<int>> _v;
};

int main()
{

	Travel T;
	T.Input();
	T.Output();
	return 0;
}