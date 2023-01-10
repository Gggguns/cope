#include<stdio.h>
int main()
{
	int g;
	scanf("%d",&g);
	if(90<=g)
		printf("成绩等级为A");
	else if(80<=g&&g<90)
		printf("成绩等级为B");
	else if(70<=g&&g<80)
		printf("成绩等级为C");
	else if(60<=g&&g<70)
		printf("成绩等级为D");
	else if(0<=g&&g<70)
		printf("成绩等级为E");
	else
		printf("输入时输错了");
	return 0;
}