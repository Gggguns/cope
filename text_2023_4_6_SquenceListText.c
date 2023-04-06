#include"text_2023_4_6_SquenceList.h"
int main()
{
	SQList SQ;
	Init_SquenceList(&SQ);
	PushBack_SquenceList(&SQ,1);
	PushBack_SquenceList(&SQ,2);
	PushBack_SquenceList(&SQ,3);
	PushBack_SquenceList(&SQ,4);
	PushBack_SquenceList(&SQ,5);
	PushBack_SquenceList(&SQ,6);
	Print_SquenceList(&SQ);
	Destory_SquenceList(&SQ);
	return 0;
}