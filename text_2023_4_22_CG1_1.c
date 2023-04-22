#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_4_22_CG1_1.h"
int main()
{
	SListNode* head = NULL;
	SLTDateType x;
	char ch;
	do
	{
		scanf("%d,%d", &x.num, &x.score);
		SListPushBack(&head, x);
		ch = getchar();
	} while (ch == ' ');
	SListPrint(head);
	SListDestroy(&head);
	return 0;
}