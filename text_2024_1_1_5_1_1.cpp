#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count = 0;

// �ж��Ƿ�Ϊ����
int estimate(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return -1;
        }
    }
    return 1;
}

// �ݹ��������ӷֽ�
void search(int m) {
    for (int i = 2; i < m; i++) 
    {
        if (m % i == 0) 
        { 
            // �ҵ�һ������i����¼
            Count++; 
            if (estimate(m / i) == -1) 
            { 
                // ���m/i��������
                search(m / i); 
            }
        }
    }
}

int main() {
    int n;
    while (std::cin >> n) 
    {
        // ��������
        search(n); 
        // ������
        cout << Count + 1 << endl; 
        // ��ռ�����
        Count = 0; 
    }
    return 0;
}