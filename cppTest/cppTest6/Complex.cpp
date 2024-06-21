// Complex.cpp: implementation of the Complex class.
//
//////////////////////////////////////////////////////////////////////

#include "Complex.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Complex::Complex(double r, double i)
{
	real = r;
	image = i;
}

Complex::~Complex()
{

}

void Complex::show()
{
	cout << "(" << real << ", " << image << ")" << endl;
}

//用成员函数重载加法运算符
Complex Complex::operator +(Complex c)
{
	Complex result;
	result.real = real + c.real;
	result.image = image + c.image;
	return result;
}

//用友元函数重载减法运算符
Complex operator - (Complex c1, Complex c2)
{
	Complex result;
	result.real = c1.real - c2.real;
	result.image = c1.image - c2.image;
	return result;
}

//用成员函数重载单目运算符-(取反）
Complex Complex::operator - ()
{
    Complex result;
    result.real = -real;
    result.image = -image;
    return result;
}

//用成员函数重载单目运算符++，前缀形式（先变化后返回）
//假设该操作的效果是将实部与虚部各加1
Complex Complex::operator ++ ()
{
	real ++;    //先变化　
	image ++;

	Complex result;   //后返回
	result.real = real;
	result.image = image;
	return result;
}

//用成员函数重载单目运算符++，后缀形式（先返回后变化）
//假设该操作的效果是将实部与虚部各加1	
Complex Complex::operator ++ (int)
{
	Complex result(real, image);   //保留原值
	real ++;   //加1
	image ++;
	return result;
}

//用友元重载单目运算符--，前缀形式（先变化后返回）
Complex operator -- (Complex& c)  //c需要改变，因而需要用引用形式！
{
	c.real --;
	c.image --;
	return c;
}

//用友元重载单目运算符--，后缀形式（先返回后变化）
Complex operator -- (Complex& c, int)  //c需要改变，因而需要用引用形式！
{
	Complex result = c;
	c.real --;
	c.image --;
	return result;
}

////复数相乘
//Complex Complex::operator*(Complex c){
//	Complex Res;
//	Res.image=real*c.image+c.real*image;
//	Res.real=real*c.real+c.image*image;
//	return Res;
//}
//友元重载*
Complex operator*(Complex c1,Complex c2){
	Complex Res;
	Res.image=c1.image*c2.real+c1.real*c2.image;
	Res.real=c1.real*c2.real+c1.image*c2.image;
	return Res;
}

//赋值
Complex& Complex::operator=(Complex& c){
	real=c.real;
	image=c.image;
	return *this;
}