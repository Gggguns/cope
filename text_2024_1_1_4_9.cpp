#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
typedef long long LL;

inline LL Abs(LL x) { return x < 0 ? -x : x; }
// 计算两个向量的最大公约数
LL Gcd(LL a, LL b) { return b ? Gcd(b, a % b) : a; }

// 定义向量结构体
struct Vec {
	LL x, y;
	Vec() { x = y = 0; }
	Vec(LL _x, LL _y) { x = _x, y = _y; }
};

// 操作符重载
 bool operator < (Vec a, Vec b) 
 { 
	 return a.x == b.x ? a.y < b.y : a.x < b.x; 
 }
 Vec operator + (Vec a, Vec b) 
 { 
	 return Vec(a.x + b.x, a.y + b.y); 
 }
 Vec operator - (Vec a, Vec b) 
 {
	 return Vec(a.x - b.x, a.y - b.y);
 }
 Vec operator * (LL a, Vec b) 
 { 
	 return Vec(a * b.x, a * b.y); 
 }
 LL operator * (Vec a, Vec b) 
 { 
	 return a.x * b.x + a.y * b.y; 
 }
 LL operator / (Vec a, Vec b) 
 { 
	 return a.x * b.y - a.y * b.x;
 }
 LL len(Vec a) { return a * a; }
 Vec Rotate(Vec a) 
 { 
	 return Vec(-a.y, a.x); 
 }

// 定义存储斜率和截距的数据结构
typedef std::pair<std::pair<LL, LL>, LL> plll;
const int MN = 1005, MS = 499505;

int N, Cnt;
Vec P[MN];
std::map<plll, int> Num;
std::vector<Vec> D[MS];
Vec S[MN * 2];
std::map<LL, int> Buk;
LL Ans;

// 计算ABC的值
inline void getABC(Vec A, Vec B, LL& a, LL& b, LL& c) {
	a = B.y - A.y, b = B.x - A.x, c = A / B;
	LL d = Gcd(Abs(a), Gcd(Abs(b), Abs(c)));
	a /= d, b /= d, c /= d;
	if (a < 0 || (a == 0 && b < 0)) a = -a, b = -b, c = -c;
}

int main() 
{
	// 输入点的个数
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		// 输入每个点的坐标
		cin >> P[i].x >> P[i].y;
	}
	// 枚举两个点，计算斜率，得到所有直线的斜率和截距
	for (int j = 2; j <= N; ++j)
	{
		for (int i = 1; i < j; ++i)
		{
			Vec A = P[i], B = P[j], C = A + B;
			Vec tA = C + Rotate(2 * A - C);
			Vec tB = C + Rotate(2 * B - C);
			LL a, b, c;
			getABC(tA, tB, a, b, c);
			int& val = Num[{ {a, b}, c}];
			if (!val) val = ++Cnt;
			D[val].push_back(C);
		}
	}
	for (int i = 1; i <= Cnt; ++i) 
	{
		sort(D[i].begin(), D[i].end());
	}
	for (int u = 1; u <= N; ++u) 
	{
		int M = 0;
		for (int i = 1; i <= N; ++i) 
		{
			if (i != u)
			{
				S[++M] = P[i] - P[u];
			}
		}
		sort(S + 1, S + M + 1, [&](Vec i, Vec j) {
		int zi = i.y > 0 || (i.y == 0 && i.x > 0);
		int zj = j.y > 0 || (j.y == 0 && j.x > 0);
		if (zi == zj) return i / j > 0;
		return zi < zj;
			});
		for (int i = 1; i <= M; ++i) 
		{
			S[M + i] = S[i];
		}
		LL Sum = 0;
		int lb = 1, rb = 0;
		Buk.clear();
		for (int i = 1; i <= M; ++i) 
		{
			while (rb < i + M - 1) 
			{
				Vec R = S[rb + 1];
				if (R * S[i] >= 0 && (R / S[i] > 0 || (R / S[i] == 0 && rb >= M))) break;
				Sum += Buk[len(R)]++;
				++rb;
			}
			while (lb <= i + M - 1) 
			{
				Vec R = S[lb];
				if (R * S[i] < 0 || (R / S[i] > 0 || (R / S[i] == 0 && lb > M))) break;
				Sum -= --Buk[len(R)];
				++lb;
			}
			Vec A = P[u], B = S[i] + P[u];
			if (B < A) 
			{
				swap(A, B);
			}
			LL a, b, c, Val = 0;
			getABC(2 * A, 2 * B, a, b, c);
			plll p = { {a, b}, c };
			if (Num.find(p) != Num.end()) 
			{
				auto V = D[Num[p]];
				Val = lower_bound(V.begin(), V.end(), 2 * B) - upper_bound(V.begin(), V.end(), 2 * A);
			}
			Ans += Sum * Val;
		}
	}
	cout << (Ans * 4);
	return 0;
}
