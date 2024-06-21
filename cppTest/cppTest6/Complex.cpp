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

//�ó�Ա�������ؼӷ������
Complex Complex::operator +(Complex c)
{
	Complex result;
	result.real = real + c.real;
	result.image = image + c.image;
	return result;
}

//����Ԫ�������ؼ��������
Complex operator - (Complex c1, Complex c2)
{
	Complex result;
	result.real = c1.real - c2.real;
	result.image = c1.image - c2.image;
	return result;
}

//�ó�Ա�������ص�Ŀ�����-(ȡ����
Complex Complex::operator - ()
{
    Complex result;
    result.real = -real;
    result.image = -image;
    return result;
}

//�ó�Ա�������ص�Ŀ�����++��ǰ׺��ʽ���ȱ仯�󷵻أ�
//����ò�����Ч���ǽ�ʵ�����鲿����1
Complex Complex::operator ++ ()
{
	real ++;    //�ȱ仯��
	image ++;

	Complex result;   //�󷵻�
	result.real = real;
	result.image = image;
	return result;
}

//�ó�Ա�������ص�Ŀ�����++����׺��ʽ���ȷ��غ�仯��
//����ò�����Ч���ǽ�ʵ�����鲿����1	
Complex Complex::operator ++ (int)
{
	Complex result(real, image);   //����ԭֵ
	real ++;   //��1
	image ++;
	return result;
}

//����Ԫ���ص�Ŀ�����--��ǰ׺��ʽ���ȱ仯�󷵻أ�
Complex operator -- (Complex& c)  //c��Ҫ�ı䣬�����Ҫ��������ʽ��
{
	c.real --;
	c.image --;
	return c;
}

//����Ԫ���ص�Ŀ�����--����׺��ʽ���ȷ��غ�仯��
Complex operator -- (Complex& c, int)  //c��Ҫ�ı䣬�����Ҫ��������ʽ��
{
	Complex result = c;
	c.real --;
	c.image --;
	return result;
}

////�������
//Complex Complex::operator*(Complex c){
//	Complex Res;
//	Res.image=real*c.image+c.real*image;
//	Res.real=real*c.real+c.image*image;
//	return Res;
//}
//��Ԫ����*
Complex operator*(Complex c1,Complex c2){
	Complex Res;
	Res.image=c1.image*c2.real+c1.real*c2.image;
	Res.real=c1.real*c2.real+c1.image*c2.image;
	return Res;
}

//��ֵ
Complex& Complex::operator=(Complex& c){
	real=c.real;
	image=c.image;
	return *this;
}