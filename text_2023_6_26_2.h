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

//前序遍历创建二叉树
BTNode* PrevOrderCreateBinaryTree(BinaryTreeData* arr, int* pi);

//统计叶子节点的个数
int BinaryTreeLeafNodeCount(BTNode* root);

//前序遍历
void PreOrderBinaryTree(BTNode* root);