// Complex.h: interface for the Complex class.
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
#if !defined(AFX_COMPLEX_H__B806A409_5547_4464_987B_99238E6DA4DC__INCLUDED_)
#define AFX_COMPLEX_H__B806A409_5547_4464_987B_99238E6DA4DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Complex  
{
public:
	Complex operator + (Complex c);
	friend Complex operator - (Complex c1, Complex c2);
	Complex operator - ();
	Complex operator ++ ();
	Complex operator ++ (int);
	friend Complex operator*(Complex c1,Complex c2);

	friend Complex operator -- (Complex& c);
	friend Complex operator -- (Complex& c, int);

	void show();
	Complex(double r = 0, double i = 0);
	//¸´ÊýÏà³Ë
	//Complex operator*(Complex c);
	//¸³Öµ
	Complex& operator=(Complex& c);
	virtual ~Complex();

private:
	double image;
	double real;
};

#endif // !defined(AFX_COMPLEX_H__B806A409_5547_4464_987B_99238E6DA4DC__INCLUDED_)
