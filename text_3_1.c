#define _CRT_SECURE_NO_WARNINGS
#include"test_3_1.h"
int main()
{
	char arr[] = "ABC#EF####G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr,&i);
	printf("ǰ�������\n");
	BinaryTreePrevOrder(root);
	printf("\n���������\n");
	BinaryTreeInOrder(root);
	printf("\n���������\n");
	BinaryTreePostOrder(root);
	printf("\n�������Ľڵ��ܸ���:%d\n",BinaryTreeCountNode(root));
	BinaryTreeSwapLeftRight(root);
	printf("ǰ�������\n");

	printf("������\n");
	BinaryTreePrevOrder(root);
	printf("\n���������\n");
	BinaryTreeInOrder(root);
	printf("\n���������\n");
	BinaryTreePostOrder(root);
	printf("\n�������Ľڵ��ܸ���:%d\n", BinaryTreeCountNode(root));
	BinaryTreeDestroy(root);
	return 0;
}