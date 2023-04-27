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

//����������
BTNode* BinaryTreeCreate(char* str,int*pi);

//���ٶ�����
void BinaryTreeDestroy(BTNode* root);

//ǰ�����
void BinaryTreePrevOrder(BTNode* root);

//�������
void BinaryTreeInOrder(BTNode* root);

//�������
void BinaryTreePostOrder(BTNode* root);

//�������Ľڵ��ܸ���
int BinaryTreeCountNode(BTNode* root);

//���������Һ��ӽ���
void BinaryTreeSwapLeftRight(BTNode* root);
