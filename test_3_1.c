#define _CRT_SECURE_NO_WARNINGS
#include"test_3_1.h"
//创建二叉树
BTNode* BinaryTreeCreate(char* str,int*pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root)
	{
		root->val = str[(*pi)++];
		root->left = BinaryTreeCreate(str,pi);
		root->right = BinaryTreeCreate(str,pi);
		return root;
	}
	else
	{
		perror("malloc fail\n");
		return NULL;
	}
}

//销毁二叉树
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("#");
		return;
	}
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);

}

//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreePostOrder(root->right);
}

//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->val);
}

//二叉树的节点总个数
int BinaryTreeCountNode(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeCountNode(root->left) + BinaryTreeCountNode(root->right) + 1;
}

//二叉树左右孩子交换
void BinaryTreeSwapLeftRight(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeSwapLeftRight(root->left);
	BinaryTreeSwapLeftRight(root->right);
	BTNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

