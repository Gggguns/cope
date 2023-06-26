#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_26_2.h"

//ǰ���������������
BTNode* PrevOrderCreateBinaryTree(BinaryTreeData* arr, int* pi)
{
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("Create malloc fail");
		return NULL;
	}
	root->data = arr[(*pi)++];
	root->left = PrevOrderCreateBinaryTree(arr, pi);
	root->right = PrevOrderCreateBinaryTree(arr, pi);
	return root;
}


//ͳ��Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = BinaryTreeLeafNodeCount(root->left);
	int right = BinaryTreeLeafNodeCount(root->right);
	if (right == 0 && left == 0)
		return 1;
	return left + right;
}


//ǰ�����
void PreOrderBinaryTree(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}
	printf("%c", root->data);
	PreOrderBinaryTree(root->left);
	PreOrderBinaryTree(root->right);
}