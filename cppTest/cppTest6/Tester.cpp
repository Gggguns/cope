#include "Complex.h"

int main()
{
	Complex c1(3, -2), c2(-4, 3), c3;
	/*c3 = c1 + c2;
	Complex c4 = c1 - c2;
	c3.show();
	c4.show();
	c4 = c1--; 
	
	c1.show();
	c4.show();*/
	cout<<"��c1��ֵ��c2\nc1:";
	c1.show();
	cout<<"c2:";
	c2.show();
	c2=c1;
	cout<<"��ֵ���c2:";
	c2.show();
	system("pause");
	return 0;
}