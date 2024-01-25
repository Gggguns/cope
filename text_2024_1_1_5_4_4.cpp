#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

struct Is_Safe
{
	bool operator()(vector <int>& Empress, int EmpressPos,int Empressi)
	{
		if (Empressi >= Empress.size())
		{
			return false;
		}
		int i = 0;
		for (i = 0;i < Empressi;i++)
		{
			if (Empress[i] == EmpressPos)
			{
				return false;
			}
			if (Empress[i] - (Empressi - i) == EmpressPos || Empress[i] + (Empressi - i) == EmpressPos)
			{
				return false;
			}
		}
		
		return true;
	}
};

int chessboard(vector <int> Empress,int Empressi)
{
	if (Empressi == Empress.size())
	{
		for (auto e : Empress)
		{
			cout << e << ' ';
		}
		cout << endl;
		return 1;
	}
	int i = 0;
	int Sum = 0;
	for (i = 0;i < Empress.size();i++)
	{
		Is_Safe S;
		if (S(Empress, i + 1, Empressi))
		{
			Empress[Empressi] = i + 1;
			Sum += chessboard(Empress,  Empressi+1);
		}
		
	}
	return Sum;
}
int main()
{
	
	int n = 0;
	cin >> n;
	vector <int> Empress(n,1);
	int Sum = 0;
	for(int i=0;i<n;i++)
	{
		Empress[0] = i+1;
		Sum += chessboard(Empress, 1);
	}
	cout << "Total=" << Sum << endl;
	return 0;
}