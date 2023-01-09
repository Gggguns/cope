#include<stdio.h>
int main()
{
	int n,num,odd=0,even=0,i;
	scanf("%d",&n);
	if(0<n&&n<=1000)
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num%2==0)
			even++;
		else
			odd++;
	}
	printf("%d %d",odd,even);

	return 0;
}