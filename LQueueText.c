#include"LQueue.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Queue QU;
	QueueInit(&QU);
	//QueuePush(&QU, 1);
	/*QueuePush(&QU, 2);
	QueuePush(&QU, 3);
	QueuePush(&QU, 4);
	QueuePush(&QU, 5);
	QueuePush(&QU, 6);
	QueuePush(&QU, 7);
	QueuePush(&QU, 8);
	QueuePush(&QU, 3);
	QueuePush(&QU, 4);
	QueuePush(&QU, 5);
	QueuePush(&QU, 6);
	QueuePush(&QU, 7);
	QueuePush(&QU, 8);*/
	printf("���еĳ���Ϊ%d\n", QueueSize(&QU));
	printf("���е�βԪ��%d\n", QueueBack(&QU));
	/*while (!QueueEmpty(&QU))
	{
		QueueDataType x = QueueFront(&QU);
		QueuePop(&QU);
		printf("%d ", x);
	}*/
	//QueuePop(&QU);
	QueueDestroy(&QU);
	return 0;
}