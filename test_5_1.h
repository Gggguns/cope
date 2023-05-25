#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<stdbool.h>
#define SEQ_SEARCH 0
#define BINARY_SEARCH 1
#define BST_SEARCH 2
#define BALANCE_SEARCH 3

int ASL[4] ;


void Text();

//˳�����
int SequenceSearch(int* pa,int lenth,int key);

//���ֲ���
int BinarySearch(int* pa, int lenth, int key);

//������������

typedef struct BinaryTreeNode
{
	int key;
	struct BinaryTreeNode* left;
	struct BinryTreeNode* right;
	int bf;
}BTNode;

int SearchBST1(BTNode* pRoot, int key, BTNode** pKeyNode, BTNode** pParentNode);

int SearchBST2(BTNode* pRoot, int key);

//ƽ�������
int SearchBalanceBST(BTNode* pRoot, int key);

//�����������������㷨
int InsertBST(BTNode** pRoot, int key);

void RightRotate(BTNode** pNode);

void LeftRo

