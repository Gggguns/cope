#define _CRT_SECURE_NO_WARNINGS
#include"SQStack.h"
int main()
{
	Stack ST;
	STInit(&ST);
	int falt = 1;
	SQSTDataType x;
	SQSTDataType top;
	do
	{
		x = getchar();
		if (x == '(' || x == '{' || x == '[')
			STPush(&ST, x);
		if (x == ')' || x == '}' || x == ']')
		{
			top = STTop(&ST);
			STPop(&ST);
			if (top != '(' && x == ')')
			{
				falt = 0;
				printf("¿®∫≈≤ª∆•≈‰\n");
				break;
			}
			else if (top != '{' && x == '}')
			{
				printf("¿®∫≈≤ª∆•≈‰\n");
				break;
			}
			else if (top != '[' && x == ']')
			{
				printf("¿®∫≈≤ª∆•≈‰\n");
				break;
			}
		}
	} while (x != '\n');
	return 0;
}