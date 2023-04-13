#define _CRT_SECURE_NO_WARNINGS
#include"SQStack.h"
int main()
{
	Stack ST;
	STInit(&ST);
	/*STPush(&ST, 1);
	STPush(&ST, 2);
	STPush(&ST, 3);
	STPush(&ST, 4);
	STPush(&ST, 5);
	STPush(&ST, 6);
	STPush(&ST, 7);
	STPush(&ST, 8);*/
	SQSTDataType x;
	while (scanf("%d", &x)!= EOF)
	{
		STPush(&ST, x);
	}
	if (STFull(&ST))
		printf("Õ»Âú\n");
	//printf("%d\n",STLength(&ST));
	while (!STEmpty(&ST))
	{
		x = STTop(&ST);
		STPop(&ST);
		printf("%d ",x);
	}
	STDestroy(&ST);
	return 0;
}