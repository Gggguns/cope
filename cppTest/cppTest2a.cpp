#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Rectangle{
public:
	//�вι���
	Rectangle(double lenth,double width):_lenth(lenth),_width(width){
		_count++;
		cout<<"�������Ĺ��캯��������"<<endl;
	}
	//�޲ι���
	Rectangle(){
		_count++;
		cout<<"�޲������캯��������\n";
	}
	//��������
	Rectangle(Rectangle&r):_lenth(r._lenth),_width(r._width){
		_count++;
		cout<<"�������캯��������\n";
	}
	//����
	~Rectangle(){
		cout<<"��������������\n";
		_count--;
	}
	
	//���㳤�����ܳ�
	double CalGirth(){
		return (_lenth+_width)*2;
	}
	//���㳤���α����
	double CalArea(){
		return _lenth*_width;
	}
	//�鿴�������
	static int GetRectangleCount(){
		return _count;
	}
	//���ó�
	void setLenth(double lenth) {
		_lenth = lenth;
	}
	//���ÿ�
	void setWidth(double Width) {
		_width = Width;
	}
	//����
	void test1(){
		cout<<"���������볤���εĳ����Կո�Ϊ���������"<<endl;
		cin>>_lenth>>_width;
		//cout<<_lenth<<_width<<_hight<<endl;
		cout<<"�����ε��ܳ�:"<<CalGirth()<<endl;
		cout<<"�����ε����:"<<CalArea()<<endl;
		Rectangle*Pr=this;
		cout<<"�����ε��ܳ�:"<<Pr->CalGirth()<<endl;
		cout<<"�����ε����:"<<Pr->CalArea()<<endl;
		//GetRectangleCount();

	}
	void test2() {
		cout << "���������볤���εĳ����Կո�Ϊ���������" << endl;
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
		printf("��%d�������εĳ��Ϳ�����Ϊ��%lf %lf\n", i, lenth, width);
		arr[i].setLenth(lenth);
		arr[i].setWidth(width);
		cout << "�����ܳ�Ϊ��" << arr[i].CalGirth() << endl;
	}
	cout << "�����εĸ����У�" << Rectangle::GetRectangleCount() << endl;
}
void main(){
	test1();
}