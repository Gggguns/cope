#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, m, q;
int A[1110][1110], x[10], y[10], c[10];
//交换两个变量的数
void swap(int* p1, int* p2)
{
    *p1 = (*p1) ^ (*p2);
    *p2 = (*p1) ^ (*p2);
    *p1 = (*p1) ^ (*p2);
}

//行翻转
void RowReverse()
{
    int row = 0, l = 0, r = 0, tmp = 0;
    scanf("%d%d%d", &row, &l, &r);
    while (l < r)
    {
        tmp = A[row - 1][l - 1];
        A[row - 1][l - 1] =A[row - 1][r - 1];
        A[row - 1][r - 1] = tmp;
        l++;
        r--;
    }
}
//列翻转
void ColReverse()
{
    int col = 0, tmp = 0, l = 0, r = 0;
    scanf("%d%d%d", &col, &l, &r);
    while (l < r)
    {
        tmp = A[l - 1][col - 1];
       A[l - 1][col - 1] = A[r - 1][col - 1];
        A[r - 1][col - 1] = tmp;
        l++;
        r--;
    }
}
//排序交换
void QsortSwap()
{
    int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, num1 = 0, num2 = 0, num3 = 0;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if ((A[x3 - 1][y3 - 1]) < (A[x1 - 1][y1 - 1]))
        swap(&A[x3 - 1][y3 - 1], &A[x1 - 1][y1 - 1]);
    if ((A[x3 - 1][y3 - 1]) < (A[x2 - 1][y2 - 1]))
        swap(&A[x3 - 1][y3 - 1], &A[x2 - 1][y2 - 1]);
    if ((A[x2 - 1][y2 - 1]) < (A[x1 - 1][y1 - 1]))
        swap(&A[x2 - 1][y2 - 1], &A[x1 - 1][y1 - 1]);
}
int main()
{
    int row = 0, col = 0, q = 0, i = 0, j = 0, fun;
    void (*Tran[4])() = { NULL,RowReverse,ColReverse,QsortSwap };
    scanf("%d%d%d", &row, &col, &q);
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    while (q--)
    {
        scanf("%d", &fun);
        (Tran[fun])();
    }
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            printf("%d ", A[i][j]);
        }
        if (i < row - 1)
            printf("\n");
    }
    return 0;
}

