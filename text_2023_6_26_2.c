#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_6_26_2.h"
int main()
{
	int i = 0;
	char arr[] = "abc##de#g##f##e#k##";
	BTNode*root=PrevOrderCreateBinaryTree(arr, &i);
	PreOrderBinaryTree(root);
	printf("\n叶子节点个数为%d", BinaryTreeLeafNodeCount(root));
	return 0;
}
