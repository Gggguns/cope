#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
class Piont {
public:
	//��Ԫ����
	friend double distance(Piont& e1, Piont& e2);
	//���캯��
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
	//��Ԫ����
	friend ostream& operator<<(ostream& out, Complex c);
	friend Complex operator-(Complex& c);
	//���캯��
	Complex(double real=0,double imaginary=0):_real(real),_imaginary(imaginary){}
	//���ؼӺ�+�����
	Complex operator+(Complex c) {
		Complex Ret;
		Ret._real = _real + c._real;
		Ret._imaginary = _imaginary + c._imaginary;
		return Ret;
	}
	//���ؼӺ�-�����
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
//�������������
ostream& operator<<(ostream& out,Complex c) {
	out << c._real << ' ' << c._imaginary<<'i';
	return  out;
}
//�����ĸ�����
Complex operator-(Complex& c) {
	c._real = -c._real;
	c._imaginary = -c._imaginary;
	return c;
}

//ǰ������
template<class T>
class stack;
//�ڵ�
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
	//���캯��
	stack() {
		_head = new Node<T>;
		_tail = _head;
		_sz = 0;
	}
	//ѹջ
	void push(T data) {
		Node<T>* node = new Node<T>(data);
		_tail->_next = node;
		_tail = _tail->_next;
		_sz++;
	}
	//��ջ
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
	//ջ��
	T top() {
		if (_sz == 0)return T();
		else {
			return _tail->_data;
		}
	}
	//��������
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
//Complex���������
void test2() {
	Complex c(1, 2);
	cout << c << endl;
}
//Complex����Ӳ���
void test3() {
	Complex c1(1, 2),c2(2,4);
	cout << "������" << c1 << " ������" << c2 << "���" << endl;;
	cout << "���Ϊ��" << c1 + c2 << endl;
}
//Complex���������
void test4() {
	Complex c1(1, 8), c2(7, 4);
	cout << "������" << c1 << " ������" << c2 << "���" << endl;;
	cout << "���Ϊ��" << c1 - c2 << endl;
}
//Complex�ĸ��������
void test5() {
	Complex c1(1, 8);
	cout << "������" << c1 << "�ĸ�������" << endl;
	cout << "���Ϊ��" << -c1 << endl;
}
//ջ�Ĳ���
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