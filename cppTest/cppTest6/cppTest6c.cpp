#include<iostream>
#include<string>
using namespace std;
class People{
public:
	//有参构造
	People(string name=""):_name(name){}
	//纯虚函数
	virtual void cal_salary()=0;
	virtual void print()=0;
protected:
	string _name;
};
class Manage:public People{
public:
	Manage(string name,int salary):People(name),_salary(salary){}
	void cal_salary(){
		cout<<"我每月的工资固定是"<<_salary<<endl;
	}
	void print(){
		cout<<"我叫"<<_name<<",是一名经理\n";
	}
protected:
	int _salary;
};

class HourWorker:public People{
public:
	HourWorker(string name,int hour,int wage):People(name),_hour(hour),_wage(wage){}
	void cal_salary(){
		cout<<"我工作了"<<_hour<<"小时，时薪为"<<_wage<<"元,所得工资为"<<_hour*_wage<<"元\n";
	}
	void print(){
		cout<<"我叫"<<_name<<",是一名小时工\n";
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