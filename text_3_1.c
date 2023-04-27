#define _CRT_SECURE_NO_WARNINGS
#include"test_3_1.h"
int main()
{
	char arr[] = "ABC#EF####G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr,&i);
	printf("前序遍历：\n");
	BinaryTreePrevOrder(root);
	printf("\n中序遍历：\n");
	BinaryTreeInOrder(root);
	printf("\n后序遍历：\n");
	BinaryTreePostOrder(root);
	printf("\n二叉树的节点总个数:%d\n",BinaryTreeCountNode(root));
	BinaryTreeSwapLeftRight(root);
	printf("前序遍历：\n");

	printf("交换后：\n");
	BinaryTreePrevOrder(root);
	printf("\n中序遍历：\n");
	BinaryTreeInOrder(root);
	printf("\n后序遍历：\n");
	BinaryTreePostOrder(root);
	printf("\n二叉树的节点总个数:%d\n", BinaryTreeCountNode(root));
	BinaryTreeDestroy(root);
	return 0;
}