#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_4_22.h"

int main()
{
	SListNode* head1=NULL, * head2=NULL;
	SLTDateType x;
	char ch;
	//��һ���ǽ������е�����
	do
	{
		scanf("%d", &x);
		SListPushBack(&head1, x);
		ch = getchar();
	} while (ch == ' ');
	//�ڶ����ǽ������е�����
	do
	{
		scanf("%d", &x);
		SListPushBack(&head2, x);
		ch = getchar();
	} while (ch == ' ');

	SListNode* head3 = Combine(head1, head2);
	SListPrint(head3);
	SListDestroy(&head3);
	head1 = NULL;
	head2 = NULL;
	return 0;
}