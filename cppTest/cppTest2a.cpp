#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Rectangle{
public:
	//有参构造
	Rectangle(double lenth,double width):_lenth(lenth),_width(width){
		_count++;
		cout<<"带参数的构造函数被调用"<<endl;
	}
	//无参构造
	Rectangle(){
		_count++;
		cout<<"无参数构造函数被调用\n";
	}
	//拷贝构造
	Rectangle(Rectangle&r):_lenth(r._lenth),_width(r._width){
		_count++;
		cout<<"拷贝构造函数被调用\n";
	}
	//析构
	~Rectangle(){
		cout<<"析构函数被调用\n";
		_count--;
	}
	
	//计算长方形周长
	double CalGirth(){
		return (_lenth+_width)*2;
	}
	//计算长方形表面积
	double CalArea(){
		return _lenth*_width;
	}
	//查看对象个数
	static int GetRectangleCount(){
		return _count;
	}
	//设置长
	void setLenth(double lenth) {
		_lenth = lenth;
	}
	//设置宽
	void setWidth(double Width) {
		_width = Width;
	}
	//测试
	void test1(){
		cout<<"请依次输入长方形的长宽（以空格为间隔符）："<<endl;
		cin>>_lenth>>_width;
		//cout<<_lenth<<_width<<_hight<<endl;
		cout<<"长方形的周长:"<<CalGirth()<<endl;
		cout<<"长方形的面积:"<<CalArea()<<endl;
		Rectangle*Pr=this;
		cout<<"长方形的周长:"<<Pr->CalGirth()<<endl;
		cout<<"长方形的面积:"<<Pr->CalArea()<<endl;
		//GetRectangleCount();

	}
	void test2() {
		cout << "请依次输入长方形的长宽（以空格为间隔符）：" << endl;
		cin >> _lenth >> _width;
	}
private:
	double _lenth;
	double _width;
	static  int _count;
};
int Rectangle::_count=0;

void test1() {
	Rectangle R(2, 3);
	Rectangle cpR(R);
	srand(time(NULL));
	Rectangle arr[3];
	for (int i = 0;i < 3;i++) {
		double lenth = rand() % 100;
		double width = rand() % 100;
		printf("第%d个长方形的长和宽依次为：%lf %lf\n", i, lenth, width);
		arr[i].setLenth(lenth);
		arr[i].setWidth(width);
		cout << "它的周长为：" << arr[i].CalGirth() << endl;
	}
	cout << "长方形的个数有：" << Rectangle::GetRectangleCount() << endl;
}
void main(){
	test1();
}