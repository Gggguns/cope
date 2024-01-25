#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10007;

int n, v; 
int w[maxn]; 
bool g[maxn][maxn]; 
int dp[maxn]; 
vector<int> ans; 

// 动态规划求解最优解
void Change() {
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= w[i]; --j) 
        {
            if (dp[j - w[i]] + w[i] >= dp[j]) 
            { 
                // 如果选择当前物品能够使背包价值更大
                dp[j] = dp[j - w[i]] + w[i]; // 更新背包在该容量下的最大价值
                g[i][j] = true; // 标记第 i 个物品被选择
            }
        }
    }

    int cnt = 0;
    // 如果背包无法达到要求容量，则输出 "No Solution"
    if (dp[v] != v) {
        cout << "No Solution" << endl;
    }
    else {
        // 从最后一个物品开始，依次判断该物品是否被选择
        for (int i = n, j = v; i >= 1 && j >= 0; --i) {
            if (g[i][j]) { // 如果第 i 个物品被选择，则将其存入 ans 数组
                ans.push_back(w[i]);
                j -= w[i]; // 背包容量减去选择的物品重量
            }
        }

        // 输出选择的物品
        for (int i = 0; i < ans.size(); ++i) {
            if (i == ans.size() - 1) {
                cout << ans[i] << endl;
            }
            else {
                cout << ans[i] << " ";
            }
        }
    }
}

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // 物品按重量从大到小排序
    sort(w + 1, w + n + 1, greater<int>());

    // 求解最优解并输出选择的物品
    Change();

    return 0;
}