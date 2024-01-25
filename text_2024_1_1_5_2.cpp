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

// ��̬�滮������Ž�
void Change() {
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= w[i]; --j) 
        {
            if (dp[j - w[i]] + w[i] >= dp[j]) 
            { 
                // ���ѡ��ǰ��Ʒ�ܹ�ʹ������ֵ����
                dp[j] = dp[j - w[i]] + w[i]; // ���±����ڸ������µ�����ֵ
                g[i][j] = true; // ��ǵ� i ����Ʒ��ѡ��
            }
        }
    }

    int cnt = 0;
    // ��������޷��ﵽҪ������������� "No Solution"
    if (dp[v] != v) {
        cout << "No Solution" << endl;
    }
    else {
        // �����һ����Ʒ��ʼ�������жϸ���Ʒ�Ƿ�ѡ��
        for (int i = n, j = v; i >= 1 && j >= 0; --i) {
            if (g[i][j]) { // ����� i ����Ʒ��ѡ��������� ans ����
                ans.push_back(w[i]);
                j -= w[i]; // ����������ȥѡ�����Ʒ����
            }
        }

        // ���ѡ�����Ʒ
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

    // ��Ʒ�������Ӵ�С����
    sort(w + 1, w + n + 1, greater<int>());

    // ������ŽⲢ���ѡ�����Ʒ
    Change();

    return 0;
}