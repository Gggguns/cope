#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char BinaryTreeData;

typedef struct BinaryTreeNode
{
	BinaryTreeData data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//ǰ���������������
BTNode* PrevOrderCreateBinaryTree(BinaryTreeData* arr, int* pi);

//ͳ��Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafNodeCount(BTNode* root);

//ǰ�����
void PreOrderBinaryTree(BTNode* root);