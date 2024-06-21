#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
class Piont {
public:
	//友元声明
	friend double distance(Piont& e1, Piont& e2);
	//构造函数
	Piont(double x=0, double y=0) :_x(x), _y(y){}
private:
	double _x;
	double _y;
};
double distance(Piont&e1, Piont&e2) {
	return sqrt((e1._x - e2._x) * (e1._x - e2._x) + (e1._y - e2._y) * (e1._y - e2._y));
}
class Complex {
public:
	//友元声明
	friend ostream& operator<<(ostream& out, Complex c);
	friend Complex operator-(Complex& c);
	//构造函数
	Complex(double real=0,double imaginary=0):_real(real),_imaginary(imaginary){}
	//重载加号+运算符
	Complex operator+(Complex c) {
		Complex Ret;
		Ret._real = _real + c._real;
		Ret._imaginary = _imaginary + c._imaginary;
		return Ret;
	}
	//重载加号-运算符
	Complex operator-(Complex c) {
		Complex Ret;
		Ret._real = _real - c._real;
		Ret._imaginary = _imaginary - c._imaginary;
		return Ret;
	}

private:
	double _real;
	double _imaginary;
};
//复数的输出重载
ostream& operator<<(ostream& out,Complex c) {
	out << c._real << ' ' << c._imaginary<<'i';
	return  out;
}
//复数的负运算
Complex operator-(Complex& c) {
	c._real = -c._real;
	c._imaginary = -c._imaginary;
	return c;
}

//前置声明
template<class T>
class stack;
//节点
template<class T>
class Node {
public:
	Node(T data = T()) :_data(data), _next(nullptr) {}
	friend class stack<T>;
private:
	T _data;
	Node<T>* _next;
};

template<class T>
class stack {
public:
	//构造函数
	stack() {
		_head = new Node<T>;
		_tail = _head;
		_sz = 0;
	}
	//压栈
	void push(T data) {
		Node<T>* node = new Node<T>(data);
		_tail->_next = node;
		_tail = _tail->_next;
		_sz++;
	}
	//出栈
	void pop() {
		if (_sz == 0)return;
		else {
			_sz--;
			Node<T>* cur = _head;
			while (cur->_next != _tail)cur = cur->_next;
			delete _tail;
			_tail = cur;
			_tail->_next = nullptr;
		}
	}
	//栈顶
	T top() {
		if (_sz == 0)return T();
		else {
			return _tail->_data;
		}
	}
	//析构函数
	~stack() {
		Node<T>* cur = _head;
		Node<T>* next = cur->_next;
		while (cur) {
			next = cur->_next;
			delete cur;
			cur = next;
		}
	}
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _sz;
};
void test1() {
	Piont p1(2, 3);
	Piont p2(5, 7);
	cout << distance(p1, p2);
}
//Complex的输出测试
void test2() {
	Complex c(1, 2);
	cout << c << endl;
}
//Complex的相加测试
void test3() {
	Complex c1(1, 2),c2(2,4);
	cout << "复数：" << c1 << " 复数：" << c2 << "相加" << endl;;
	cout << "结果为：" << c1 + c2 << endl;
}
//Complex的相减测试
void test4() {
	Complex c1(1, 8), c2(7, 4);
	cout << "复数：" << c1 << " 复数：" << c2 << "相减" << endl;;
	cout << "结果为：" << c1 - c2 << endl;
}
//Complex的负运算测试
void test5() {
	Complex c1(1, 8);
	cout << "复数：" << c1 << "的负号运算" << endl;
	cout << "结果为：" << -c1 << endl;
}
//栈的测试
void test6() {
	stack<int> st;
	st.push(1);
	cout << st.top()<<endl;
	st.pop();
	st.pop();
	st.push(1);
	cout << st.top()<<endl;
	st.push(2);
	cout << st.top()<<endl;
	st.push(3);
	cout << st.top()<<endl;
	st.pop();
	cout << st.top() << endl;
}
int main() {
	/*test3();
	test4();
	test5();*/
	test6();
	return 0;
}