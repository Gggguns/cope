#include<iostream>
#include<string>
using namespace std;

class Rectangle   //������
{
protected:
	int length;   //���εĳ�
protected:
	int width;    //���εĿ�
public:
	Rectangle(int l = 10, int w = 10):length(l), width(w)
	{
	}
	virtual int calArea()
	{
		return length * width;
	}
};

class Cuboid : public Rectangle  //�������࣬��Rectangle��������
{
private:
	int height;    //������ĸ�
public:
	Cuboid(int l = 10, int w = 10, int h = 10){
		length = l;
		width = w;
		height = h;
	}

	//���㳤����ı����
	int calArea(){
		return 2*(length*height+length*width+width*height);
	}
	int calVolume()
	{
		return calArea() * height;
	}
};

//����
class vehicle{
public:
	//���ι���
	vehicle(int MaxSpeed,int Weight):_MaxSpeed(MaxSpeed),_Weight(Weight){
		cout<<"���๹�캯��������\n";
	}
	void Run(){
		cout<<"��ʻ��\n";
	}
	void Stop(){
		cout<<"ͣ��\n";
	}
	//��������
	~vehicle(){
		cout<<"������������������"<<endl;
	}
protected:
	int _MaxSpeed;
	int _Weight;
};
//����
class motorcar : public vehicle{
public:
	//���ι���
	motorcar(int MaxSpeed,int Weight,int SeatNum):vehicle(MaxSpeed,Weight),_SeatNum(SeatNum){
		cout<<"������ι��캯��������\n";
	}
	//��������
	~motorcar(){
		cout<<"������������������"<<endl;
	}
protected:
	int _SeatNum;
};
//��
class Person{
public:
	Person(string name,string sex):_name(name),_sex(sex){}
protected:
	string _name;
	string _sex;
};
//��ʦ
class Teacher:virtual public Person{
public:
	Teacher(string name,string sex,string course):Person(name,sex),_course(course){}
protected:
	string _course;
};
//ѧ��
class Student:virtual public Person{
public:
	Student(string name,string sex,string sno):Person(name,sex),_sno(sno){}
protected:
	string _sno;
};
//Master
class Master:public Teacher,public Student{
public:
	Master(string name,string sex,string course,string sno,string honor):Person(name,sex),Teacher(name,sex,course),Student(name,sex,sno),_honor(honor){}
	void Print(){
		cout<<"������"<<_name<<endl;
		cout<<"�Ա�:"<<_sex<<endl;
		cout<<"���ڿγ�:"<<_course<<endl;
		cout<<"ѧ��:"<<_sno<<endl;
		cout<<"����������"<<_honor<<endl;
	}
protected:
	string _honor;
};
void test1(){
	motorcar M(120,600,4);
}
void test2(){
	Master ma("hihi","��","����","32220302","������㽲ʦ");
	ma.Print();
}
void main(void)
{
	/*Cuboid test(10, 20, 30);
	cout<<"������ĳ��������Ϊ��10��20��30"<<endl;
	cout<<"������ı����Ϊ��"<<test.calArea()<<endl;
	cout << test.calVolume() << endl;*/
	
	//cout<<"\n";
	test2();
	system("pause");
}