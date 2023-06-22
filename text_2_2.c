#define _CRT_SECURE_NO_WARNINGS
#include"LQueue.h"
#include"SQStack.h"
int main()
{
	Queue QU;
	QueueInit(&QU);
	char ch;
	SQSTDataType x;
	do
	{
		scanf("%c", &x);
		QueuePush(&QU, x);
		ch = getchar();
	} while (ch == ' ');
	Stack ST;
	STInit(&ST);
	while (!QueueEmpty(&QU))
	{
		x = QueueFront(&QU);
		STPush(&ST, x);
		QueuePop(&QU);
	}
	while (!STEmpty(&ST))
	{
		x = STTop(&ST);
		STPop(&ST);
		printf("%c ", x);
	}
	QueueDestroy(&QU);
	STDestroy(&ST);
	return 0;
}