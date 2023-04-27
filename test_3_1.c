#define _CRT_SECURE_NO_WARNINGS
#include"test_3_1.h"
//����������
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

//���ٶ�����
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//ǰ�����
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

//�������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreePostOrder(root->right);
}

//�������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->val);
}

//�������Ľڵ��ܸ���
int BinaryTreeCountNode(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeCountNode(root->left) + BinaryTreeCountNode(root->right) + 1;
}

//���������Һ��ӽ���
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

