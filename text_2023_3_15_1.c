#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char buf[BUFSIZ], * p, * str = "_xy_";
	char* ptr = NULL;
	while (scanf("%s", buf) != EOF)
	{
		ptr = strstr(buf, "_xy_");ptr != NULL;
		if (ptr)
		{
			strncpy(ptr, "_ab_", 4);
		}
		printf("%s\n", buf);
	}
	return 0;
}