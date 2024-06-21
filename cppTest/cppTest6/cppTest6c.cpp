#include<iostream>
#include<string>
using namespace std;
class People{
public:
	//�вι���
	People(string name=""):_name(name){}
	//���麯��
	virtual void cal_salary()=0;
	virtual void print()=0;
protected:
	string _name;
};
class Manage:public People{
public:
	Manage(string name,int salary):People(name),_salary(salary){}
	void cal_salary(){
		cout<<"��ÿ�µĹ��ʹ̶���"<<_salary<<endl;
	}
	void print(){
		cout<<"�ҽ�"<<_name<<",��һ������\n";
	}
protected:
	int _salary;
};

class HourWorker:public People{
public:
	HourWorker(string name,int hour,int wage):People(name),_hour(hour),_wage(wage){}
	void cal_salary(){
		cout<<"�ҹ�����"<<_hour<<"Сʱ��ʱнΪ"<<_wage<<"Ԫ,���ù���Ϊ"<<_hour*_wage<<"Ԫ\n";
	}
	void print(){
		cout<<"�ҽ�"<<_name<<",��һ��Сʱ��\n";
	}
protected:
	int _hour;
	int _wage;
};
int main(){
	People *arr[3];
	Manage M("LiDan",5000);
	HourWorker H1("Kuku",80,100);
	HourWorker H2("Xaoxi",100,66);
	arr[0]=&M;arr[1]=&H1;arr[2]=&H2;
	for(int i=0;i<3;i++){
		arr[i]->print();
		cout<<' ';
		arr[i]->cal_salary();
		cout<<endl;
	}
	system("pause");
	return 0;
}