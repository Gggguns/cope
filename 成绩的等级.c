#include<stdio.h>
int main()
{
	int g;
	scanf("%d",&g);
	if(90<=g)
		printf("�ɼ��ȼ�ΪA");
	else if(80<=g&&g<90)
		printf("�ɼ��ȼ�ΪB");
	else if(70<=g&&g<80)
		printf("�ɼ��ȼ�ΪC");
	else if(60<=g&&g<70)
		printf("�ɼ��ȼ�ΪD");
	else if(0<=g&&g<70)
		printf("�ɼ��ȼ�ΪE");
	else
		printf("����ʱ�����");
	return 0;
}