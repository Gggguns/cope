#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count = 0;

// 判断是否为素数
int estimate(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return -1;
        }
    }
    return 1;
}

// 递归搜索因子分解
void search(int m) {
    for (int i = 2; i < m; i++) 
    {
        if (m % i == 0) 
        { 
            // 找到一个因子i并记录
            Count++; 
            if (estimate(m / i) == -1) 
            { 
                // 如果m/i不是素数
                search(m / i); 
            }
        }
    }
}

int main() {
    int n;
    while (std::cin >> n) 
    {
        // 搜索因子
        search(n); 
        // 输出结果
        cout << Count + 1 << endl; 
        // 清空计数器
        Count = 0; 
    }
    return 0;
}