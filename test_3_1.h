#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//创建二叉树
BTNode* BinaryTreeCreate(char* str,int*pi);

//销毁二叉树
void BinaryTreeDestroy(BTNode* root);

//前序遍历
void BinaryTreePrevOrder(BTNode* root);

//中序遍历
void BinaryTreeInOrder(BTNode* root);

//后序遍历
void BinaryTreePostOrder(BTNode* root);

//二叉树的节点总个数
int BinaryTreeCountNode(BTNode* root);

//二叉树左右孩子交换
void BinaryTreeSwapLeftRight(BTNode* root);
